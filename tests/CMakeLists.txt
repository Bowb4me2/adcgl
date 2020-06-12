
#file(GLOB src_files
#	"*.h"
#	"*.cpp"
#)

#add_library(tests ${src_files})

add_executable(tensor_array_test tensor_array_test.cpp)
target_link_libraries(tensor_array_test src)

add_executable(brodcast_test brodcast_test.cpp)
target_link_libraries(brodcast_test src)

