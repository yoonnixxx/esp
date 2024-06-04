#include <Arduino.h>
#include "BluetoothSerial.h"

// conf do blueth
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
// defini pinos e variaveis 
#define LED_1 2
#define LED_2 33
int delaytime = 1000;
int count = 0;
int maximo = 100;

void setup()
{  
    Serial.begin(115200);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    SerialBT.begin("ESP32test"); // Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");
}
void loop()
{   
    //conet blueth
    if (Serial.available()){SerialBT.write(Serial.read());}
    if (SerialBT.available()){Serial.write(SerialBT.read());}
    delay(20);

    count += 1; // incrementa o contador 
    Serial.print("N: ");
    if (count > maximo) // testa se o cont ta no limite
    {
        count = 0;
    }
    else
    {
        if (count % 3 == 0) // multiplo de 3
        {
            digitalWrite(LED_1, HIGH);
            SerialBT.print(count);
            SerialBT.print(" Led no pino: ");
            SerialBT.print(LED_1);
            SerialBT.print(" aceso");
            SerialBT.println("");
        }
        else if (count % 5 == 0) // multiplo de 5
        {
            digitalWrite(LED_2, HIGH);
            SerialBT.print(count);
            SerialBT.print("Led no pino: ");
            SerialBT.print(LED_2);
            SerialBT.print(" aceso");
            SerialBT.println("");
        }
    }

    delay(delaytime); 
    // desliga o led
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_1, LOW);
}