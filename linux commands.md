## Linux Basic commands

df -h

ifconfig

sudo yum update 



## Topics 
### PATH environment
In Linux, the PATH environment variable is a system-wide variable that specifies a list of directories where executable files and scripts are located. When you enter a command in the terminal, the system searches these directories for the corresponding executable.

Here's how to work with the PATH environment variable in Linux:

1. **Viewing the PATH Variable:**
   
   To view the current value of the PATH variable, you can use the `echo` command:
   
   ```bash
   echo $PATH
   ```

2. **Modifying the PATH Variable:**
   
   To add a directory to the PATH variable, you can modify your shell's configuration file, such as `.bashrc` for Bash or `.zshrc` for Zsh. Open the appropriate file in a text editor (e.g., `nano`, `vi`, `gedit`) and add the following line, replacing `/your/directory/path` with the actual directory you want to add:
   
   ```bash
   export PATH=$PATH:/your/directory/path
   ```

   After making the changes, save and exit the file. To apply the changes, either log out and log back in, or source the file:
   
   ```bash
   source ~/.bashrc   # For Bash
   source ~/.zshrc    # For Zsh
   ```

3. **Removing a Directory from the PATH Variable:**

   To remove a directory from the PATH variable, edit the shell configuration file and remove the corresponding line that sets the PATH.

4. **Temporary Modification:**

   If you want to temporarily modify the PATH for the current session, you can use the `export` command directly in the terminal:
   
   ```bash
   export PATH=$PATH:/your/temporary/directory
   ```

   This change will be effective for the current session only.

5. **Checking for Executables:**

   To check if a particular executable is in the PATH, you can use the `which` command. For example:
   
   ```bash
   which executable_name
   ```

   Replace `executable_name` with the actual name of the executable you're looking for.

Keep in mind that modifying the PATH variable should be done with caution to ensure that the system can locate essential executables and scripts needed for its normal operation.

## CMAKE BASICS 
```
cmake [options] -S <path-to-source> -B <path-to-build>
```
path-to-source - should have CMakeLists.txt

path-to-build - is usually under build folder.

```
cmake
cd build
cmake -s ../ -B . 
cd ..
CMakeLists.txt
```


# Google Unit Test 
Example: https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/ 

wget https://github.com/google/googletest/archive/release-1.8.0.tar.gz

tar xzf release-1.8.0.tar.gz

cd googletest-release-1.8.0

```
mkdir build && cd build
cmake ..
make -j
``` 

Now, copy the headers to a directory where compilers can find them:
sudo cp -r ../googletest/include /usr/local/include

copy static libraries: 
sudo cp -r ./googlemock/gtest/libgtest*.a /usr/local/lib/

Additionally, you can also add googlemock library (C++ framework for mocking objects):
sudo cp -r ./googlemock/libgmock*.a /usr/local/lib/


# git

```
git config --global user.email " "
git config --global user.name " "
```
## Adding a local repository to GitHub using Git
```
$ git remote add origin <REMOTE_URL>
```
#Sets the new remote
```
$ git remote -v
```
#Verifies the new remote URL
```
$ git push origin main
```
#Pushes the changes in your local repository up to the remote repository you specified as the origin

```
git branch --set-upstream-to=origin/<branch> master

git branch --set-upstream-to=origin/main master
```
set the upstream branch



hint:   git config pull.rebase false  # merge 
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only


git push origin HEAD:main
