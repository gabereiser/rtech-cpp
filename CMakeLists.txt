cmake_minimum_required(VERSION 3.16)

set(RTECH_VERSION "0.1.0")
string(TIMESTAMP TODAY "%Y/%m/%d")
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
project(rtech VERSION ${RTECH_VERSION})
project(rtech-bin VERSION ${RTECH_VERSION})

find_package(Git QUIET REQUIRED)
if(GIT_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
    # Get the current working branch
    execute_process(
        COMMAND git rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    
    # Get the latest abbreviated commit hash of the working branch
    execute_process(
        COMMAND git rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_COMMIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    message(WARNING "Git not found, cannot set version info")

    SET(REVISION "unknown")
    SET(BRANCH "unknown")
endif()

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h"
    "${PROJECT_BINARY_DIR}/include/config.h"
)

add_subdirectory(dependencies/glm)
add_subdirectory(dependencies/sdl2)
add_subdirectory(dependencies/bgfx)

find_package(ZLIB REQUIRED)
find_package(vulkan REQUIRED)

file(GLOB SOURCES src/**.cpp include/**.inl include/**.h)



set(LIBS ${ZLIB_LIBRARIES} ${VULKAN_LIBRARIES})

set(INCLUDE ${BGFX_INCLUDE_DIR}
            ${ZLIB_INCLUDE_DIRS}
            ${SDL2_INCLUDE_DIRS}
            ${VULKAN_INCLUDE_DIRS}
            ${CMAKE_CURRENT_BINARY_DIR}/include
            ${CMAKE_CURRENT_BINARY_DIR}/install/include
            ${CMAKE_SOURCE_DIR}/dependencies/glm
            ${CMAKE_SOURCE_DIR}/dependencies/bgfx/bgfx/include
)

add_library(rtech ${SOURCES})
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set_target_properties(rtech PROPERTIES DEBUG_POSTFIX d)
endif(CMAKE_BUILD_TYPE MATCHES Debug)
add_executable(rtech-bin ${SOURCES})

include_directories(${INCLUDE}
                    "${CMAKE_SOURCE_DIR}/include"
                    "${CMAKE_SOURCE_DIR}/src"
                    )

target_link_libraries(rtech ${LIBS} glm bx bimg bgfx SDL2-static)
target_link_libraries(rtech-bin rtech)

include(GNUInstallDirs)

# install rtech
install( TARGETS rtech
    EXPORT rtech-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} )
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include DESTINATION . )