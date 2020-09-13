# Add sources
set(tensor_operator_sources_list
	"Operator.cpp"
	"Operator.h"
)

# Add Library
add_library("tensor_operator" ${tensor_operator_sources_list})

target_include_directories ("tensor_operator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("elementwise")
add_subdirectory("matrix")

# Link libraries
target_link_libraries("tensor_operator" LINK_PUBLIC 
	"tensor_operator_elementwise"
	"tensor_operator_matrix"
)