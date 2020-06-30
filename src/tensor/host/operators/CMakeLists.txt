# Add sources
set(operators_sources_list
	"elementwise_ops.cpp"
	"elementwise_ops.h"
	"operators.h"
)

# Add Library
add_library("tensor_operators" ${operators_sources_list})

target_include_directories ("tensor_operators" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})