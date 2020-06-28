# Add sources
set(sources_sources_list
	"Constant.cpp"
	"Constant.h"
	"Source.cpp"
	"Source.h"
	"Variable.cpp"
	"Variable.h"
)

# Add library
add_library("sources" ${sources_sources_list})

target_include_directories ("sources" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})