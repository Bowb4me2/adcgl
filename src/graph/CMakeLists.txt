# Add sources
set(graph_sources_list
	DCGraph.cpp
	DCGraph.h
)

add_library(graph ${graph_sources_list})

target_include_directories (graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})