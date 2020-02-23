cmake_minimum_required(VERSION 3.16)

project(00-hello-triangle)

add_executable(00-hello-triangle main.cpp)

add_dependencies(00-hello-triangle rtech)

target_link_libraries(00-hello-triangle rtech)

install( TARGETS 00-hello-triangle
    EXPORT 00-hello-triangle-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_BINDIR} )