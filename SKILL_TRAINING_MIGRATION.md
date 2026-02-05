# EVE-Style Skill Training System Implementation

## Overview

This implementation adds a complete EVE Online-style skill training system to the EchoesBackend_v1 project, including:

- Faction and SkillGroup entities
- Enhanced character skill training with real-time progress
- Background worker for automatic training completion
- API endpoints for skill management
- Data migration from old `character_skills` to `character_skills_enhanced` table

## Database Changes

### New Tables

1. **factions** - Stores game factions (Arden, Nova, Solaris, Valerion)
   - `faction_id` (PK)
   - `name`
   - `config_json`
   - `description`
   - `created_at`, `updated_at`

2. **skill_groups** - Categorizes skills (Gunnery, Missiles, etc.)
   - `skill_group_id` (PK)
   - `name`
   - `description`
   - `config_json`
   - `created_at`, `updated_at`

### Modified Tables

1. **characters** - Added faction relationship
   - Added `faction_id` (FK to factions, default: 1)

2. **skills** - Replaced enum with foreign key
   - Changed `skill_group` (enum) → `skill_group_id` (FK to skill_groups)

3. **character_skills_enhanced** - Added optimistic concurrency
   - Added `row_version` (timestamp for concurrency control)
   - Added unique constraint on (`character_id`, `skill_id`)
   - Added index on (`is_active`, `training_finished_at`) for training queries

## SkillGroup Enum to Entity Mapping

The old `SkillGroup` enum has been kept for backward compatibility. Here's the mapping to new entity IDs:

| Enum Name            | Enum Value | SkillGroupEntity ID |
|---------------------|------------|-------------------|
| Gunnery             | 0          | 1                 |
| Missiles            | 1          | 2                 |
| Drones              | 2          | 3                 |
| Navigation          | 3          | 4                 |
| Targeting           | 4          | 5                 |
| Engineering         | 10         | 6                 |
| Electronics         | 11         | 7                 |
| Mechanics           | 12         | 8                 |
| Shield              | 13         | 9                 |
| Armor               | 14         | 10                |
| SpaceshipCommand    | 20         | 11                |
| Frigate             | 21         | 12                |
| Cruiser             | 22         | 13                |
| Battleship          | 23         | 14                |
| Industrial          | 24         | 15                |

**Note**: The enum values do NOT match the entity IDs. You'll need to create a mapping helper if you need to convert between them:

```csharp
public static class SkillGroupMapper
{
    private static readonly Dictionary<SkillGroup, int> EnumToEntityId = new()
    {
        { SkillGroup.Gunnery, 1 },
        { SkillGroup.Missiles, 2 },
        { SkillGroup.Drones, 3 },
        { SkillGroup.Navigation, 4 },
        { SkillGroup.Targeting, 5 },
        { SkillGroup.Engineering, 6 },
        { SkillGroup.Electronics, 7 },
        { SkillGroup.Mechanics, 8 },
        { SkillGroup.Shield, 9 },
        { SkillGroup.Armor, 10 },
        { SkillGroup.SpaceshipCommand, 11 },
        { SkillGroup.Frigate, 12 },
        { SkillGroup.Cruiser, 13 },
        { SkillGroup.Battleship, 14 },
        { SkillGroup.Industrial, 15 },
    };
    
    public static int ToEntityId(this SkillGroup skillGroup)
    {
        return EnumToEntityId.TryGetValue(skillGroup, out var id) ? id : 1;
    }
}
```

## Migration Steps

### 1. Apply Database Migration

```bash
# Apply the migration to your database
dotnet ef database update --project Echoes.API.csproj

# Verify tables were created
psql -d your_database -c "SELECT * FROM factions;"
psql -d your_database -c "SELECT * FROM skill_groups;"
psql -d your_database -c "SELECT faction_id FROM characters LIMIT 1;"
psql -d your_database -c "SELECT skill_group_id FROM skills LIMIT 1;"
```

### 2. Update Existing Skills

Before migrating character skills, ensure all existing skills in the `skills` table have valid `skill_group_id` values:

```sql
-- Check for any NULL or invalid skill_group_id values
SELECT skill_id, name, skill_group_id FROM skills WHERE skill_group_id IS NULL OR skill_group_id < 1;

-- If you need to update skills based on old enum values, use appropriate mapping
-- Example: UPDATE skills SET skill_group_id = 1 WHERE old_enum_value = 0;
```

### 3. Run Data Migration

**IMPORTANT**: Take a database backup before running this migration!

```bash
# Option 1: Via API endpoint (create a migration controller)
curl -X POST http://localhost:5116/api/migration/character-skills

# Option 2: Via direct execution (add to Program.cs or create a CLI tool)
```

The migration will:
1. Read all records from `character_skills`
2. Calculate proper `SkillPointsToNextLevel` for each skill
3. Set `TrainedLevel` for skills with active training
4. Create corresponding records in `character_skills_enhanced`
5. Skip any skills that already exist in the enhanced table

### 4. Verify Migration

