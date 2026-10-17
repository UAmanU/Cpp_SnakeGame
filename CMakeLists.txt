cmake_minimum_required(VERSION 3.20)
project(Cpp_SnakeGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Cpp_SnakeGame ${GAME_SOURCES})

target_include_directories(Cpp_SnakeGame PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/object"
)

target_link_libraries(Cpp_SnakeGame PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/libraylib.a"
    winmm
 gdi32
    opengl32
)
