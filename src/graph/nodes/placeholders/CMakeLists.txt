# Add sources
set(placeholders_sources_list
	"Placeholder.cpp"
	"Placeholder.h"
)

# Add library
add_library("placeholders" ${placeholders_sources_list})

target_include_directories ("placeholders" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
