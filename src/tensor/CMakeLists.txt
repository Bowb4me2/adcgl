# Add sources
set(tensor_sources_list
	Shape.cpp
	Shape.h
	Tensor.h
	TensorArray.h
)

# Add Library
add_library(tensor ${tensor_sources_list})

target_include_directories (tensor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} host)

# Add subdirectories
add_subdirectory(host)

# Link libraries
target_link_libraries(tensor LINK_PUBLIC host)
