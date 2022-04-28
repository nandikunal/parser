# Unit test
enable_testing()

find_package(GTest REQUIRED)
find_package(Boost COMPONENTS system filesystem)

add_executable(utest test_output_factory.cpp test_text_parser.cpp)

list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include")

list(APPEND LIBS "${Boost_LIBRARIES}")
list(APPEND LIBS GTest::gtest GTest::gmock GTest::gmock_main)
list(APPEND LIBS parser_core_lib)

set_target_properties(utest
    PROPERTIES
        INCLUDE_DIRECTORIES "${INCLUDE_DIRS}"
        LINK_LIBRARIES "${LIBS}" 
)

add_test(NAME Test COMMAND utest)
