# Git Basic Commands

## Table of Contents
1. [Setup & Configuration](#setup--configuration)
2. [Repository Basics](#repository-basics)
3. [Staging & Committing](#staging--committing)
4. [Branches](#branches)
5. [Remote Operations](#remote-operations)
6. [Viewing Changes](#viewing-changes)
7. [Tags & Versioning](#tags--versioning)
8. [Undoing Changes](#undoing-changes)
9. [Rebase Operations](#rebase-operations)
10. [Pull Strategies](#pull-strategies)
11. [SSH Key Management](#ssh-key-management)

---

## Setup & Configuration

### Initial Configuration
```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
git config --list  # View all configurations
```

### Repository Setup
```bash
git init                                    # Initialize a new local repository
git clone /path/to/repository              # Clone a local repository
git clone username@host:/path/to/repo      # Clone a remote repository
git clone https://github.com/user/repo.git # Clone from GitHub/GitLab
```

---

## Repository Basics

### Check Status & Information
```bash
git status              # Display current branch and changes
git remote -v           # List all configured remote repositories (with URLs)
git remote add origin <REMOTE_URL>  # Add a new remote repository
git branch              # List local branches
git branch -a           # List all branches (local and remote)
```

---

## Staging & Committing

### Staging Files
```bash
git add <filename>      # Stage specific file
git add *               # Stage all changes
git add -u              # Stage only modified/deleted files (tracked by Git, ignores untracked)
```

### Committing Changes
```bash
git commit -m "Commit message"              # Commit staged changes
git commit -a                               # Commit all tracked changes
git commit -am "Commit message"             # Stage and commit tracked changes at once
git commit --amend                          # Modify the last commit
git commit --amend -m "New message"         # Update last commit message
```

---

## Branches

### Creating & Switching Branches
```bash
git checkout -b <branchname>    # Create a new branch and switch to it
git checkout <branchname>       # Switch to an existing branch
git branch --set-upstream-to=origin/<branch> <local-branch>  # Set upstream branch
```

### Pushing Branches
```bash
git push origin <branchname>                # Push branch to remote
git push --all origin                       # Push all branches
git push -u origin <branchname>             # Push and set upstream tracking
git push --set-upstream origin <branchname> # Alternative: push with upstream
git push origin HEAD:main                   # Push current branch as 'main' to remote
git push origin :<branchname>               # Delete a remote branch
```

### Branch Merging
```bash
git merge <branchname>          # Merge another branch into current branch
git merge --no-ff <branchname>  # Create merge commit (preserves history)
```

---

## Remote Operations

### Pulling & Fetching
```bash
git pull                        # Fetch and merge from tracked remote branch
git fetch origin <branchname>   # Fetch specific branch from remote
git fetch origin main           # Fetch latest changes from main
```

### Pull Strategy Configuration
Choose how Git handles divergent branches when pulling:

```bash
# Option 1: Merge (default strategy)
git config pull.rebase false

# Option 2: Rebase
git config pull.rebase true

# Option 3: Fast-forward only
git config pull.ff only
```

Set globally:
```bash
git config --global pull.rebase false
```

---

## Viewing Changes

### Comparing Changes
```bash
git diff                                    # Show changes in working directory
git diff --base <filename>                  # Compare with base version
git diff <sourcebranch> <targetbranch>     # Compare two branches
```

### Viewing Commit History
```bash
git log                         # Show commit history
git show <commit-hash>          # Show details of specific commit
git show --name-only <commit-hash>    # Show files changed in a commit
git show --name-status <commit-hash>  # Show files with status (modified/added/deleted)
git grep "foo()"                # Search for 'foo()' in the working directory
```

---

## Tags & Versioning

### Creating & Pushing Tags
```bash
git tag 1.0.0 <commitID>        # Create a tag for a specific commit
git tag 1.0.0                   # Tag the current commit
git push --tags origin          # Push all tags to remote
```

---

## Undoing Changes

### Discarding Changes
```bash
git checkout -- <filename>      # Discard changes to a file
git reset --hard main           # Reset branch to match main (destructive)
git reset --hard origin/master  # Reset to remote master (destructive)
git fetch origin                # Fetch latest from remote
git reset --hard origin/main    # Reset hard to latest remote main
```

---

## Rebase Operations

### Basic Rebase
```bash
git rebase origin/main          # Rebase current branch onto origin/main
git rebase master               # Rebase current branch onto master
git rebase -i origin/master     # Interactive rebase for commit editing
```

### Rebase Workflow
```bash
# 1. Update main branch
git checkout main
git fetch origin main

# 2. Switch to your branch
git checkout branch1

# 3. Perform rebase
git rebase origin/main

# 4. Resolve conflicts if any
git add <resolved-files>
git rebase --continue

# 5. Cancel rebase if needed
git rebase --abort

# 6. Force push after rebase (use --force-with-lease for safety)
git push --force-with-lease origin branch1
```

### Reset Branch to Main
```bash
git checkout main
git pull origin main
git checkout branch1
git reset --hard main           # Reset branch1 to match main
git push --force origin branch1 # Force push (requires caution)
```

---

## Pull Strategies

When pulling changes, Git can handle divergent branches in different ways:

```bash
# Merge strategy (default) - creates a merge commit
git config pull.rebase false

# Rebase strategy - replays your commits on top of remote
git config pull.rebase true

# Fast-forward only - only updates if no divergence
git config pull.ff only
```

After setting the configuration, pull changes:
```bash
git pull origin main
```

---

## SSH Key Management

### Generate New SSH Key
```bash
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
# Default location: ~/.ssh/id_rsa
# Custom location: ~/.ssh/id_rsa_gitlab
```

### Add Key to SSH Agent
```bash
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa           # Add default key
ssh-add ~/.ssh/id_rsa_gitlab    # Add custom key
```

### Copy Public Key to Clipboard
```bash
# macOS
cat ~/.ssh/id_rsa.pub | pbcopy

# Linux
cat ~/.ssh/id_rsa.pub | xclip -selection clipboard

# Windows
cat ~/.ssh/id_rsa.pub | clip

# Or display and copy manually
cat ~/.ssh/id_rsa.pub
```

### Add Key to GitLab/GitHub
1. Go to your profile → Settings/Preferences → SSH Keys
2. Paste your public key from clipboard
3. Add a descriptive title
4. Click "Add key"

### Test SSH Connection
```bash
ssh -T git@gitlab.com      # For GitLab
ssh -T git@github.com      # For GitHub
```

---

## References
- [Atlassian Bitbucket Git Commands](https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html)
- [Official Git Documentation](https://git-scm.com/doc)
