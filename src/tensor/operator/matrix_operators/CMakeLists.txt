# Add sources
set(matrix_operators_sources_list

)

# Add Library
add_library("matrix_operators" ${operators_sources_list})

target_include_directories ("matrix_operators" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
