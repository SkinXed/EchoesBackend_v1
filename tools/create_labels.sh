#!/bin/bash
# Script to create GitHub labels for the Echoes MMO Backend project
# Run this script with: bash tools/create_labels.sh

# Type labels
gh label create "bug" --description "Something isn't working" --color "d73a4a" --force
gh label create "feature" --description "New feature or request" --color "a2eeef" --force
gh label create "task" --description "Technical task or chore" --color "0e8a16" --force
gh label create "refactor" --description "Code refactoring" --color "fbca04" --force

# Layer labels
gh label create "[C++] Engine" --description "Unreal Engine C++ client code" --color "5319e7" --force
gh label create "[.NET] Backend" --description "ASP.NET Core backend API" --color "0052cc" --force
gh label create "[UI/HUD]" --description "UI and HUD implementation" --color "c5def5" --force
gh label create "[DB] Postgres" --description "Database schema and queries" --color "006b75" --force

# Priority labels
gh label create "P0" --description "Critical priority - immediate attention" --color "b60205" --force
gh label create "P1" --description "High priority - important" --color "d93f0b" --force
gh label create "P2" --description "Normal priority - backlog" --color "e99695" --force

echo "✓ All labels created successfully!"
