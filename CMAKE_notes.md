# CMake basics

CMake is a tool to manage building of source code. 

``` CMake
cmake_minimum_required(VERSION 2.8)
CMAKE_CXX_STANDARD
CMAKE_CXX_STANDARD_REQUIRED
project() # Project name
project(${PROJECT_NAME})
project(HelloWorldTest)
add_library() #add library
add_library(project1_lib project1.cpp)
add_executable()  #Create the executable file called app
add_executable(app main.cpp)
target_link_libraries(app proj1lib)
set()
set(CMAKE_CXX_FLAGS "-g -Wall")
set(PROJECT_NAME MyProject) //Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.

option(test "Build all tests." OFF) # Makes boolean 'test' available. Options. Turn on with 'cmake -Dmyvarname=ON'.
```
-----------------------------------------------------------------------------------------------------------------------------

## simple hello world cpp file with cmake

Sample Project dir
.
├──  CMakeLists.txt
├── hello.h
├── hello.cpp
├── main.cpp
├── mymakescript.sh

File to edit:
CMakeLists.txt
``` CMake
# CMake version requirement
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
#add_compile_options(-std=c++11)

# Project name
project(HelloWorldTest)
# add library
add_library(proj1lib hello.cpp)
# Create the executable
add_executable(app main.cpp)
target_link_libraries(app proj1lib)
```

hello.cpp

``` cpp
#include<iostream>
#include "hello.h"

void hello()
{
    std::cout<<"testing hello world from cpp file! "<<std::endl;
}
```

hello.h
``` cpp
#ifndef HELLO_H
#define HELLO_H

void hello();

#endif
```
``` cpp
#include<iostream>
#include "hello.h"

int main ()
{
    hello();
    return 0;
}
```
mymakescript.sh
``` bash
#!/bin/bash

echo "####removing build####"
rm -r build 
sleep 3
echo "####making build####"
mkdir build
sleep 3
echo "####cd build####"
sleep 3
cd build
sleep 3
echo "####cmake ..####"
cmake ..
sleep 3
# echo "####cmake --build .####"
#cmake --build .
echo "####make####"
make
```

```
 ./mymakescript.sh 
####removing build####
####making build####
####cd build####
####cmake ..####
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/c/Users/Owner/Documents/code/cplusplus/CmakeCplusplus1/build
####make####
[ 25%] Building CXX object CMakeFiles/proj1lib.dir/hello.cpp.o
[ 50%] Linking CXX static library libproj1lib.a
[ 50%] Built target proj1lib
[ 75%] Building CXX object CMakeFiles/app.dir/main.cpp.o
[100%] Linking CXX executable app
[100%] Built target app
```
cd build
./app
testing hello world from cpp file! 
----------------------------------------------------------------------------------------------

# CMAKE CPP with Gtest:

build/ is where code is built - like where executables are.
lib/ includes gtest-1.6.0.
Rest of code in root:
-CMakeLists.txt must be in each subdirectory of the project
-main.cpp is just a driver file - the common place to run the normal application
-project1.cpp and project1.h have code for the class 'Project1'
-test_project1.cpp has code to test Project1




## Use cmake and make
If you want to test it all out through the common gtest procedure, first
**delete build/** (if present). Then...

In the project root:

    mkdir build
    cd build
    cmake ..

By now Makefiles should be created.
Then, to build executables and do all that linking stuff,

    make

To prepare all your tests, run this:

    cmake -Dtest=ON ..

To run all tests easily,

    make test

## Run executables
Then you can do ./myexecutable for the generated executable, e.g.:

    ./project1

and if you did cmake with test=ON:

    ./runUnitTests

# Details

## Command things
`cmake -Dtest=ON` turns on the variable 'test', which is specified in the root
CMakeLists.txt file. This is handy if you want to build in certain ways. Clear
description



good example: https://github.com/dmonopoly/gtest-cmake-example/tree/master 



mymakescript.sh

```
#!/bin/bash

echo "####removing build####"
rm -r build 
sleep 3
echo "####making build####"
mkdir build
sleep 3
echo "####cd build####"
sleep 3
cd build
sleep 3
echo "####cmake ..####"
cmake ..
sleep 3
# echo "####cmake --build .####"
#cmake --build .
echo "####make####"
make
```
```
chmod +X mymakescript.sh
```
