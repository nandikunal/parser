# Parser core

add_library(parser_core_lib)

target_include_directories(parser_core_lib
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_sources(parser_core_lib PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/console_output_impl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/text_output_impl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xml_output_impl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/output_factory.cpp
    ${CMAKE_CURRENT_LIST_DIR}/text_parser.cpp
)
