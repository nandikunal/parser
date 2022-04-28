# Text Parser
## Table of Contents
1. [Overview](#overview)
2. [Dependencies and Setup](#setup)
4. [Build and Run instructions](#build-run)
5. [Improvement scope](#scope)

### Overview

Parser application analyses a text block provided as regular text file input to covering the following requirements:

1. It computes the start position or index in the text of all the smileys. Smileys are defined as the character colon plus an optional dash character and a bracket. e.g: :-] or :(

2. It computes the top 10 used words (excluding smileys)

3. It supports the following output formats:
    | Output Type      |  Value |
    |------------------|--------|
    | * CONSOLE        |    0   |
    | * TEXT           |    1   |
    | * XML            |    2   |
    | * CONSOLE_TEXT   |    3   |
    | * CONSOLE_XML    |    4   |
    | * TEXT_XML       |    5   |
    | * ALL            |    6   |
    |------------------|--------|

 * All the possible combination of the backends can be specified through command line arguments (Console only, Text file only, Text file + XML file, Text file + XML + console, etc). 
 * Each output contain all the above information (1 and 2).
 * Output format of information (1 and 2) is kept consistent for all the backends.
 
 Note: This last requirement is not skippable and it is expected that the solution provided is generic (e.g. allows for easy addition of future output formats).

### Dependencies and Setup

### Build and Run instructions
### Additional information
### Improvement scope
### Scope
Additional information:

·       UTF8 encoding can be assumed

·       Lines are separated by '\n'

·       Words are separated by whitespace

·       There are some edge cases that should be considered:

·       Whitespace can be '\t', multiple consecutive whitespace characters, etc

·       The text can consist of a single line without '\n' at the end. The line count should be 1 in such a case.

Desired solution should have the following:

·       Solution has to run on Linux.

·       Design with classes and clean APIs.

·       Good documentation.

·       Code quality to be comparable to production code.

·       Usage of C++11/14/17 features.

·       Usage of STL and Boost features would be preferable whenever applicable, or other known open source libraries.

·       Unit tests with high coverage > 90%.

·       CMake files which covers building and adding the tests.


- Factory Class – Output (Console, file, XML, possible to extend)
- BaseClass for Output extend it to different types.
- Utility file to define logging macro.
- Create threads to write the output in different ways.
- Case Sensitive

### Dependency
- CMake VERSION 3.22 or above
- 
git clone https://github.com/gabime/spdlog.git
cd spdlog;cmake -Bbuild .;cd build;make -j install

- Setting up Docker 
apt update
apt install build-essential
apt install software-properties-common
add-apt-repository ppa:git-core/ppa
apt install git

- Install GCC 9
add-apt-repository ppa:ubuntu-toolchain-r/test
apt install gcc-9 g++-9 -y

ln -s /usr/bin/gcc-9 /usr/bin/gcc
ln -s /usr/bin/g++-9 /usr/bin/g++

- Install CMake 3.23
apt install wget -y
wget -v https://github.com/Kitware/CMake/releases/download/v3.23.1/cmake-3.23.1-linux-x86_64.sh
chmod +x cmake-3.23.1-linux-x86_64.sh
mkdir /opt/cmake

./cmake-3.23.1-linux-x86_64.sh --prefix=/opt/cmake

cp -r bin /usr/
cp -r doc /usr/share/
cp -r man /usr/share/
cp -r share /usr/

- Install boost & gdb
apt install libboost-all-dev
apt install gdb

apt-get update
apt-get upgrade

https://github.com/google/googletest/blob/main/googletest/README.md

apt install gcovr
gcovr --exclude=../main.cpp -r ../