```sql
-- Compare record counts
SELECT 
    (SELECT COUNT(*) FROM character_skills) as old_count,
    (SELECT COUNT(*) FROM character_skills_enhanced) as new_count;

-- Check a few migrated records
SELECT * FROM character_skills_enhanced LIMIT 10;

-- Check for active training
SELECT 
    cse.character_id, 
    s.name, 
    cse.skill_level, 
    cse.trained_level,
    cse.training_finished_at
FROM character_skills_enhanced cse
JOIN skills s ON cse.skill_id = s.skill_id
WHERE cse.is_active = true;
```

### 5. Testing

After migration:
1. Test starting new skill training
2. Test pausing/canceling training
3. Verify background worker completes training automatically
4. Check that skill progression works correctly

## API Endpoints

### Get Character Skills
```
GET /api/skilltraining/character/{characterId}
```

Returns all skills for a character with current training progress.

### Start Training
```
POST /api/skilltraining/start
Body: {
  "characterId": "guid",
  "skillId": 123,
  "targetLevel": 3
}
```

Starts training a skill to the specified level.

### Pause Training
```
POST /api/skilltraining/pause
Body: {
  "characterId": "guid",
  "skillId": 123
}
```

Pauses training and saves progress (gained SP).

### Cancel Training
```
POST /api/skilltraining/cancel
Body: {
  "characterId": "guid",
  "skillId": 123
}
```

Cancels training without saving progress.

## Background Worker

The `TrainingWorker` runs every minute and automatically completes any training that has finished. It:
1. Queries for skills where `is_active = true` AND `training_finished_at <= NOW()`
2. Calls `CompleteTrainingAsync` for each finished training
3. Advances skill level and updates character skills

## Training Formula (EVE Online)

### Skill Points Required
```
SP = 250 × (2.5^(level-1)) × Rank
```

### Training Time
```
Time (minutes) = SP_required / (Primary_Attribute + Secondary_Attribute/2)
```

## Backward Compatibility

### Old `character_skills` Table
- **NOT DELETED** in this migration
- Kept for rollback safety
- Can be removed after thorough testing in production
- Add a note in your deployment checklist

### Enum `SkillGroup`
- **NOT REMOVED** from codebase
- Kept for backward compatibility with existing code
- New code should use `SkillGroupEntity` relationships
- Consider deprecating enum in future releases

## SQL Snippets for Manual Operations

### Fixing Enum-to-ID Mismatches

If you have skills using the old enum values and need to update them:

```sql
-- Create a mapping table (temporary)
CREATE TEMP TABLE skill_group_mapping (enum_value INT, entity_id INT);

INSERT INTO skill_group_mapping VALUES
  (0, 1),   -- Gunnery
  (1, 2),   -- Missiles
  (2, 3),   -- Drones
  (3, 4),   -- Navigation
  (4, 5),   -- Targeting
  (10, 6),  -- Engineering
  (11, 7),  -- Electronics
  (12, 8),  -- Mechanics
  (13, 9),  -- Shield
  (14, 10), -- Armor
  (20, 11), -- SpaceshipCommand
  (21, 12), -- Frigate
  (22, 13), -- Cruiser
  (23, 14), -- Battleship
  (24, 15); -- Industrial

-- Update skills table (if needed)
-- UPDATE skills s 
-- SET skill_group_id = m.entity_id
-- FROM skill_group_mapping m
-- WHERE s.old_enum_column = m.enum_value;
```

### Rollback Migration (if needed)

```sql
-- Delete migrated records
DELETE FROM character_skills_enhanced;

-- Optionally drop the column from characters
-- ALTER TABLE characters DROP COLUMN faction_id;
```

## TODO / Future Work

1. ✅ Implement basic training system
2. ✅ Add background worker
3. ✅ Create data migration script
4. ⚠️ Test migration with production-like data volume
5. ⚠️ Add training queue support (multiple skills queued)
6. ⚠️ Add skill prerequisites validation
7. ⚠️ Add attribute remapping support
8. ⚠️ Add neural remap mechanics
9. ⚠️ Add unit tests for training service
10. ⚠️ Performance testing for background worker
11. ⚠️ Consider removing old `character_skills` table after 1-2 releases

## Support

For questions or issues with this implementation, please refer to:
- [IMPLEMENTATION_SUMMARY.md](./IMPLEMENTATION_SUMMARY.md) - Overall project documentation
- [ECONOMY_SYSTEM.md](./ECONOMY_SYSTEM.md) - Economic systems documentation
- [ROADMAP.md](./ROADMAP.md) - Project roadmap

## Migration Checklist

Before deploying to production:

- [ ] Database backup taken
- [ ] Migration tested on staging environment
- [ ] All existing skills have valid `skill_group_id` values
- [ ] Data migration script tested with sample data
- [ ] API endpoints tested
- [ ] Background worker tested
- [ ] Rollback plan prepared
- [ ] Monitoring/alerting configured for training worker
- [ ] Documentation updated
- [ ] Team trained on new system
