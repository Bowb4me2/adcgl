# Add sources
set(host_sources_list
	"HTensor.h"
	"temp.cpp"
)

# Add Library
add_library("host" ${host_sources_list})

target_include_directories ("host" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("operators")

# Link libraries
target_link_libraries("host" LINK_PUBLIC "tensor_operators")