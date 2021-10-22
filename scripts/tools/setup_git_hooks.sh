#!/bin/sh

HOOKS_FOLDER=.git/hooks

### Setup git hooks ####
if [ -d "$HOOKS_FOLDER" ]; then
  # Post merge hook.
  cp scripts/hooks/post-merge .git/hooks/post-merge
  chmod +x .git/hooks/post-merge
fi
