catkin_add_gtest(test_dataLoggerProcess test_DataLoggerProcess.cpp)
target_link_libraries(test_dataLoggerProcess ${catkin_LIBRARIES} ${Boost_LIBRARIES} logger dataLoggerProcess)
add_dependencies(test_dataLoggerProcess eros_generate_messages_cpp)
