# library

add_library(src adcgl.cpp adcgl.h)

target_include_directories (src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Add subdirectories
#add_subdirectory(graph)
add_subdirectory(tensor)

#target_link_libraries(src LINK_PUBLIC graph)
target_link_libraries(src LINK_PUBLIC tensor)