
- `git checkout -b <branch-name>`: Creates a new branch and switches to it.
- `git push origin <branch-name>`: Pushes your new branch to the remote repository.
- `git push --set-upstream origin <branch-name>`: Pushes the branch and sets it up to track the corresponding remote branch, so future `git push` and `git pull` commands are simplified.

### 1. `git checkout -b <branch-name>`
- This command **creates a new branch** and switches to it immediately.
- The `-b` option tells `git` to create a new branch with the given name.
  
  **Example:**
  ```bash
  git checkout -b feature-branch
  ```
  This creates a new branch called `feature-branch` and switches to it.

### 2. `git push origin <branch-name>`
- This command **pushes your branch** (local branch) to the remote repository (in this case, called `origin`).
- `origin` is the default name for the remote repository you cloned from, but you can push to other remotes as well.
  
  **Example:**
  ```bash
  git push origin feature-branch
  ```
  This pushes your `feature-branch` to the `origin` remote (usually the main Git repository you're working with).

### 3. `git push --set-upstream origin <branch-name>` or `git push -u origin <branch-name>`
- This command pushes the branch **and sets the upstream tracking** so that future `git push` and `git pull` commands can be executed without specifying the remote and branch name.
- The `--set-upstream` or `-u` option links your local branch to the remote branch, so `git` knows which branch to push or pull changes from in the future without needing additional arguments.
  
  **Example:**
  ```bash
  git push --set-upstream origin feature-branch
  ```
  After running this, you can simply run `git push` or `git pull` without specifying `origin feature-branch` every time, as `git` will remember that this local branch is linked to the remote `feature-branch`.



    
    
    
    
    
    
    
    
    
 ```   
    git config --global user.name "sam smith"
    
    git config --global user.email sam@example.com
    
    git config --list

    git init 

    git clone /path/to/repository
    
    git clone username@host:/path/to/repository
```
------
```
    git status
    
    git add <filename>
    git add *
    git add -u #git add only modified changes and ignore untracked files

    git commit -m "Commit message"
    git commit -a
    git commit -am "Commit message"
    
    git push --set-upstream origin
    git push origin master  # Send changes to the master branch of your remote repository:
  
    git remote add origin <server> #If you haven't connected your local repository to a remote server, add the server to be able to push to it:
    git remote -v #List all currently configured remote repositories:

    git checkout -b <branchname> #Create a new branch and switch to it:
    git checkout <branchname> #Switch from one branch to another:
 
    git branch
    git branch -al # List all the branches in your repo, and also tell you what branch you're currently in:
    git push origin <branchname>
    git push --all origin
    git push origin :<branchname> #Delete a branch on your remote repository:

    git pull
    git merge <branchname> #To merge a different branch into your active branch:
    git diff
    git diff --base <filename>
    git diff <sourcebranch> <targetbranch>
    git add <filename>
    git tag 1.0.0 <commitID> #You can use tagging to mark a significant changeset, such as a release:
    git log
    git push --tags origin

    git checkout -- <filename>
    git fetch origin #Instead, to drop all your local changes and commits, fetch the latest history from the server and point your local master branch at it, do this:
    git reset --hard origin/master
    git grep "foo()" #Search the working directory for foo():
```
https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html 
```


You can follow one of the suggestions provided in the hint messages. Here are your options:

1. Merge (the default strategy):
   ```
   git config pull.rebase false
   ```

2. Rebase:
   ```
   git config pull.rebase true
   ```

3. Fast-forward only:
   ```
   git config pull.ff only
   ```

Choose the option that suits your workflow best. For example, if you want to perform a merge to reconcile the divergent branches, you can use:
```
git config pull.rebase false
```

After setting the configuration, you can pull the changes again:
```
git pull origin main
```

If you want to set a default preference for all repositories, you can use the `--global` flag with `git config`. For example:
```
git config --global pull.rebase false
```

This will set the merge strategy to be the default behavior for all repositories.

