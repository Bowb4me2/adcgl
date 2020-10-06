add_executable(tensor_array_test tensor_array_test.cpp)
target_link_libraries(tensor_array_test swing)

add_executable(brodcast_test brodcast_test.cpp)
target_link_libraries(brodcast_test swing)

add_executable(node_test node_test.cpp)
target_link_libraries(node_test swing)

add_executable(node_test_2 node_test_2.cpp)
target_link_libraries(node_test_2 swing)

add_executable(differentiation_test differentiation_test.cpp)
target_link_libraries(differentiation_test swing)