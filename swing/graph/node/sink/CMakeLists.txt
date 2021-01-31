# Add sources
set(swing_graph_node_sink_sources_list
	"Sink.cpp"
	"Sink.h"
)

# Add library
add_library("swing_graph_node_sink" ${swing_graph_node_sink_sources_list})

target_include_directories ("swing_graph_node_sink" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})