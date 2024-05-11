#include <Arduino.h>

#define LED_1 2
#define LED_2 33
int delaytime = 2000;

void setup(){
    Serial.begin(115200);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
}
void loop(){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    Serial.print("Led no pino: ");
    Serial.print(LED_1);
    Serial.print(" aceso e led no pino: ");
    Serial.print(LED_2);
    Serial.print("apagado");
    Serial.println("");
    delay (delaytime);

    digitalWrite(LED_2, HIGH);
    digitalWrite (LED_1, LOW);
    Serial.print("Led no pino: ");
    Serial.print(LED_2);
    Serial.print(" aceso e led no pino: ");
    Serial.print(LED_1);
    Serial.print("apagado");
    Serial.println("");
    delay (delaytime);
}