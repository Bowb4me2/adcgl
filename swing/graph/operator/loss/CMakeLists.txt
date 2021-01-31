set(swing_graph_operator_loss_sources_list
	"MSE.cpp"
	"MSE.h"
)

# Add library
add_library("swing_graph_operator_loss" ${swing_graph_operator_loss_sources_list})

target_include_directories ("swing_graph_operator_loss" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})