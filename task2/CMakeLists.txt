cmake_minimum_required(VERSION 3.16)
project(TASK2)
find_package(GTest REQUIRED)
include_directories(A)
add_subdirectory(B ${TASK2_SOURCE_DIR}/lib)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(C)
include_directories(B)
include_directories(${TASK2_SOURCE_DIR})
add_executable(main "C/main.cpp" ${PROJECT_SOURCE_DIR}/A/index.h)
add_executable(CTest "C/main_test.cpp" ${PROJECT_SOURCE_DIR}/A/index.h)
add_custom_command(
    OUTPUT ${TASK2_SOURCE_DIR}/A/index.h
    COMMAND python3 ${TASK2_SOURCE_DIR}/A/preparing.py ${TASK2_SOURCE_DIR}/A
)
set(EXECUTABLE_OUTPUT_PATH ${TASK2_SOURCE_DIR}/bin)
target_link_libraries(main lib)
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread lib)
target_include_directories(main PUBLIC "${CMAKE_LIST_DIR}")