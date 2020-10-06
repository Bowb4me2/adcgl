# Add sources
set(graph_node_source_sources_list
	"Constant.cpp"
	"Constant.h"
	"Source.cpp"
	"Source.h"
	"Variable.cpp"
	"Variable.h"
)

# Add library
add_library("graph_node_source" ${graph_node_source_sources_list})

target_include_directories ("graph_node_source" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})