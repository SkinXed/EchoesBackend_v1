-- Add SequenceNumber field to character_states table
-- Migration: 20260207020300_AddSequenceNumberToCharacterState
-- Purpose: Enable optimistic concurrency control to prevent race conditions

-- Add SequenceNumber column with default value 0
ALTER TABLE character_states 
ADD COLUMN "SequenceNumber" BIGINT NOT NULL DEFAULT 0;

-- Create index for faster sequence number lookups during bulk updates
CREATE INDEX "IX_character_states_SequenceNumber" 
ON character_states ("SequenceNumber");

-- Optional: Set initial sequence numbers based on LastUpdated timestamp
-- This ensures existing records have meaningful sequence numbers
UPDATE character_states 
SET "SequenceNumber" = EXTRACT(EPOCH FROM "LastUpdated") * 10000000
WHERE "SequenceNumber" = 0;

COMMENT ON COLUMN character_states."SequenceNumber" IS 'Sequence number for optimistic concurrency control. Higher values indicate more recent updates.';
