add_subdirectory(modules)

add_executable(main main.cpp)

target_link_libraries(main pico_stdlib)
target_link_libraries(main log)

target_link_libraries(main bootstrap motor_io button_io)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)



# create map/bin/hex file etc.
pico_add_extra_outputs(main)
