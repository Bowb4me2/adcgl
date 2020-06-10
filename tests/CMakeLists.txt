
#file(GLOB src_files
#	"*.h"
#	"*.cpp"
#)

#add_library(tests ${src_files})

add_executable(adcgl_exe main.cpp)

target_link_libraries(adcgl_exe src)