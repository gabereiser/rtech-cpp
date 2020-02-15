cmake_minimum_required(VERSION 3.16)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

### Set C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


### Define Project Sources
project(rtech VERSION 0.1.0)

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
)

add_subdirectory(dependencies/bgfx)

find_package(ZLIB REQUIRED)

file(GLOB SOURCES src/**.cpp include/**.inl include/**.h)



set(LIBS ${ZLIB_LIBRARIES})

set(INCLUDE ${BGFX_INCLUDE_DIR}
            ${ZLIB_INCLUDE_DIRS}
            ${CMAKE_CURRENT_BINARY_DIR}/include
)

add_library(rtech ${SOURCES})

include_directories(${INCLUDE}
                    "${CMAKE_CURRENT_SOURCE_DIR}/include"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/bgfx/bgfx"
                    )

target_link_libraries(rtech ${LIBS} bx bimg bgfx)



