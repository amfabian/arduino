#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_GFX.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_SSD1306.h> //INCLUSÃO DE BIBLIOTECA

#include "DHT.h"
#define DHTPIN 2 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
int sensorValue;
float h;
float t;

Adafruit_SSD1306 display = Adafruit_SSD1306(); //OBJETO DO TIPO Adafruit_SSD1306

DHT dht(DHTPIN, DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();

  Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //INICIALIZA O DISPLAY COM ENDEREÇO I2C 0x3C
  display.setTextColor(WHITE); //DEFINE A COR DO TEXTO
  display.setTextSize(0); //DEFINE O TAMANHO DA FONTE DO TEXTO
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
}
 void loop() 
{
  
   display.setCursor(40,1); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Monitor "); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  display.drawLine(0, 12, 127, 12, 1);
  display.setCursor(1,15); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Temperatura:"); //ESCREVE O TEXTO NO DISPLAY
  display.setCursor(1,25); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Umidade:"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  
  sensorValue=analogRead(A0);
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  h = dht.readHumidity();
  t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
 /* if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
   
  */
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


  
  display.setCursor(80,15); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print(t); //ESCREVE O TEXTO NO DISPLAY
  display.setCursor(80,25); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print(h); //ESCREVE O TEXTO NO DISPLAY
  display.setCursor(115,15); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print(" c"); //ESCREVE O TEXTO NO DISPLAY
  display.setCursor(115,25); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print(" %"); //ESCREVE O TEXTO NO DISPLAY
  display.display();
    
    delay(10000);
     
    display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
 // }

  
}
