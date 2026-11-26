cmake_minimum_required(VERSION 4.3)

project(main)

set(SRC "src")
set(LIBRARY "compound")
set(TESTDIR "CompoundTest")

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

add_library(compound_static STATIC 
    ${SRC}/datastructure/datastructure.c
    ${SRC}/error/error.c
    ${SRC}/io/curlftp.c
    ${SRC}/io/curlhttp.c
    ${SRC}/process/process.c
    ${SRC}/thread/thread.c)

# keep files in order.
add_library(datastructure STATIC IMPORTED)
add_library(error STATIC IMPORTED)
add_library(curlftp STATIC IMPORTED)
add_library(curlhttp STATIC IMPORTED)
add_library(process STATIC IMPORTED)

target_include_directories(${LIBRARY}_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(${LIBRARY}_static PROPERTIES POSITION_INDEPENDENT_CODE ON)

install(TARGETS compound_static ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX})

# 11.04.26
# create a new directory inside of the build directory to house the lib file 
add_custom_command(
    TARGET ${LIBRARY}_static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/lib" 
    COMMAND ${CMAKE_COMMAND} -E copy 
    "${CMAKE_CURRENT_BINARY_DIR}/lib${LIBRARY}_static.a"
    "${CMAKE_CURRENT_BINARY_DIR}/lib/lib${LIBRARY}_static.a"
    COMMENT "Copying static compound_static.a file to build directory.")

# Copy archive file 
# #
add_custom_command (
    TARGET ${LIBRARY}_static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/lib/lib${LIBRARY}_static.a" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/home/patrick/Dev/GitProjects/${TESTDIR}/libs/lib${LIBRARY}_static.a"
    COMMENT "Moving file to archive file..."
)

# Copy the *.h files
# # 
add_custom_command (
    TARGET ${LIBRARY}_static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/home/patrick/Dev/GitProjects/${TESTDIR}/include/"
    COMMENT "Moving include files...")

# #
# Create an Archive File, and use it.
# 10.26.26
# #

# this program create a library or "static library" of datastructures that
# is compiled into build/library the file is libds_static.a and is used in StaticTest program, one level above. StaticTest uses the library and makes 
# function calls using the library's functions: stack, linkedlist, queue...
# Sharedlibrary is in github, but StaticTest isn't. 
# To add the library to another program, add the header files: stack.h,
# linkedlist.h etc. into main's include declaration.
# 
# StaticTest/src/main.c
# #include "stack.h"
# 
# initialize the datastructure and you're in business. 
# example:
# stack_t stack = create_stack();
# stack.data ...
