#include "motor_io.h"

void Motor::sync_motor() {
    if(status == MotorStatus::STOP) {
        gpio_put(forward_motor_gpio_pin, false);
        gpio_put(reverse_motor_gpio_pin, false);
        log_info("Motor '%d' set STOP", no);
    } else if (status == MotorStatus::FORWARD) {
        gpio_put(reverse_motor_gpio_pin, false);
        sleep_ms(10);
        gpio_put(forward_motor_gpio_pin, true);
        log_info("Motor '%d' set FORWARD", no);
    } else if (status == MotorStatus::REVERSE) {
        gpio_put(forward_motor_gpio_pin, false);
        sleep_ms(10);
        gpio_put(reverse_motor_gpio_pin, true);
        log_info("Motor '%d' set REVERSE", no);
    }
}

void Motor::do_forward() {
    status =MotorStatus::FORWARD;
    sync_motor();
}

void Motor::do_reverse() {
    status =MotorStatus::REVERSE;
    sync_motor();
}

void Motor::motor_stop() {
    status =MotorStatus::STOP;
    sync_motor();
}

Motor *Motor::NewMotor(int motor_no, int forward, int reverse) {
    gpio_init(forward);
    gpio_init(reverse);

    gpio_set_dir(forward, GPIO_OUT);
    gpio_set_dir(reverse, GPIO_OUT);

    gpio_put(forward, false);
    gpio_put(reverse, false);

    auto ret = new Motor();
    ret->forward_motor_gpio_pin = forward;
    ret->reverse_motor_gpio_pin = reverse;
    ret->no = motor_no;

    ret->status = MotorStatus::STOP;

    log_info("Motor '%d' defined", motor_no);

    return ret;
}

