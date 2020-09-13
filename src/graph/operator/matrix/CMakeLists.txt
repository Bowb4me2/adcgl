set(graph_operator_matrix_sources_list
	"Outer.cpp"
	"Outer.h"
)

# Add library
add_library("graph_operator_matrix" ${graph_operator_matrix_sources_list})

target_include_directories ("graph_operator_matrix" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})