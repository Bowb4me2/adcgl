set(operators_sources_list
	"Add.cpp"
	"Add.h"
	#"Div.cpp"
	#"Div.h"
	#"Mul.cpp"
	#"Mul.h"
	"Operator.cpp"
	"Operator.h"
	#"Sub.cpp"
	#"Sub.h"
)

# Add library
add_library("operators" ${operators_sources_list})

target_include_directories ("operators" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})