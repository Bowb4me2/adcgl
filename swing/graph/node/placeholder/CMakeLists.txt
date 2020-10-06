# Add sources
set(graph_node_placeholder_sources_list
	"Placeholder.cpp"
	"Placeholder.h"
)

# Add library
add_library("graph_node_placeholder" ${graph_node_placeholder_sources_list})

target_include_directories ("graph_node_placeholder" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
