set(swing_graph_operator_matrix_sources_list
	"Dot.cpp"
	"Dot.h"
	"Outer.cpp"
	"Outer.h"
)

# Add library
add_library("swing_graph_operator_matrix" ${swing_graph_operator_matrix_sources_list})

target_include_directories ("swing_graph_operator_matrix" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})