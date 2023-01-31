# /led_logic/CMakeLists.txt

# 정적 라이브러리 logic을 만든다.
add_library(logic STATIC logic.cc)
# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(logic PUBLIC /leds ${CMAKE_SOURCE_DIR})
target_include_directories(logic PUBLIC /pattern ${CMAKE_SOURCE_DIR})

# 해당 라이브러리를 컴파일 할 옵션
target_compile_options(logic PRIVATE -Wall -Werror)

target_link_libraries(logic PRIVATE pthread)