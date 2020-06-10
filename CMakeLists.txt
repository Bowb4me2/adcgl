# CMakeList.txt : CMake project for adcgl, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (adcgl)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

# TODO: Add tests and install targets if needed.
