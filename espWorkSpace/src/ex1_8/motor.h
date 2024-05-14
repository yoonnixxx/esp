#include <Arduino.h>

void foward(int motor, int velocidade, int pwmChannel_A, int pwmChannel_B);
void reverse(int motor, int velocidade, int pwmChannel_A, int pwmChannel_B);
void stop(int motor, int pwmChannel_A, int pwmChannel_B);