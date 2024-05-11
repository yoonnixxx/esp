#include <Arduino.h>

#define LEDPIN 2
int delaytime = 2000;

void setup(){
    Serial.begin(115200);
    pinMode(LEDPIN, OUTPUT);
}

void loop(){
    digitalWrite (LEDPIN, HIGH);
    Serial.println("Led acesso");
    delay (delaytime);

    digitalWrite (LEDPIN, LOW);
    Serial.println("Led apagado");
    delay (delaytime);
}