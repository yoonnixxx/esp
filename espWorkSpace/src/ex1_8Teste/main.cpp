#include <Arduino.h>
#include "motor.h"

// Declaração pinos digitais da ponte-h
#define PWM1 32
#define AIN1 25
#define AIN2 26
#define PWM2 33
#define BIN1 27
#define BIN2 14

#define motorA 1
#define motorB 2

// Definindo propriedades sinal PWM ESP
const int freq = 30000;
const int pwmChannel_A = 0;
const int pwmChannel_B = 1;
const int resolution = 8;

Motor motor1 (AIN1, AIN2, PWM1, pwmChannel_A, resolution, freq);
Motor motor2 (BIN1, BIN2, PWM2, pwmChannel_B, resolution, freq);

void setup()
{

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
