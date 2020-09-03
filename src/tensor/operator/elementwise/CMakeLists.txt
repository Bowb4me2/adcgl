# Add sources
set(tensor_operator_elementwise_sources_list
	"Add.cpp"
	"Add.h"
	"Div.cpp"
	"Div.h"
	"Mul.cpp"
	"Mul.h"
	"Sub.cpp"
	"Sub.h"
)

# Add Library
add_library("tensor_operator_elementwise" ${tensor_operator_elementwise_sources_list})

target_include_directories ("tensor_operator_elementwise" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
