-- World Objects Persistence Table
-- Stores persistent world objects (containers, debris) dropped in space

CREATE TABLE IF NOT EXISTS world_objects (
    "Id" UUID PRIMARY KEY,
    "TemplateId" INTEGER NOT NULL,
    "SystemId" UUID NOT NULL,
    "PosX" DOUBLE PRECISION NOT NULL,
    "PosY" DOUBLE PRECISION NOT NULL,
    "PosZ" DOUBLE PRECISION NOT NULL,
    "RotW" REAL NOT NULL DEFAULT 1.0,
    "RotX" REAL NOT NULL DEFAULT 0.0,
    "RotY" REAL NOT NULL DEFAULT 0.0,
    "RotZ" REAL NOT NULL DEFAULT 0.0,
    "InventoryJson" JSONB NOT NULL DEFAULT '{}'::jsonb,
    "ExpirationTime" TIMESTAMP WITH TIME ZONE,
    "CreatedAt" TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT NOW(),
    "LastUpdated" TIMESTAMP WITH TIME ZONE,
    
    -- Foreign key to solar_systems table
    CONSTRAINT "FK_world_objects_solar_systems_SystemId" 
        FOREIGN KEY ("SystemId") 
        REFERENCES solar_systems("system_id") 
        ON DELETE CASCADE
);

-- Create index on SystemId for efficient queries by system
CREATE INDEX IF NOT EXISTS "IX_world_objects_SystemId" 
    ON world_objects ("SystemId");

-- Create index on ExpirationTime for efficient cleanup queries
CREATE INDEX IF NOT EXISTS "IX_world_objects_ExpirationTime" 
    ON world_objects ("ExpirationTime");

-- Comments for documentation
COMMENT ON TABLE world_objects IS 'Stores persistent world objects (containers, debris) dropped in space';
COMMENT ON COLUMN world_objects."Id" IS 'Unique identifier for the world object';
COMMENT ON COLUMN world_objects."TemplateId" IS 'Template ID for the object type (container type, debris type)';
COMMENT ON COLUMN world_objects."SystemId" IS 'Solar system where this object exists';
COMMENT ON COLUMN world_objects."PosX" IS 'X coordinate in 3D space';
COMMENT ON COLUMN world_objects."PosY" IS 'Y coordinate in 3D space';
COMMENT ON COLUMN world_objects."PosZ" IS 'Z coordinate in 3D space';
COMMENT ON COLUMN world_objects."RotW" IS 'Quaternion W component for rotation';
COMMENT ON COLUMN world_objects."RotX" IS 'Quaternion X component for rotation';
COMMENT ON COLUMN world_objects."RotY" IS 'Quaternion Y component for rotation';
COMMENT ON COLUMN world_objects."RotZ" IS 'Quaternion Z component for rotation';
COMMENT ON COLUMN world_objects."InventoryJson" IS 'JSON serialized inventory contents';
COMMENT ON COLUMN world_objects."ExpirationTime" IS 'When this object expires and should be cleaned up (null = never expires)';
COMMENT ON COLUMN world_objects."CreatedAt" IS 'When this object was created';
COMMENT ON COLUMN world_objects."LastUpdated" IS 'Last time this object was updated (e.g., inventory change)';
