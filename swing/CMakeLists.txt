# Add sources
set(swing_sources_list
	"swing.cpp"
	"swing.h"
)

#Add library
add_library("swing" ${swing_sources_list})

target_include_directories ("swing" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("common")
add_subdirectory("graph")
add_subdirectory("tensor")



target_link_libraries("swing" LINK_PUBLIC
	"swing_common"
	"swing_graph" 
	"swing_tensor"
)