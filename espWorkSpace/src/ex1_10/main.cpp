#include <Arduino.h>
#include "BluetoothSerial.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

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

const unsigned int BUTAO = 2;
const unsigned int POT = 4;
int botao = 0;

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

    pinMode(BUTAO, INPUT_PULLUP);
    pinMode(POT, INPUT_PULLDOWN);

    SerialBT.begin("ESP32test"); // Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
    
    if (Serial.available()){SerialBT.write(Serial.read());}
    if (SerialBT.available()){Serial.write(SerialBT.read());}
    delay(20);

    if (digitalRead(BUTAO) == LOW && botao == 0){botao = 1;}
    else if (digitalRead(BUTAO) == LOW){ botao = 0;}

    vel = analogRead(POT);
    vel= map(vel, 0, 4096, 255, 0);
    if (botao == 1)
    {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        ledcWrite(pwmChannel_A, vel);

        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
        ledcWrite(pwmChannel_B, vel);
         SerialBT.print("motor girando com velocidade: ")
        SerialBT.println(vel);
        delay(100);
    }
    else {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        ledcWrite(pwmChannel_A, vel);

        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        ledcWrite(pwmChannel_B, vel);
        SerialBT.print("motor girando com velocidade: ")
        SerialBT.println(vel);
        delay(100);
    }
}