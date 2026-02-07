-- Migration: Add Player Sessions Table
-- Purpose: Track active player sessions, combat status, and connection state
-- Date: 2026-02-07

-- Create player_sessions table
CREATE TABLE player_sessions (
    session_id UUID PRIMARY KEY,
    character_id UUID NOT NULL,
    current_system_id UUID,
    server_address VARCHAR(100) NOT NULL,
    connected_at TIMESTAMP WITH TIME ZONE NOT NULL,
    last_heartbeat TIMESTAMP WITH TIME ZONE NOT NULL,
    is_active BOOLEAN NOT NULL DEFAULT TRUE,
    combat_until TIMESTAMP WITH TIME ZONE,
    aggression_until TIMESTAMP WITH TIME ZONE,
    disconnected_at TIMESTAMP WITH TIME ZONE,
    metadata JSONB,
    
    -- Foreign keys
    CONSTRAINT fk_player_sessions_character
        FOREIGN KEY (character_id)
        REFERENCES characters(character_id)
        ON DELETE CASCADE,
    
    CONSTRAINT fk_player_sessions_system
        FOREIGN KEY (current_system_id)
        REFERENCES solar_systems(system_id)
        ON DELETE SET NULL
);

-- Create indexes for performance
CREATE INDEX idx_player_sessions_character_active
    ON player_sessions(character_id, is_active);

CREATE INDEX idx_player_sessions_heartbeat
    ON player_sessions(last_heartbeat)
    WHERE is_active = TRUE;

CREATE INDEX idx_player_sessions_active
    ON player_sessions(is_active);

CREATE INDEX idx_player_sessions_system
    ON player_sessions(current_system_id)
    WHERE current_system_id IS NOT NULL;

-- Create index for combat queries
CREATE INDEX idx_player_sessions_combat
    ON player_sessions(combat_until)
    WHERE combat_until IS NOT NULL;

-- Comments
COMMENT ON TABLE player_sessions IS 'Tracks active player sessions with combat and connection status';
COMMENT ON COLUMN player_sessions.session_id IS 'Unique identifier for this session';
COMMENT ON COLUMN player_sessions.character_id IS 'Character associated with this session';
COMMENT ON COLUMN player_sessions.current_system_id IS 'Current solar system the character is in';
COMMENT ON COLUMN player_sessions.server_address IS 'Server address (IP:Port) where session is active';
COMMENT ON COLUMN player_sessions.connected_at IS 'When the session was established';
COMMENT ON COLUMN player_sessions.last_heartbeat IS 'Last heartbeat received from server';
COMMENT ON COLUMN player_sessions.is_active IS 'Whether the session is currently active';
COMMENT ON COLUMN player_sessions.combat_until IS 'Player remains in combat state until this time';
COMMENT ON COLUMN player_sessions.aggression_until IS 'Player has aggression flag until this time';
COMMENT ON COLUMN player_sessions.disconnected_at IS 'When the session ended';
COMMENT ON COLUMN player_sessions.metadata IS 'Additional session metadata (JSON)';
