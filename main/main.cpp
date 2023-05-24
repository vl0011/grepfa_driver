#include <iostream>
#include <log.h>
#include <bootstrap.h>
#include <motor_io.h>
#include <sw_xway.h>
#include "pico/stdlib.h"

void cb(uint gpio, uint32_t event_mask) {
    log_info("%d: hello", gpio);
}

int main() {

    stdio_init_all();

    log_set_level(0);

    auto b1 = Button::NewButton(2, 3, &cb, &cb);

    log_info("program start...");

    auto m1 = Motor::NewMotor(0, 18, 19);

    while(true) {
        m1->do_forward();
        sleep_ms(10000);
        m1->do_reverse();
        sleep_ms(10000);
        m1->motor_stop();
        sleep_ms(10000);
    }

    return 0;
}
