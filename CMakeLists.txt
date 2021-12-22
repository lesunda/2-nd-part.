# CMakeList.txt : CMake project for V1.5CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("V1.5CMakeProject1")

# Include sub-projects.
add_executable (V1.5CMakeProject1 "pagrindinis.cpp" "V1.5.cpp" "headeris.h")
