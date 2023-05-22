#include <iostream>
#include <log.h>
#include "pico/stdlib.h"

int main() {

    stdio_init_all();

    log_set_level(0);

    log_info("program start...");

    while(true) {
        log_info("11111");
        sleep_ms(1000);
    }

    return 0;
}
