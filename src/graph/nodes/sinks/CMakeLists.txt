# Add sources
set(sinks_sources_list
	"Sink.cpp"
	"Sink.h"
)

# Add library
add_library("sinks" ${sinks_sources_list})

target_include_directories ("sinks" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})