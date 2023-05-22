set(LIBRARY_NAME bootstrap)

add_library(
        ${LIBRARY_NAME}
        STATIC
        lib/lib.cpp
)

target_include_directories(
        ${LIBRARY_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

message("bootstrap imported")