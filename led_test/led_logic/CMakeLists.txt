# /led_logic/CMakeLists.txt

# 정적 라이브러리 pattern 를 만든다.
add_library(pattern STATIC pattern.cc)

# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(pattern PUBLIC /includes ${CMAKE_SOURCE_DIR})

# 해당 라이브러리를 컴파일 할 옵션
target_compile_options(pattern PRIVATE -Wall -Werror)

target_link_libraries(pattern PRIVATE pthread)