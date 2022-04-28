cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")

project(parser)

option(UTEST "Set unit test Option" OFF)

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

if(UTEST)
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()
