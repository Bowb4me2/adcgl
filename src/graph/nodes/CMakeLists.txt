# Add sources
set(nodes_sources_list
	Node.cpp
	Node.h
	NodeArray.cpp
	NodeArray.h
)

# Add library
add_library(nodes ${nodes_sources_list})

target_include_directories (nodes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(placeholders)
add_subdirectory(sinks)
add_subdirectory("sources")