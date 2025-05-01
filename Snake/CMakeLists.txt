cmake_minimum_required(VERSION 3.16)

project("Snake" VERSION 0.1.0 DESCRIPTION "Classic snake game" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/third_party")
set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/third_party")

file(GLOB_RECURSE SOURCES CMAKE_CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/source/*.cpp")

FetchContent_Declare(
	raylib
	GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
	GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_SOURCE_DIR}/assets/")

target_include_directories(${PROJECT_NAME} PUBLIC
	"${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
