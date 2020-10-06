# Add sources
set(graph_node_sink_sources_list
	"Sink.cpp"
	"Sink.h"
)

# Add library
add_library("graph_node_sink" ${graph_node_sink_sources_list})

target_include_directories ("graph_node_sink" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})