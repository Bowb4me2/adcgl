set(graph_operator_loss_sources_list
	"MSE.cpp"
	"MSE.h"
)

# Add library
add_library("graph_operator_loss" ${graph_operator_loss_sources_list})

target_include_directories ("graph_operator_loss" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})