#include <Arduino.h>
#include "BluetoothSerial.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
//#include <BLEDevice.h>

// conf do blueth
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

// declaração do sensor de humidade
#define DHT_SENSOR_PIN  21
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

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

// pinos das coisas e variaveis 
const unsigned int BUTAO = 15;
const unsigned int POT = 4;
const unsigned int LEDPIN = 5;
int direcao = 1;
int ultimaDirecao = 0;
int marcatempo = 0;

void sensorTemp ();
void piscaLed();
void stop ();
void forward(int vel);
void backwards(int vel);

void setup()
{
    // inicializçao
    Serial.begin(115200);
    dht_sensor.begin();
    SerialBT.begin("ESP32test"); // Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

    // definindo os pinos
    pinMode(PWM1, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    pinMode(PWM2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);

    pinMode(STBY, OUTPUT);

    pinMode(BUTAO, INPUT_PULLUP);
    pinMode(POT, INPUT_PULLDOWN);
    pinMode(LEDPIN, OUTPUT);

    // Configura funcionalidades LED PWM
    ledcSetup(pwmChannel_A, freq, resolution);
    ledcSetup(pwmChannel_B, freq, resolution);

    // anexa o canal ao GPIO a ser controlado
    ledcAttachPin(PWM1, pwmChannel_A);
    ledcAttachPin(PWM2, pwmChannel_B);
    digitalWrite(STBY, HIGH);
}

void loop()
{
    //conet blueth
    if (Serial.available()){SerialBT.write(Serial.read());}
    if (SerialBT.available()){Serial.write(SerialBT.read());}
    delay(20);

    // calcula a velocidade de acordo com o potenciometro 
    int vel = analogRead(POT);
    vel= map(vel, 0, 4096, 255, 0);

    sensorTemp(); // mede temperatura e humidade 
    piscaLed(); // pisca o led?????? kkkk

    if (millis() - marcatempo >= 250 && digitalRead(BUTAO)== HIGH){ // debounce
        marcatempo=millis(); 
        SerialBT.print("botao apertado");
        //while (digitalRead(BUTAO)==LOW);

    // se a direção for 1 quando o botao for apertado e a ultima for 0 troca o sentido
        if (direcao == 1 && ultimaDirecao == 0){ 
          direcao = 0;
          ultimaDirecao = 1;  
          stop();
          forward(vel);
        }
        // se for 0 vai fazer a mesma coisa pro outro lado 
        else if (direcao == 0 && ultimaDirecao == 1) {
            direcao = 1;
            ultimaDirecao = 0;
            stop();
            backwards(vel);
        }
    }
   
    SerialBT.println("//////////////////////////\n");
}

void sensorTemp (){
    // humidade 
    float humi = dht_sensor.readHumidity();
    // temp em celsius 
    float tempC = dht_sensor.readTemperature();
    
    // testa se deu pra medir ou não 
    if (isnan(tempC) || isnan(tempF) || isnan(humi))
    {
        SerialBT.println("Failed to read from DHT sensor!");
    }
    else // imprimi
    {
        SerialBT.print("Humidity: ");
        SerialBT.print(humi);
        SerialBT.print("%");

        SerialBT.print("  |  ");

        SerialBT.print("Temperature: ");
        SerialBT.print(tempC);
        SerialBT.print("°C  ~  ");
        SerialBT.print(tempF);
        SerialBT.println("°F");
    }
    delay(2000);
}

void piscaLed()
{
    digitalWrite (LEDPIN, HIGH);
    SerialBT.println("Led acesso");
    delay (1000);

    digitalWrite (LEDPIN, LOW);
    SerialBT.println("Led apagado");
    delay (1000);
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

void forward(int vel) // vai pra frente?
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    ledcWrite(pwmChannel_A, vel);

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    ledcWrite(pwmChannel_B, vel);
    SerialBT.print("A, motor girando com velocidade: ");
    SerialBT.println(vel);
    delay(100);
}

void backwards(int vel)
{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    ledcWrite(pwmChannel_A, vel);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    ledcWrite(pwmChannel_B, vel);
    SerialBT.print("B, motor girando com velocidade: ");
    SerialBT.println(vel);
    delay(100);
}
