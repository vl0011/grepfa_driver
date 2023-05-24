//
// Created by vl0011 on 23. 5. 23.
//

#ifndef DRIVER_SW_XWAY_H
#define DRIVER_SW_XWAY_H

#include <functional>

#include "pico.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "gpio_IRQ.h"

class Button {
private:

    int forward_button_gpio_pin;
    int reverse_button_gpio_pin;

    gpio_irq_callback_t forward_button_cb;
    gpio_irq_callback_t reverse_button_cb;


public:
    static Button *NewButton(int forward, int reverse, gpio_irq_callback_t forward_cb, gpio_irq_callback_t reverse_cb);
};

/*
    GPIO_IRQ_LEVEL_LOW = 0x1u,
    GPIO_IRQ_LEVEL_HIGH = 0x2u,
    GPIO_IRQ_EDGE_FALL = 0x4u,
    GPIO_IRQ_EDGE_RISE = 0x8u,
 */


typedef void (*sw_cb_t)();

class SwEv {
private:
    int gpio;
    uint32_t ev_mask;
    std::function<void()> cb;
};

class SwSPST {

private:

    static void handler(uint gpio, uint32_t ev) {

    }

    static std::unordered_map<int, SwEv> cb_table;

    int sw_gpio;    // throw gpio

    sw_cb_t on_cb = nullptr;
    sw_cb_t off_cb = nullptr;

    gpio_irq_callback_t toggle_on_cb;    // ◉○
    gpio_irq_callback_t toggle_off_cb;   // ○◉

    void toc(uint gpio, uint32_t ev);

    int current = 0;

public:
    static SwSPST *NewSw(int gpio, gpio_irq_callback_t on_callback, gpio_irq_callback_t off_callback);
};

class SwSPDT {
private:
    int sw_forward_gpio;
    int sw_reverse_gpio;

    gpio_irq_callback_t toggle_forward_cb;
    gpio_irq_callback_t toggle_reverse_cb;
    gpio_irq_callback_t toggle_stop_cb;

public:

    static SwSPST *NewSw(
            int forward_gpio, int reverse_gpio,
            gpio_irq_callback_t forward_callback,
            gpio_irq_callback_t reverse_callback,
            gpio_irq_callback_t stop_callback
    );
};


#endif //DRIVER_SW_XWAY_H
