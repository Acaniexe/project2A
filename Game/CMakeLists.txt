
if(CMAKE_BUILD_TYPE STREQUAL "Release")
add_executable(Game WIN32 src/main.cpp)
else()
add_executable(Game src/main.cpp)
endif()

target_link_libraries(Game project2A)

# Install rules
install(TARGETS Game
    RUNTIME DESTINATION .
)

install(TARGETS project2A
    RUNTIME DESTINATION .
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/Game/assets
    DESTINATION .
)

install(FILES C:/libs/SDL2/x86_64-w64-mingw32/bin/SDL2.dll
    DESTINATION .
)
