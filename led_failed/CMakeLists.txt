cmake_minimum_required(VERSION 3.16)
project(cmake_test)

message(STATUS "Compiler")
message(STATUS " - ID\t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version\t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path\t: ${CMAKE_CXX_COMPILER}")


add_subdirectory(logic)

add_executable (program main.cc)

target_link_libraries(program blink)
