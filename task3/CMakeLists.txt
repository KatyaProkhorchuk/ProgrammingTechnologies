cmake_minimum_required(VERSION 3.0)
project(SimpleLibrary)

include_directories(include)
# set(TOOLCHAIN /usr/local/arm/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin)
if(ARM_BUILD)
    set(CMAKE_SYSTEM_PROCESSOR aarch64)
    set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
    install(FILES ${SimpleLibrary_SOURCE_DIR}/include/buffer.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
    set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif(ARM_BUILD)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

if(ARM_BUILD)
    install(TARGETS Main MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
endif(ARM_BUILD)