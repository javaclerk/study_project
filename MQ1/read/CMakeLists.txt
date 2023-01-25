cmake_minimum_required(VERSION 3.16)
project(study)

message(STATUS "Compiler")
message(STATUS " - ID\t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " -Version\t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path\t: ${CMAKE_CXX_COMPILER}")

add_executable(re re.c)