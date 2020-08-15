# Add sources
set(cpu_operators_sources_list
	"elementwise_ops.cpp"
	"elementwise_ops.h"
	"matrix_ops.cpp"
	"matrix_ops.h"
	"operators.h"
)

# Add Library
add_library("cpu_tensor_operators" ${cpu_operators_sources_list})

target_include_directories ("cpu_tensor_operators" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})