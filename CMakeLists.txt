project(Rendering-Algorithms-2014)
FIND_PACKAGE(Boost REQUIRED)
FIND_PACKAGE(Freetype REQUIRED)
FIND_PACKAGE(PNG REQUIRED)
ADD_DEFINITIONS( -std=c++11 )
cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE Rendering_SOURCES "*.cpp")
file(GLOB_RECURSE Rendering_HEADERS "*.h")

set (Rendering_INCLUDE_DIRS "")
foreach (_headerFile ${Rendering_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Rendering_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Rendering_INCLUDE_DIRS)

include_directories(${Rendering_INCLUDE_DIRS} ${Boost_INCLUDE_DIR} "/usr/include/freetype2" ${PNG_INCLUDE_DIR})

add_executable (ra2014 ${Rendering_SOURCES})

target_link_libraries(ra2014 ${Boost_LIBRARIES} ${Freetype_LIBRARIES} ${PNG_LIBRARIES})
