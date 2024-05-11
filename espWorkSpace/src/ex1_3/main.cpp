#include <Arduino.h>

#define LED_1 2
#define LED_2 33
#define BUTAO 27
int delaytime = 1000;
int count = 1;
int marcatempo = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(BUTAO, INPUT_PULLUP);
}
void loop()
{
    if (millis() - marcatempo >= 250 && digitalRead(BUTAO)== LOW){
        count++;
        marcatempo=millis();
        Serial.print("N: ");
        Serial.print(count);
        while (digitalRead(BUTAO)==LOW);
    }

    if (count % 3 == 0)
    {
        digitalWrite(LED_1, HIGH);
        Serial.print(count);
        Serial.print(" Led no pino: ");
        Serial.print(LED_1);
        Serial.print(" aceso");
        Serial.println("");
    }
    if (count % 5 == 0)
    {
        digitalWrite(LED_2, HIGH);
        Serial.print(count);
        Serial.print("Led no pino: ");
        Serial.print(LED_2);
        Serial.print(" aceso");
        Serial.println("");
    }
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_1, LOW);
}