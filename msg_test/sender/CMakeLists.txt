cmake_minimum_required(VERSION 3.10)
project(msg_test)

message(STATUS "Compiler")
message(STATUS " - ID\t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " -Version\t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path\t: ${CMAKE_CXX_COMPILER}")

add_subdirectory(includes)

add_executable(program_sender sender.c)

target_sources(msg_data.h)