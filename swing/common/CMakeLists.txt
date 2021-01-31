set(swing_common_sources_list	
	"common.cpp"
	"common.h"
	"exception.h"
	"RefArray.h"
)

#Add library
add_library("swing_common" ${swing_common_sources_list})

target_include_directories ("swing_common" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories

# target links