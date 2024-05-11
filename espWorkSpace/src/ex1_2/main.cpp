#include <Arduino.h>

#define LED_1 2
#define LED_2 33
int delaytime = 1000;
int count = 0;
int maximo = 100;

void setup(){
    Serial.begin(115200);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
}
void loop(){
    count += 1;
    Serial.print("N: ");
    if (count > maximo){
        count = 0;
    } else {
        if (count % 3 == 0){
            digitalWrite(LED_1, HIGH);
            Serial.print(count);
            Serial.print(" Led no pino: ");
            Serial.print(LED_1);
            Serial.print(" aceso");
            Serial.println("");
        }
        else if (count % 5 == 0){
            digitalWrite(LED_2, HIGH);
            Serial.print(count);
            Serial.print("Led no pino: ");
            Serial.print(LED_2);
            Serial.print(" aceso");
            Serial.println("");
        }
    }

    delay (delaytime);
    digitalWrite(LED_2, LOW);
    digitalWrite (LED_1, LOW);

}