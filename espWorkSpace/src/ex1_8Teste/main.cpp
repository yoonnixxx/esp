#include <Arduino.h>
#include "motor.h"

#define motorA 1
#define motorB 2
const unsigned int PWM1 = 26;
const unsigned int AIN1 = 13;
const unsigned int AIN2 = 14;
const unsigned int STBY = 33;
const unsigned int PWM2 = 25;
const unsigned int BIN1 = 12;
const unsigned int BIN2 = 17;

// Definindo propriedades sinal PWM ESP
const unsigned int freq = 500;
const unsigned int pwmChannel_A = 0;
const unsigned int pwmChannel_B = 0;
const unsigned int resolution = 8;

void setup()
{
    Serial.begin(115200);
    Motor motor1(AIN1, AIN2, PWM1, pwmChannel_A, resolution, freq);
    Motor motor2(BIN1, BIN2, PWM2, pwmChannel_B, resolution, freq);

    pinMode(STBY, OUTPUT);
    digitalWrite(STBY, HIGH);
}

void loop()
{
    // A ideia é aumentar a velocidade aos poucos nos dois motores e depois mudar sentido
    for (int vel = 0; vel <= 255; vel++)
    {
        motor1.drive2(motorA, vel, pwmChannel_A, 1);

        motor2.drive1(vel, pwmChannel_B, BIN1, BIN2);
    }

    motor1.stop(pwmChannel_A);
    motor2.stop(pwmChannel_B);
    delay(1000);

    for (int vel = 0; vel <= 255; vel++)
    {
        motor1.drive2(motorA, vel, pwmChannel_A, 2);

        motor2.drive1(vel, pwmChannel_B, BIN2, BIN1);
    }

    motor1.stop(pwmChannel_A);
    motor2.stop(pwmChannel_B);
    delay(1000);
}
