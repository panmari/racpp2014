project(Rendering-Algorighms-2014)
cmake_minimum_required(VERSION 2.8)
include_directories ("/usr/include/cairo")

file(GLOB_RECURSE Rendering_SOURCES "*.cpp")
file(GLOB_RECURSE Rendering_HEADERS "*.h")

set (Rendering_INCLUDE_DIRS "")
foreach (_headerFile ${Rendering_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Rendering_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Rendering_INCLUDE_DIRS)

include_directories(${Rendering_INCLUDE_DIRS})
add_executable (ra2014 ${Rendering_SOURCES})
