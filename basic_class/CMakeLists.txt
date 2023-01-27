cmake_minimum_required(VERSION 3.10)
project(study)

message(STATUS "Compiler")
message(STATUS " - ID\t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " -Version\t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path\t: ${CMAKE_CXX_COMPILER}")

add_subdirectory(logic)

add_executable(program Led.cpp)

target_link_libraries(program blink)
