# Add sources
set(devices_sources_list
	"Device.cpp"
	"Device.h"
)

# Add Library
add_library("devices" ${devices_sources_list})

target_include_directories ("devices" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})