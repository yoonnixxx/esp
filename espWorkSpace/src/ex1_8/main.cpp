#include <Arduino.h>

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


void setup()
{
    pinMode(PWM1, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    pinMode(PWM2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);

    // Configura funcionalidades LED PWM
    ledcSetup(pwmChannel_A, freq, resolution);
    ledcSetup(pwmChannel_B, freq, resolution);

    // anexa o canal ao GPIO a ser controlado
    ledcAttachPin(PWM1, pwmChannel_A);
    ledcAttachPin(PWM2, pwmChannel_B);
}

void loop()
{
    // A ideia é aumentar a velocidade aos poucos nos dois motores e depois mudar sentido
    for (int vel = 0; vel <= 255; vel++)
    {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        ledcWrite(pwmChannel_A, vel);

        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
        ledcWrite(pwmChannel_B, vel);
    }

    ledcWrite(pwmChannel_A, 0);
    ledcWrite(pwmChannel_B, 0);
    delay(1000);

    for (int vel = 0; vel <= 255; vel++)
    {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        ledcWrite(pwmChannel_A, vel);
        // define o sentido pelos pinos BIN1 e BIN2 e a velocidade pelo PWM2
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        ledcWrite(pwmChannel_B, vel);
    }

    ledcWrite(pwmChannel_A, 0);
    ledcWrite(pwmChannel_B, 0);
    delay(1000);
}
