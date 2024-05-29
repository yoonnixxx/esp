#include <Arduino.h>

// Declaração pinos digitais da ponte-h
const unsigned int PWM1 = 32;
const unsigned int AIN2 = 33;
const unsigned int AIN1 = 25;
const unsigned int STBY = 26;
const unsigned int BIN1 = 27;
const unsigned int BIN2 = 14;
const unsigned int PWM2 = 13;

// Definindo propriedades sinal PWM ESP
const unsigned int freq = 500;
const unsigned int pwmChannel_A = 0;
const unsigned int pwmChannel_B = 0;
const unsigned int resolution = 8;

void setup()
{
  Serial.begin(115200);
  pinMode(PWM1, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWM2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);

  // Configura funcionalidades LED PWM
  ledcSetup(pwmChannel_A, freq, resolution);
  ledcSetup(pwmChannel_B, freq, resolution);

  // anexa o canal ao GPIO a ser controlado
  ledcAttachPin(PWM1, pwmChannel_A);
  ledcAttachPin(PWM2, pwmChannel_B);
  digitalWrite(STBY, HIGH);
}

//void Drive(int vel, ){}

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
  Serial.println(vel);
  delay(100);
  }
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  ledcWrite(pwmChannel_A, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmChannel_B, 0);
  delay(100);

  for (int vel = 0; vel <= 255; vel ++)
  {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  ledcWrite(pwmChannel_A, vel);
  // define o sentido pelos pinos BIN1 e BIN2 e a velocidade pelo PWM2
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(pwmChannel_B, vel);
  Serial.println(vel);
  delay(100);
  }

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  ledcWrite(pwmChannel_A, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmChannel_B, 0);
  delay(100);
}


    // Pinos
/*
    const unsigned int motorA1 = 13;
const unsigned int motorA2 = 14;
const unsigned int PWM_A = 26;

const unsigned int motorB1 = 12;
const unsigned int motorB2 = 17;
const unsigned int PWM_B = 25;

const unsigned int PWM_A_Chan = 0;   // canal de PWM 1 - 16 disponíveis
const unsigned int PWM_A_Freq = 500; // Frequência
const unsigned int PWM_A_Res = 8;    // Resolução 1 - 16 bits | 8 bits = valores de 0-255

const unsigned int PWM_B_Chan = 0;
const unsigned int PWM_B_Freq = 500;
const unsigned int PWM_B_Res = 8;

void moveFrente(int vel)
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);
}

void moveTras(int vel)
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);
}

void movedireita(int vel)
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);
}

void moveesquerda(int vel)
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);
}

void parar()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  ledcWrite(PWM_A_Chan, 0);
  ledcWrite(PWM_B_Chan, 0);
}

void setup()
{

  Serial.begin(9600); // Certifique-se que seu Serial Monitor também está nesse baud rate.
                      // Nome do dispositivo

  pinMode(motorA1, OUTPUT); // Definição de cada tipo dos pins
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  ledcSetup(PWM_A_Chan, PWM_A_Freq, PWM_A_Res); // configurando o PWM
  ledcSetup(PWM_B_Chan, PWM_B_Freq, PWM_B_Res);

  ledcAttachPin(PWM_A, PWM_A_Chan); // Linkando o  canal para os pinos
  ledcAttachPin(PWM_B, PWM_B_Chan);
}

void loop()
{
  moveFrente(255);
  delay(2000);
  moveTras(255);
  delay(2000);
}
*/
// digitalWrite(motorA1, HIGH);
// digitalWrite(motorA2, LOW);
// digitalWrite(motorB1, HIGH);
// digitalWrite(motorB2, LOW);
// ledcWrite(PWM_A_Chan, 255);
// ledcWrite(PWM_B_Chan, 255);
