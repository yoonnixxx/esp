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

void setup() 
{
  // Inicialização e configuração dos pinos
  pinMode(PWM1,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);

  pinMode(PWM2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

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
  for(int vel = 0; vel<=255; vel++)
  {
    foward(motorA, vel, pwmChannel_A, pwmChannel_B);
    foward(motorB, vel, pwmChannel_A, pwmChannel_B);
    delay(500); 
  }

  stop(motorA, pwmChannel_A, pwmChannel_B);
  stop(motorB, pwmChannel_A, pwmChannel_B);
  delay(1000);

  for(int vel = 0; vel<=255; vel++)
  {
    reverse(motorA, vel, pwmChannel_A, pwmChannel_B);
    reverse(motorB, vel, pwmChannel_A, pwmChannel_B);
    delay(500); 
  }
  stop(motorA, pwmChannel_A, pwmChannel_B);
  stop(motorB, pwmChannel_A, pwmChannel_B);
  delay(1000); 

}
