cmake_minimum_required(VERSION 3.26)
find_package(OpenCV REQUIRED)
include_directories(${Open_CV_INCLUDE_DIRS})
project(Catan_AR_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(Catan_AR_Game
        draw_shapes.cpp
        draw_shapes.h
        util.cpp
        util.h
        ObjDrawer.cpp
        ObjDrawer.h
        main.cpp
        organize_markers.cpp
        organize_markers.h)

target_link_libraries(Catan_AR_Game ${OpenCV_LIBS})