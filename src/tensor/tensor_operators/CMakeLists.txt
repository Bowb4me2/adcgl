# Add sources
set(operators_sources_list
	"tensor_operators.cpp"
	"tensor_operators.h"
)

# Add Library
add_library("tensor_operators" ${operators_sources_list})

target_include_directories ("tensor_operators" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("cpu")

# Link libraries
target_link_libraries("tensor_operators" LINK_PUBLIC "cpu_tensor_operators")