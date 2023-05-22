//
// Created by vl0011 on 23. 5. 23.
//

#ifndef DRIVER_BUTTON_IO_H
#define DRIVER_BUTTON_IO_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <functional>

#define __FORWARD 0
#define __REVERSE 1

class Button {
private:

    int forward_button_gpio_pin;
    int reverse_button_gpio_pin;

    std::function<void()> callbacks[2];

    void rcb() {

    }

    // callback table
    // GPIO -> callback
    static std::unordered_map<int, std::function<void()>> cb_table;

    static void callback(uint gpio, uint32_t events) {
        auto b = new Button;
        auto z = &(b->rcb);
    }




public:
    Button* NewButton();
};



#endif //DRIVER_BUTTON_IO_H
