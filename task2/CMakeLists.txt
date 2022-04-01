cmake_minimum_required(VERSION 3.16)
project(TASK2)
find_package(GTest REQUIRED)
add_subdirectory(B ${TASK2_SOURCE_DIR}/lib)
add_executable(main "C/main.cpp" ${PROJECT_SOURCE_DIR}/A/index.h)
add_executable(CTest "C/main_test.cpp" ${PROJECT_SOURCE_DIR}/A/index.h)
target_include_directories(CTest PUBLIC ${TASK2_SOURCE_DIR})
target_include_directories(CTest PUBLIC ${GTEST_INCLUDE_DIRS})
add_custom_command(
    OUTPUT ${TASK2_SOURCE_DIR}/A/index.h
    COMMAND python3 ${TASK2_SOURCE_DIR}/A/preparing.py ${TASK2_SOURCE_DIR}/A
)
set(EXECUTABLE_OUTPUT_PATH ${TASK2_SOURCE_DIR}/bin)
target_link_libraries(main lib)
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread lib)
target_include_directories(main PUBLIC "${CMAKE_LIST_DIR}")
