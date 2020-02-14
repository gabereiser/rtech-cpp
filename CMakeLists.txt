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

file(GLOB SOURCES src/**.cpp include/**.h)
link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(
    ${CMAKE_BINARY_DIR}/src
    ${CMAKE_BINARY_DIR}/include
)

set(SDL2_BUILDING_LIBRARY False)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_net REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(ZLIB REQUIRED)
find_package(GLM REQUIRED)

set(LIBS ${ZLIB_LIBRARIES}
         ${OPENGL_LIBRARIES}
         ${SDL2_LIBRARY}
         ${SDL2_IMAGE_LIBRARIES}
         ${SDL2_TTF_LIBRARIES}
         ${SDL2_NET_LIBRARIES}
         ${SDL2_MIXER_LIBRARIES}
)

set(INCLUDE ${GLM_INCLUDE_DIR}
            ${ZLIB_INCLUDE_DIRS}
            ${OPENGL_INCLUDE_DIR}
            ${SDL2_INCLUDE_DIR}
            ${SDL2_IMAGE_INCLUDE_DIRS}
            ${SDL2_TTF_INCLUDE_DIRS}
            ${SDL2_NET_INCLUDE_DIRS}
            ${SDL2_MIXER_INCLUDE_DIRS}
)

add_executable(rtech ${SOURCES})

include_directories(${INCLUDE}
                    "${CMAKE_CURRENT_SOURCE_DIR}/include"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src"
                    )

target_link_libraries(rtech ${LIBS})



