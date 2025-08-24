CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

PROJECT(app CXX)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_COMPILER ${clang})

SET(APP geometry-dash-game)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_BUILD_DIR ${PROJECT_SOURCE_DIR}/build)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)

#############################################
# Git submodules

EXECUTE_PROCESS(
    COMMAND bash "-c" "git submodule update --init --recursive"
)

set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(raylib)

#############################################
# External Library

# ADD_SUBDIRECTORY(lib)

#############################################
# Main Program

ADD_EXECUTABLE(${APP}
    src/main.cpp
    src/game.cpp
    src/render.cpp
)

TARGET_INCLUDE_DIRECTORIES(${APP}
  PUBLIC
    include/
  PRIVATE
    src
)

TARGET_LINK_LIBRARIES(${APP}
  PUBLIC
  PRIVATE
   raylib
)

ADD_CUSTOM_TARGET(run
    COMMAND ${APP}
    DEPENDS ${APP}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

SET(AVX512 "-mavx512f -mavx512dq -mavx512vl")
SET(AVX2 "-mavx2")
SET(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -fpermissive -g -DNDEBUG ${AVX2} -fsanitize=address")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 ${AVX2} -ftree-vectorize")

MESSAGE("Built: ${CMAKE_BUILD_TYPE} mode")
