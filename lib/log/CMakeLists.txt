set(LIBRARY_NAME log)

add_library(
        ${LIBRARY_NAME}
        STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/log/src/log.c
)

target_include_directories(
        ${LIBRARY_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/log
)

target_compile_options(${LIBRARY_NAME} PRIVATE -Wall -Werror)

message("log library imported")