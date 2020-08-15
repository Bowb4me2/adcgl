# Add sources
set(elementwise_operators_sources_list
	"Add.cpp"
	"Add.h"
	"Div.cpp"
	"Div.h"
	"Mul.cpp"
	"Mul.h"
	"Sub.cpp"
	"Sub.h"
)

# Add Library
add_library("elementwise_operators" ${operators_sources_list})

target_include_directories ("elementwise_operators" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
