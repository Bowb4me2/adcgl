# Add sources
set(swing_graph_node_placeholder_sources_list
	"Placeholder.cpp"
	"Placeholder.h"
)

# Add library
add_library("swing_graph_node_placeholder" ${swing_graph_node_placeholder_sources_list})

target_include_directories ("swing_graph_node_placeholder" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
