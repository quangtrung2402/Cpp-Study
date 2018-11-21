cmake_minimum_required(VERSION 2.8)

project(SearchWord)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Create a list with all source/header files
set( project_sources
   SRC/main.cpp
   SRC/Utility.cpp
   SRC/Reader.cpp
   SRC/Searcher.cpp
   SRC/FileManager.cpp
)

set( project_headers
   HDR/Reader.h
   HDR/Utility.h
   HDR/Searcher.h
   HDR/FileManager.h
)

# Create executable with all necessary source files
add_executable(${PROJECT_NAME}
  ${project_sources}
  ${project_headers}
)

macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

use_cxx11()
