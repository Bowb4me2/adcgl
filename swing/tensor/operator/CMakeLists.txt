# Add sources
set(swing_tensor_operator_sources_list
	"Operator.cpp"
	"Operator.h"
)

# Add Library
add_library("swing_tensor_operator" ${swing_tensor_operator_sources_list})

target_include_directories ("swing_tensor_operator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("elementwise")
add_subdirectory("matrix")

# Link libraries
target_link_libraries("swing_tensor_operator" LINK_PUBLIC 
	"swing_tensor_operator_elementwise"
	"swing_tensor_operator_matrix"
)