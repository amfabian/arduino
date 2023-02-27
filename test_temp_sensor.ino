#include "DHT.h"
#define DHTPIN 2 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}
 void loop() 
{
  int sensorValue;
  sensorValue=analogRead(A0);
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print("%t ");
    Serial.print(" -- Temperatura: ");
    Serial.print(t);
    Serial.print("*C");
    Serial.print(" -- UV:");
    Serial.print(sensorValue*5000/1023.0);
    Serial.print("mV");
    Serial.print("\n");
    delay(1000);
  }
}
