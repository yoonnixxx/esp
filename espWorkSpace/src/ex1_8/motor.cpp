#include "motor.h"

#define PWM1 32
#define AIN1 25
#define AIN2 26
#define PWM2 33
#define BIN1 27
#define BIN2 14

#define motorA 1 
#define motorB 2 

// Função para mover os motores para frente
void foward(int motor, int velocidade, int pwmChannel_A, int pwmChannel_B)
{
  if (motor == 1)
  {
    //define o sentido pelos pinos AIN1 e AIN2 e a velocidade pelo PWM1
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW); 

    ledcWrite(pwmChannel_A, velocidade); 
  }
  else
  {
    //define o sentido pelos pinos BIN1 e BIN2 e a velocidade pelo PWM2
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW); 

    ledcWrite(pwmChannel_B, velocidade); 
  }
}

// Função para mover os motores para trás
void reverse(int motor, int velocidade, int pwmChannel_A, int pwmChannel_B)
{
  if (motor == 1)
  {
    //define o sentido pelos pinos AIN1 e AIN2 e a velocidade pelo PWM1
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH); 

    ledcWrite(pwmChannel_A, velocidade); 
  }
  else
  {
    //define o sentido pelos pinos BIN1 e BIN2 e a velocidade pelo PWM2
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH); 

    ledcWrite(pwmChannel_B, velocidade); 
  }
}

// Função para parar os motores
void stop(int motor, int pwmChannel_A, int pwmChannel_B)
{
    if (motor == 1)
  {
    ledcWrite(pwmChannel_A, 0); 
  }
  else
  {
    ledcWrite(pwmChannel_B, 0); 
  }
}
