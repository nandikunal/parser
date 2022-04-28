cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(parser)

option(UTEST "Set unit test Option" OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage -fprofile-abs-path")
endif()

find_package(spdlog REQUIRED)
find_package(Boost COMPONENTS system filesystem)

list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include")

list(APPEND LIBS "spdlog::spdlog")
list(APPEND LIBS "${Boost_LIBRARIES}")
list(APPEND LIBS parser_core_lib)

add_executable(${CMAKE_PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/main.cpp)

set_target_properties(${CMAKE_PROJECT_NAME}
    PROPERTIES
        INCLUDE_DIRECTORIES "${INCLUDE_DIRS}"
        LINK_LIBRARIES "${LIBS}"
)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(UTEST)
        message(STATUS "Unit Test is ${UTEST}")
        add_subdirectory(${CMAKE_SOURCE_DIR}/test)
    endif()
endif()
