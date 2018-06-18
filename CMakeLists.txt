cmake_minimum_required(VERSION 3.10)
project(shader-time)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/gl3w)
set_source_files_properties(
    external/gl3w/src/gl3w.c
    PROPERTIES GENERATED TRUE
)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(external/glfw)

include_directories(
    include
    external/glm
    external/stb
)

file(GLOB HEADERS include/*.hpp)
file(GLOB SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/src/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
    COMMENT "Symlinking assets folder"
)

target_link_libraries(${PROJECT_NAME} gl3w glfw)
