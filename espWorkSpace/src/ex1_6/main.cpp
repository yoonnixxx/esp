#include <Arduino.h>

// pino do led
const int ledPin = 16; 

// seta PWM propriedades
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
 
void setup(){
  // conf ass funcionalidades do led
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to  the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
}
 
void loop(){
  // increase the LED brightness
  for(int ciclo = 0; ciclo <= 255; ciclo++){   
    // troca o brilho do led com pwm
    ledcWrite(ledChannel, ciclo);
    delay(15);
  }

  // diminui brilho
  for(int ciclo = 255; ciclo >= 0; ciclo--){
    // troca o brilho do led com pwm
    ledcWrite(ledChannel, ciclo);   
    delay(15);
  }
}