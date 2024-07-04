#include <Arduino.h>

#define LEDPIN 2
int delaytime = 1000;
void Para(void *parametro){
    Serial.println("Led acesso");
 
    Serial.println("Led apagado");

    }
    
void setup(){
    Serial.begin(115200);
    //pinMode(LEDPIN, OUTPUT);
    xTaskCreatePinnedToCore(
    Para,
    "Procura",
    10000,
    NULL,
    1,
    NULL,
    1
  );
}

void loop(){
    Serial.println("");
    Serial.println("O");
    Serial.println("");
}