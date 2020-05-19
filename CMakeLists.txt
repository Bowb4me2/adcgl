# CMakeList.txt : CMake project for adcgl, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("adcgl")

# Add source to this project's executable.
add_executable (adcgl "src/main.cpp" "src/tensor/Shape.cpp" "src/tensor/TensorArray.cpp")

# TODO: Add tests and install targets if needed.
