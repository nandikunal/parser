# Text Parser
## Table of Contents
1. [Overview](#overview)
2. [Additional Information](#additional-information)
3. [Dependencies and Setup](#dependencies-and-setup)
4. [Build and Run](#build-and-run)
5. [Implementaiton Details](#implementaiton-details)
6. [Improvement Scope](#improvement-scope)
7. [References](#references)

### Overview

Parser application analyses a text block provided as regular text file input covering the following requirements:

1. It computes the start position or index in the text of all the smileys. Smileys are defined as the character colon plus an optional dash character and a bracket. e.g: :-] or :(

2. It computes the top 10 used words (excluding smileys)

3. It supports the following output formats:
    | Output Type      |  Value |
    |------------------|--------|
    |   CONSOLE        |    0   |
    |   TEXT           |    1   |
    |   XML            |    2   |
    |   CONSOLE_TEXT   |    3   |
    |   CONSOLE_XML    |    4   |
    |   TEXT_XML       |    5   |
    |   ALL            |    6   |

 * All the possible combination of the backends can be specified through command line arguments (Console only, Text file only, Text file + XML file, Text file + XML + console, etc). 
 * Each output contain all the above information (1 and 2).
 * Output format of information (1 and 2) is kept consistent for all the backends.

### Additional Information
#### Input [Text Block]
* Text Block input needs to be provided as path of regular text file in command like argument.
* UTF8 encoded text
* Input text can have lines are separated by '\n'
* Words in text blcok are separated by single or multiple consecutive whitespace characters.
* Some edge cases that are considered:
    - Whitespace can be '\t', multiple consecutive whitespace characters, etc
    - The text can consist of a single line without '\n' at the end. The line count should be 1 in such a case.

#### Opuput
* Smileys considered for computation as cobination of :, -, ], ), [, (
* Top used word with its occurance in logged in backends.
* Words are considered case sensitive, eg. "Name" and "name" are considered two different words
* Words with spacial characters like email address "hello.world@bmw.com" are considereded four words
    - hello
    - world
    - bmw
    - com
* Every execuation of parser will generate new output files for Text file and XML
    - Text file - output.txt
    - XML - output.xml
* Output of all three backend is consistent as shown below
    |<smiely>,<smiley_start_index>|
    |<smiely>,<smiley_start_index>|
    |<smiely>,<smiley_start_index>|
    |...                          |
    |<word>,<occurance_count>     |
    |<word>,<occurance_count>     |
    |<word>,<occurance_count>     |
    |...                          |

#### Supporting following checklist
* Solution has to run on Linux.
* Design with classes and clean APIs.
* Good documentation.
* Code quality to be comparable to production code.
* Usage of C++11/14/17 features.
* Usage of STL and Boost features would be preferable whenever applicable, or other known open source libraries.
* Unit tests with high coverage > 90%.
* CMake files which covers building and adding the tests.

### Dependencies and Setup
One can setup by installing all these rquired components.
* cmake 3.10 or above
* git
* boost
* spdlog logger
* gcc-8 or above
* googletest
* lcov
* gcovr

Another alternative is to Install Docker, and execute
```
user@lnx:~/task# sh rundocker.sh
```
This will setup the environment to build and run Parser and Unit test.

### Build and Run
* Build without Unit Test
```
root@lnx:/home/user/task# cmake -Bbuild .
root@lnx:/home/user/task# cd build
root@lnx:/home/user/task/build# make -j
root@lnx:/home/user/task/build# ./parser <OutputType> <TextFilePath>
```
* Build with Unit Test
```
root@lnx:/home/user/task# cmake -Bbuild . -DUTEST=ON
root@lnx:/home/user/task# cd build
root@lnx:/home/user/task/build# make -j
root@lnx:/home/user/task/build# ./test/UTest
```
* Generate coverage report
```
root@lnx:/home/user/task# cmake -Bbuild . -DUTEST=ON
root@lnx:/home/user/task# cd build
root@lnx:/home/user/task/build# make -j
root@lnx:/home/user/task/build# ./test/UTest
root@lnx:/home/user/task/build# gcovr --exclude=../main.cpp -r ../
```
### Implementaiton Details

Parser is Single threaded process parsing UTF8 Text to output top used words and start position of smiley.
#### Block Diagram
![Block Diagram](https://www.plantuml.com/plantuml/png/SoWkIImgAStDuKfCAYufIamkKKZEIImkLb3mz2yjAIWjuO9m4S0vFwyuFoSL8kkPMv23eI8ajQ84ZtH4RWuUMOYK6z0X-KMLM8qEI2mgJYtYIiqhpLN0q1XIMP3A1NMwWasDhYwcUr6amIRYa8Eu55CAA8FgIeVKl1HW4080)

### Improvement Scope
* create threads for every backend output operation
* custom cmake target commad to generate coverage report
* separate class to process input file containing Text Block
* implement CLI to take interective input from user.

### References
* https://stackoverflow.com/
* Regex - https://www.rexegg.com/regex-quickstart.html
* spdlog - https://github.com/gabime/spdlog/wiki/1.-QuickStart
* cpp - https://en.cppreference.com/
* boost - https://www.boost.org/
* GTest - https://github.com/google/googletest/tree/main/googletest
* CMake - https://cmake.org/
