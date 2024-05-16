#include "motor.h"


Motor::Motor(int IN1pin, int IN2pin, int PWMpin, int pwmChannell, int resolutionn, int frequencia)
{
  PWM = PWMpin;
  IN1 = IN1pin;
  IN2 = IN2pin;
  pwmChannel = pwmChannell;
  resolution = resolutionn;
  freq = frequencia;

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);

  // anexa o canal ao GPIO a ser controlado
  ledcAttachPin(PWM, pwmChannel);
  // Configura funcionalidades LED PWM
  ledcSetup(pwmChannel, freq, resolution);
}

// Função para mover os motores
void Motor::drive1( int velocidade, int pwmChannel, int INa, int INb)
{
  // usa variavel pro sentido
  digitalWrite(INa, HIGH);
  digitalWrite(INb, LOW); 
  ledcWrite(pwmChannel, velocidade); 

}

void Motor::drive2(int motor, int velocidade, int pwmChannel, int sentido)
{
  // usa 1 ou - 1 pro sentido 
  if (sentido == 1){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    ledcWrite(pwmChannel, velocidade);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    ledcWrite(pwmChannel, velocidade);
  }

}
// Função para parar os motores
void Motor::stop(int pwmChannel)
{
  ledcWrite(pwmChannel, 0);
}
