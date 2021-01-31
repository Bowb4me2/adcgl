set(swing_graph_operator_sources_list
	"MatrixOperator.cpp"
	"MatrixOperator.h"
	"Operator.cpp"
	"Operator.h"
	"ScalarOperator.cpp"
	"ScalarOperator.h"
	"VectorOperator.cpp"
	"VectorOperator.h"
)

# Add library
add_library("swing_graph_operator" ${swing_graph_operator_sources_list})

target_include_directories ("swing_graph_operator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("elementwise")
add_subdirectory("loss")
add_subdirectory("matrix")


target_link_libraries("swing_graph_operator" LINK_PUBLIC 
	"swing_graph_operator_elementwise" 
	"swing_graph_operator_loss"
	"swing_graph_operator_matrix"
)