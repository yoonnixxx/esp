#include <Arduino.h>
#define LED 2

void setup(){
    pinMode (2, OUTPUT);

}
void loop(){
    digitalWrite (2, HIGH);
    delay (2000);
    digitalWrite (2, LOW);
    delay (2000);
}