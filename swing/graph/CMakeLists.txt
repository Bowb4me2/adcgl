# Add sources
set(swing_graph_sources_list
	"DCGraph.cpp"
	"DCGraph.h"
	"GraphBuilder.cpp"
	"GraphBuilder.h"
)

# Add library
add_library("swing_graph" ${swing_graph_sources_list})

target_include_directories ("swing_graph" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("node")
add_subdirectory("operator")

target_link_libraries("swing_graph" LINK_PUBLIC 
	"swing_graph_node" 
	"swing_graph_operator"
)