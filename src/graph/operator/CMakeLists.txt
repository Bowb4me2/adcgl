set(graph_operator_sources_list
	"Add.cpp"
	"Add.h"
	"Div.cpp"
	"Div.h"
	"Mul.cpp"
	"Mul.h"
	"Operator.cpp"
	"Operator.h"
	"Sub.cpp"
	"Sub.h"
)

# Add library
add_library("graph_operator" ${graph_operator_sources_list})

target_include_directories ("graph_operator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})