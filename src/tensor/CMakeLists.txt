add_library(tensor Shape.cpp Shape.h Tensor.h TensorArray.h)

target_include_directories (tensor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})