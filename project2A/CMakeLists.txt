
cmake_minimum_required(VERSION 3.16)
project(project2A LANGUAGES CXX)

add_library(project2A SHARED
    src/Engine.cpp
)

set_target_properties(project2A PROPERTIES PREFIX "")

target_include_directories(project2A
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        C:/libs/SDL2/x86_64-w64-mingw32/include
)

target_link_directories(project2A
    PUBLIC
        C:/libs/SDL2/x86_64-w64-mingw32/lib
)

target_link_libraries(project2A
    PUBLIC
        mingw32
        SDL2main
        SDL2
        opengl32
)

target_compile_features(project2A PUBLIC cxx_std_17)
