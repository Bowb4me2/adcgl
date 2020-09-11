# Add sources
set(tensor_operator_matrix_sources_list
	"Dot.cpp"
	"Dot.h"
	"Outer.cpp"
	"Outer.h"
)

# Add Library
add_library("tensor_operator_matrix" ${tensor_operator_matrix_sources_list})

target_include_directories ("tensor_operator_matrix" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
