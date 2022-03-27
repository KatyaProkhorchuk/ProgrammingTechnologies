cmake_minimum_required(VERSION 3.0)

option(ARM_BUILD "")
option(TOOLCHAIN "" DAFAULT)
option(CMAKE_INSTALL_PREFIX "" DAFAULT)

if(${ARM_BUILD})
    set(CMAKE_SYSTEM_PROCESSOR aarch64)
    set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
endif()

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

project(SimpleLibrary)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

set_target_properties(buffer PROPERTIES PUBLIC_HEADER "buffer.h")
set_target_properties(MainLib PROPERTIES INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
target_link_libraries(MainLib buffer)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX})

install(TARGETS Main MainLib RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
