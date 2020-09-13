set(graph_operator_sources_list
	"Operator.cpp"
	"Operator.h"
)

# Add library
add_library("graph_operator" ${graph_operator_sources_list})

target_include_directories ("graph_operator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("elementwise")
add_subdirectory("matrix")


target_link_libraries("graph_operator" LINK_PUBLIC 
	"graph_operator_elementwise" 
	"graph_operator_matrix"
)