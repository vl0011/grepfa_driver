//
// Created by vl0011 on 23. 5. 23.
//

#ifndef DRIVER_MOTOR_IO_H
#define DRIVER_MOTOR_IO_H

#include "motor_status.h"
#include "pico/stdlib.h"
#include <log.h>

class Motor{
private:

    MotorStatus status;

    // 정방향 모터 GPIO PIN
    int forward_motor_gpio_pin;

    // 역방향 모터 GPIO PIN
    int reverse_motor_gpio_pin;

    // STATUS -> 모터 제어
    void sync_motor();

    // 모터 번호
    int no;

public:

    /**
     *
     * @param forward - 정방향 GPIO
     * @param reverse - 역방향 GPIO
     */
    static Motor* NewMotor(int motor_no, int forward, int reverse);

    /**
     * 정방향 모터 출력
     */
    void do_forward();

    /**
     * 역방향 모터 출력
     */
    void do_reverse();

    /**
     * 모터 정지
     */
    void motor_stop();

    ~Motor()= default;
};



#endif //DRIVER_MOTOR_IO_H
