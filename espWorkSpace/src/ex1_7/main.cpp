#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#define DHT_SENSOR_PIN  21 // ESP32 pin GPIO21 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  Serial.begin(115200);
  dht_sensor.begin(); // initialize the DHT sensor
}

void loop() {
   // humidade 
    float humi = dht_sensor.readHumidity();
    // temp em celsius 
    float tempC = dht_sensor.readTemperature();
    
    // testa se deu pra medir ou não 
    if (isnan(tempC) || isnan(tempF) || isnan(humi))
    {
        SerialBT.println("Failed to read from DHT sensor!");
    }
    else // imprimi
    {
        SerialBT.print("Humidity: ");
        SerialBT.print(humi);
        SerialBT.print("%");

        SerialBT.print("  |  ");

        SerialBT.print("Temperature: ");
        SerialBT.print(tempC);
        SerialBT.print("°C  ~  ");
        SerialBT.print(tempF);
        SerialBT.println("°F");
    }
    delay(2000);
}