#pragma once 
#include <Arduino.h>

class motor {
private:
    int PWM;
    int AIN1;
    int AIN2;
    int pwmChannel;
    int resolution;

public:
    void motor(int IN1pin, int IN2pin, int PWMpin, int pwmChannel, int resolution);
    void drive1(int motor, int velocidade, int pwmChannel);
    void drive2(int motor, int velocidade, int pwmChannel);
    void stop(int motor, int pwmChannel);
}

