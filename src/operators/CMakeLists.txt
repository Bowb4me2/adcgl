set(operators_sources_list
	"Operator.cpp"
	"Operator.h"
)

# Add library
add_library("node_operators" ${operators_sources_list})

target_include_directories ("node_operators" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})