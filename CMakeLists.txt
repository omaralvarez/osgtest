cmake_minimum_required(VERSION 3.7)
project(osgtest)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenSceneGraph REQUIRED COMPONENTS osgUtil osgViewer)
include_directories(${OPENSCENEGRAPH_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENSCENEGRAPH_LIBRARIES})