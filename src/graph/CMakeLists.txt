# Add sources
set(graph_sources_list
	"DCGraph.cpp"
	"DCGraph.h"
	"GraphBuilder.cpp"
	"GraphBuilder.h"
)

# Add library
add_library("graph" ${graph_sources_list})

target_include_directories ("graph" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("node")
add_subdirectory("operator")

target_link_libraries("graph" LINK_PUBLIC 
	"graph_node" 
	"graph_operator"
)