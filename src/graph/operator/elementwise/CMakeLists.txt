set(graph_operator_elementwise_sources_list
	"Add.cpp"
	"Add.h"
	"Div.cpp"
	"Div.h"
	"Mul.cpp"
	"Mul.h"
	"Sub.cpp"
	"Sub.h"
)

# Add library
add_library("graph_operator_elementwise" ${graph_operator_elementwise_sources_list})

target_include_directories ("graph_operator_elementwise" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})