# Add sources
set(tensor_device_sources_list
	"Device.cpp"
	"Device.h"
)

# Add Library
add_library("tensor_device" ${tensor_device_sources_list})

target_include_directories ("tensor_device" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})