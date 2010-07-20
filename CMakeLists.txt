# Copyright (c) 2010 Stefan Hutter, University of Zurich

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(MaoniOfLife)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(Boost  REQUIRED)
find_package(GLEW   REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Maoni  REQUIRED)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${CMAKE_SOURCE_DIR}/boost-la.tar.gz
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/include)

include_directories(include
  ${CMAKE_BINARY_DIR}/include
  ${Boost_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIR}
  ${OpenGL_INCLUDE_DIRS}
  ${Maoni_INCLUDE_DIRS}
  )

add_executable(MaoniOfLife 
  src/ca_ruleset.cpp
  src/custom_ca.cpp
  src/exercise.cpp
  src/game_of_life.cpp
  src/main.cpp
  src/simple_1d_ca.cpp
  src/simple_cell.cpp
  )
  
target_link_libraries(MaoniOfLife ${Maoni_LIBRARIES})