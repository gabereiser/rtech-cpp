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

### Present Options
option(RTECH_BUILD_SAMPLES "Build rtech samples" ON)

### Define Project
project(rtech VERSION ${RTECH_VERSION})

set(INSTALL_BIN_DIR "${CMAKE_INSTALL_PREFIX}/bin" CACHE PATH "Installation directory for executables")
set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib" CACHE PATH "Installation directory for libraries")
set(INSTALL_INC_DIR "${CMAKE_INSTALL_PREFIX}/include" CACHE PATH "Installation directory for headers")
set(INSTALL_MAN_DIR "${CMAKE_INSTALL_PREFIX}/share/man" CACHE PATH "Installation directory for manual pages")
set(INSTALL_PKGCONFIG_DIR "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" CACHE PATH "Installation directory for pkgconfig (.pc) files")


### Add Git information to the build
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

### Set dependency options
option(GLM_QUIET "" ON)
if(CMAKE_BUILD_TYPE MATCHES Debug)
option(BGFX_CONFIG_DEBUG "" ON)
endif(CMAKE_BUILD_TYPE MATCHES Debug)
option(BGFX_BUILD_TOOLS "" OFF)
option(BGFX_BUILD_EXAMPLES "" OFF)
option(BGFX_INSTALL "" OFF)
set(SDL_STATIC_ENABLED_BY_DEFAULT ON)
set(SDL_SHARED_ENABLED_BY_DEFAULT OFF)
### Add dependencies

add_subdirectory(dependencies/glm)
add_subdirectory(dependencies/sdl2)
add_subdirectory(dependencies/bgfx)
add_subdirectory(dependencies/zlib)


file(GLOB_RECURSE SOURCES 
        src/**.cpp
        include/**.inl
        include/**.h
)


set(INCLUDE ${BGFX_INCLUDE_DIR}
            ${SDL2_INCLUDE_DIRS}
            ${VULKAN_INCLUDE_DIRS}
            ${CMAKE_CURRENT_BINARY_DIR}/include
            ${CMAKE_SOURCE_DIR}/dependencies/glm
            ${CMAKE_SOURCE_DIR}/dependencies/zlib
            ${CMAKE_SOURCE_DIR}/dependencies/bgfx/bgfx/include
            ${CMAKE_SOURCE_DIR}/dependencies/sdl2/include
)

add_library(rtech STATIC ${SOURCES} )

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set_target_properties(rtech PROPERTIES DEBUG_POSTFIX d)
endif(CMAKE_BUILD_TYPE MATCHES Debug)


target_include_directories(rtech PUBLIC ${INCLUDE}
                    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
                    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                    $<INSTALL_INTERFACE:include/rtech>
)

set_property(TARGET rtech PROPERTY POSITION_INDEPENDENT_CODE 1)

if(WIN32)
add_definitions(-DDLL)
endif(WIN32)

add_dependencies(rtech zlib glm bx bimg bgfx SDL2-static)
target_link_libraries(rtech zlib glm bx bimg bgfx SDL2-static)

include(GNUInstallDirs)

# install rtech
install( TARGETS rtech
    EXPORT rtech-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} )
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX} )
install( FILES ${CMAKE_CURRENT_BINARY_DIR}/include/config.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include )


if(RTECH_BUILD_SAMPLES)
    add_subdirectory(samples)
endif(RTECH_BUILD_SAMPLES)