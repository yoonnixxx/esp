#include <Arduino.h>

#define LEDPIN 2
#define POT 4
int delaytime;

void setup(){
    Serial.begin(115200);
    pinMode(LEDPIN, OUTPUT);
    pinMode (POT, INPUT_PULLDOWN);
}

void loop(){

    delaytime = analogRead(POT);
    delaytime= map(delaytime, 0, 4096, 10000, 100);
    digitalWrite (LEDPIN, HIGH);
    Serial.println("Led acesso");
    Serial.println(delaytime);
    delay (delaytime);

    digitalWrite (LEDPIN, LOW);
    Serial.println("Led apagado");
    delay (delaytime);
}