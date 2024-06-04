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

void stop ();
void forward(int vel);
void backwards(int vel);

void setup()
{
  Serial.begin(115200);
  // definindo os pinos
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
    foward(vel);
  }
  
  stop();

  for (int vel = 0; vel <= 255; vel ++)
  {
    backwards(vel);
  }

  stop();
}


 void foward(int vel){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  ledcWrite(pwmChannel_A, vel);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  ledcWrite(pwmChannel_B, vel);
  Serial.println(vel);
  delay(100);
 } 

 void stop (){ // para o motor
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    ledcWrite(pwmChannel_A, 0);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    ledcWrite(pwmChannel_B, 0);
    delay(100);
}
void backwards(int vel){
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