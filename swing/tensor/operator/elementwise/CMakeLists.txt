# Add sources
set(swing_tensor_operator_elementwise_sources_list
	"Add.cpp"
	"Add.h"
	"Div.cpp"
	"Div.h"
	"Mul.cpp"
	"Mul.h"
	"Sub.cpp"
	"Sub.h"
	"Sum.cpp"
	"Sum.h"
	"Square.cpp"
	"Square.h"
)

# Add Library
add_library("swing_tensor_operator_elementwise" ${swing_tensor_operator_elementwise_sources_list})

target_include_directories ("swing_tensor_operator_elementwise" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
