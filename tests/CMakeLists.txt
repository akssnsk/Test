cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-std=gnu++11 -g -ggdb") 

set(TASKS_TO_TEST task.cpp)
set(UNIT_TESTS test.cpp)
set(SRC_DIR ..)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(.)

include_directories(${SRC_DIR}/task)
add_library(tasksToTest ${SRC_DIR}/task/task.cpp ${SRC_DIR}/task/Node.cpp)

add_executable(runTests ${UNIT_TESTS})
target_link_libraries(runTests gtest gtest_main rt pthread tasksToTest)

