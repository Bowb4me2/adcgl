# Add sources
set(tensor_operator_sources_list
	"tensor_operators.cpp"
	"tensor_operators.h"
	"Operator.cpp"
	"Operator.h"
)

# Add Library
add_library("tensor_operator" ${tensor_operator_sources_list})

target_include_directories ("tensor_operator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("elementwise")

# Link libraries
target_link_libraries("tensor_operator" LINK_PUBLIC 
	"tensor_operator_elementwise"
)