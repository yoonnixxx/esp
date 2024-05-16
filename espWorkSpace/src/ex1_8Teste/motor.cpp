#include "motor.h"

void motor::motor(int IN1pin, int IN2pin, int PWMpin, int pwmChannel, int resolution)
{

}

// Função para mover os motores
void motor::drive1(int motor, int velocidade, int pwmChannel)
{
  // usa variavel pro sentido

}

void motor::drive2(int motor, int velocidade, int pwmChannel)
{
  // usa 1 ou - 1 pro sentido 
}

// Função para parar os motores
void motor::stop(int motor, int pwmChannel)
{
  ledcWrite(pwmChannel, 0);
}
