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
add_subdirectory("nodes")

target_link_libraries("graph" LINK_PUBLIC "nodes")