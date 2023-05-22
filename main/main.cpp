#include <iostream>
#include <log.h>
#include <bootstrap.h>
#include <motor_io.h>
#include "pico/stdlib.h"

int main() {

    stdio_init_all();

    log_set_level(0);

    log_info("program start...");

    auto m1 = Motor::NewMotor(0, 18, 19);

    while(true) {
        m1->do_forward();
        sleep_ms(1000);
        m1->do_reverse();
        sleep_ms(1000);
        m1->motor_stop();
        sleep_ms(1000);
    }

    return 0;
}
