# Add sources
set(graph_node_sources_list
	"Node.cpp"
	"Node.h"
	"NodeArray.cpp"
	"NodeArray.h"
)

# Add library
add_library("graph_node" ${graph_node_sources_list})

target_include_directories ("graph_node" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("placeholder")
add_subdirectory("sink")
add_subdirectory("source")

target_link_libraries("graph_node" LINK_PUBLIC "graph_node_placeholder" "graph_node_sink" "graph_node_source")