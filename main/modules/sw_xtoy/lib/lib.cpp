#include "sw_xway.h"

Button *Button::NewButton(int forward, int reverse, gpio_irq_callback_t forward_cb, gpio_irq_callback_t reverse_cb) {
    auto ret = new Button();

    ret->forward_button_cb = forward_cb;
    ret->reverse_button_cb = reverse_cb;

    ret->forward_button_gpio_pin = forward;
    ret->reverse_button_gpio_pin = reverse;

    gpio_set_irq_enabled_with_callback(forward, GPIO_IRQ_EDGE_RISE, true, forward_cb);
    gpio_set_irq_enabled_with_callback(reverse, GPIO_IRQ_EDGE_RISE, true, reverse_cb);

    return ret;
}

SwSPST *SwSPST::NewSw(int gpio, gpio_irq_callback_t on_callback, gpio_irq_callback_t off_callback) {

    auto ret = new SwSPST();

    ret->toggle_on_cb = on_callback;
    ret->toggle_off_cb = off_callback;
    ret->sw_gpio = gpio;

    gpio_set_irq_enabled_with_callback(gpio, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL | GPIO_IRQ_LEVEL_HIGH | GPIO_IRQ_LEVEL_LOW,
                                       true, handler);
}

void SwSPST::toc(uint gpio, uint32_t ev) {

}

SwSPST *SwSPDT::NewSw(int forward_gpio, int reverse_gpio, gpio_irq_callback_t forward_callback,
                      gpio_irq_callback_t reverse_callback,
                      gpio_irq_callback_t stop_callback) {

    auto ret = new SwSPDT();

    ret->sw_forward_gpio = forward_gpio;
    ret->sw_reverse_gpio = reverse_gpio;

    ret->toggle_forward_cb = forward_callback;
    ret->toggle_reverse_cb = reverse_callback;
    ret->toggle_stop_cb = stop_callback;

    if (forward_callback != nullptr)
        gpio_set_irq_enabled_with_callback(forward_gpio, GPIO_IRQ_EDGE_RISE, true, ret->toggle_forward_cb);

    return nullptr;
}
