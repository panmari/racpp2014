project(Rendering-Algorighms-2014)
cmake_minimum_required(VERSION 2.8)
include_directories ("/usr/include/cairo")

file(GLOB_RECURSE Foo_SOURCES "*.cpp")
file(GLOB_RECURSE Foo_HEADERS "*.h")

set (Foo_INCLUDE_DIRS "")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

include_directories(${Foo_INCLUDE_DIRS})
add_executable (ra2014 ${Foo_SOURCES})
