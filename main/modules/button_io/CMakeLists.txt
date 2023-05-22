set(LIBRARY_NAME button_io)

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

target_link_libraries(${LIBRARY_NAME} pico_stdlib log)

message("${LIBRARY_NAME} imported")