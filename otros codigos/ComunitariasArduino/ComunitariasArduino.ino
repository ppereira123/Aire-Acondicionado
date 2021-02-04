

#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 8 
#define DHTTYPE    DHT11 
const int analogInPin = A0;
float sensorValue = 0;       
int bateria = 0;        
sensors_event_t event;
char lectura;
//INICIO SENSOR DE HUMEDAD Y TEMPERATURA////
DHT_Unified dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  
  sensorValue = analogRead(analogInPin);
  dht.temperature().getEvent(&event);
  Serial.print(event.temperature);
  Serial.print(",");
  delay(10);
  dht.humidity().getEvent(&event);
  Serial.print(event.relative_humidity);
  Serial.print(",");
  delay(10);
  bateria = (sensorValue/1023)*100;
  Serial.println(bateria);
  delay(3000);
}
