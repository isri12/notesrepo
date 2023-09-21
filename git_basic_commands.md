  git config --global user.name "sam smith"
  git config --global user.email sam@example.com
  git config --list

  git init 

  git clone /path/to/repository
  git clone username@host:/path/to/repository

  git add <filename>
  git add *

  git commit -m "Commit message"
  git commit -a
  git commit -am "Commit message"

  git push origin master  # Send changes to the master branch of your remote repository:

  git status

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






https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html 
