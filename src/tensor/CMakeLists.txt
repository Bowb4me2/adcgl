# Add sources
set(tensor_sources_list
	
	"Shape.cpp"
	"Shape.h"
	"Tensor.h"
	"TensorArray.h"
)

# Add Library
add_library("tensor" ${tensor_sources_list})

target_include_directories ("tensor" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("device")
add_subdirectory("operator")

# Link libraries
target_link_libraries("tensor" LINK_PUBLIC "tensor_device" "tensor_operator")
