cmake_minimum_required(VERSION 3.16)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
#include(pico_extras_import_optional.cmake)

project(driver C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_subdirectory(lib/log)
add_subdirectory(main)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )