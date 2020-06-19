# Add sources
set(src_sources_list
	adcgl.cpp
	adcgl.h
)

#Add library
add_library(src ${src_sources_list})

target_include_directories (src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory(graph)
add_subdirectory(tensor)

target_link_libraries(src LINK_PUBLIC graph)
target_link_libraries(src LINK_PUBLIC tensor)