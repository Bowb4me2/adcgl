# CMakeList.txt : CMake project for adcgl, include source and define
# project specific logic here.

cmake_minimum_required(VERSION 3.8)

project (swing LANGUAGES CXX)

# Add subdirectories
add_subdirectory("swing")
add_subdirectory("tests")

# TODO: install targets if needed.
