# Add sources
set(tensor_operator_sources_list
	"tensor_operators.cpp"
	"tensor_operators.h"
	"TensorOperator.cpp"
	"TensorOperator.h"
)

# Add Library
add_library("tensor_operator" ${tensor_operator_sources_list})

target_include_directories ("tensor_operator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("cpu")

# Link libraries
target_link_libraries("tensor_operator" LINK_PUBLIC "cpu_tensor_operators")