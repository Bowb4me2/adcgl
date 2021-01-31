# Add sources
set(swing_graph_node_sources_list
	"Node.cpp"
	"Node.h"
	"NodeArray.cpp"
	"NodeArray.h"
)

# Add library
add_library("swing_graph_node" ${swing_graph_node_sources_list})

target_include_directories ("swing_graph_node" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("placeholder")
add_subdirectory("sink")
add_subdirectory("source")

target_link_libraries("swing_graph_node" LINK_PUBLIC 
	"swing_graph_node_placeholder" 
	"swing_graph_node_sink" 
	"swing_graph_node_source"
)