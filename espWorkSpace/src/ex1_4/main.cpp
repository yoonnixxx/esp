#include <Arduino.h>
#define LEDPIN 2
int delaytime = 2000;
unsigned int tempo = 0;
int ligado = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(LEDPIN, OUTPUT);
}

void loop()
{
    if (millis() - tempo >= delaytime)
    {
        tempo = millis();
        if (ligado){
            digitalWrite(LEDPIN, HIGH);
            Serial.println("Led aceso");
            ligado = 0;
        }
        else {
            digitalWrite(LEDPIN, LOW);
            Serial.println("Led apagado");
            ligado = 1;
        }
    }
}