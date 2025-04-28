cmake_minimum_required(VERSION 3.16)

# project(helloworld VERSION 1.0.0 LANGUAGES CXX)

# find_library(Qt6)
set(Qt6_DIR "C:/Qt/6.4.0/android_x86_64/lib/cmake/Qt6")
# find_package(Qt6 REQUIRED COMPONENTS Core)
# set(Qt6_DIR "C:/Qt/6.4.0/mingw_64/lib/cmake/Qt6")
# C:\Qt\6.4.0\android_x86_64\lib\cmake\Qt6

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "C:/Qt/6.4.0/mingw_64/lib/cmake/Qt6")

project("helloword")


# qt_standard_project_setup()

add_executable(helloworld  # tells CMake that we want to build an executable (so not a library) called helloworld as a target. The target should be built from the C++ source file main.cpp.
    main.cpp
    mainwindow.ui
    mainwindow.cpp
)

target_link_libraries(helloworld PRIVATE Core Widgets)

set_target_properties(helloworld PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)