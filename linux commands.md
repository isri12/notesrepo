# Linux Basic commands

df -h

ifconfig

sudo yum update 


# CMAKE BASICS 
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
