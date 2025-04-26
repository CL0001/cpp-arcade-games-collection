cmake_minimum_required(VERSION 3.30)

project("Breakout" VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/third_party")

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/third_party")

file(GLOB_RECURSE SOURCES CMAKE_CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

FetchContent_Declare(
	raylib
	GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
	GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_compile_definitions(${PROJECT_NAME} PRIVATE ASSETS_PATH="${CMAKE_SOURCE_DIR}/assets/")

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)