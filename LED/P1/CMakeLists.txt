cmake_minimum_required(VERSION 3.16)

project(chj_test_1)

message(STATUS "Compiler")
message(STATUS " - ID\t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version\t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path\t: ${CMAKE_CXX_COMPILER}")

add_executable (program led1_p1.c led2_p1.c led3_p1.c led4_p1.c led5_p1.c)
