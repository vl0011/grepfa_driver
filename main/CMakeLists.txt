add_executable(main main.cpp)

target_link_libraries(main pico_stdlib)
target_link_libraries(main log)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)



# create map/bin/hex file etc.
pico_add_extra_outputs(main)
