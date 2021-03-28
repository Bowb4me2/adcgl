# Add sources
set(swing_tensor_sources_list
	
	"Shape.cpp"
	"Shape.h"
	"Tensor.cpp"
	"Tensor.h"
	"TensorArray.h"
	"TensorStorage.cpp"
	"TensorStorage.h"
	"TensorData.h"
	
)

# Add Library
add_library("swing_tensor" ${swing_tensor_sources_list})

target_include_directories ("swing_tensor" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("operator")

# Link libraries
target_link_libraries("swing_tensor" LINK_PUBLIC  "swing_tensor_operator")
