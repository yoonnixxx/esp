#pragma once 
#include <Arduino.h>

class Motor {
private:
    int PWM;
    int IN1;
    int IN2;
    int pwmChannel;
    int resolution;
    int freq;

public:
    Motor(int IN1pin, int IN2pin, int PWMpin, int pwmChannell, int resolutionn, int frequencia);
    void drive1(int velocidade, int pwmChannel, int INa, int INb);
    void drive2(int motor, int velocidade, int pwmChannel, int sentido);
    void stop(int pwmChannel);
};