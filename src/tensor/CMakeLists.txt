# Add sources
set(tensor_sources_list
	Shape.cpp
	Shape.h
	Tensor.h
	TensorArray.h
)

# Add Library
add_library(tensor ${tensor_sources_list})

target_include_directories (tensor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(operators)