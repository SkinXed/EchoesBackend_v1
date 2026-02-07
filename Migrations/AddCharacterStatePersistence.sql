-- Character State Persistence Table
-- Stores player position, rotation, and ship stats for crash recovery

CREATE TABLE IF NOT EXISTS character_states (
    "Id" UUID PRIMARY KEY,
    "CharacterId" UUID NOT NULL,
    "LastSystemId" UUID,
    "PosX" DOUBLE PRECISION NOT NULL,
    "PosY" DOUBLE PRECISION NOT NULL,
    "PosZ" DOUBLE PRECISION NOT NULL,
    "RotW" REAL NOT NULL DEFAULT 1.0,
    "RotX" REAL NOT NULL DEFAULT 0.0,
    "RotY" REAL NOT NULL DEFAULT 0.0,
    "RotZ" REAL NOT NULL DEFAULT 0.0,
    "CurrentShield" REAL NOT NULL DEFAULT 0.0,
    "CurrentArmor" REAL NOT NULL DEFAULT 0.0,
    "CurrentHull" REAL NOT NULL DEFAULT 0.0,
    "CurrentCapacitor" REAL NOT NULL DEFAULT 0.0,
    "LastUpdated" TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT NOW(),
    
    -- Foreign key to characters table
    CONSTRAINT "FK_character_states_characters_CharacterId" 
        FOREIGN KEY ("CharacterId") 
        REFERENCES characters("character_id") 
        ON DELETE CASCADE,
    
    -- Foreign key to solar_systems table (nullable)
    CONSTRAINT "FK_character_states_solar_systems_LastSystemId" 
        FOREIGN KEY ("LastSystemId") 
        REFERENCES solar_systems("system_id") 
        ON DELETE SET NULL
);

-- Create unique index on CharacterId (one state per character)
CREATE UNIQUE INDEX IF NOT EXISTS "IX_character_states_CharacterId" 
    ON character_states ("CharacterId");

-- Create index on LastSystemId for queries
CREATE INDEX IF NOT EXISTS "IX_character_states_LastSystemId" 
    ON character_states ("LastSystemId");

-- Comments for documentation
COMMENT ON TABLE character_states IS 'Stores character state for recovery after logout or server crash';
COMMENT ON COLUMN character_states."CharacterId" IS 'Character this state belongs to';
COMMENT ON COLUMN character_states."LastSystemId" IS 'Last solar system the character was in';
COMMENT ON COLUMN character_states."PosX" IS 'X coordinate in 3D space';
COMMENT ON COLUMN character_states."PosY" IS 'Y coordinate in 3D space';
COMMENT ON COLUMN character_states."PosZ" IS 'Z coordinate in 3D space';
COMMENT ON COLUMN character_states."RotW" IS 'Quaternion W component for rotation';
COMMENT ON COLUMN character_states."RotX" IS 'Quaternion X component for rotation';
COMMENT ON COLUMN character_states."RotY" IS 'Quaternion Y component for rotation';
COMMENT ON COLUMN character_states."RotZ" IS 'Quaternion Z component for rotation';
COMMENT ON COLUMN character_states."CurrentShield" IS 'Current shield hit points';
COMMENT ON COLUMN character_states."CurrentArmor" IS 'Current armor hit points';
COMMENT ON COLUMN character_states."CurrentHull" IS 'Current hull (structure) hit points';
COMMENT ON COLUMN character_states."CurrentCapacitor" IS 'Current capacitor energy';
COMMENT ON COLUMN character_states."LastUpdated" IS 'Timestamp of last state save';
