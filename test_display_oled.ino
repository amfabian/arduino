#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_GFX.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_SSD1306.h> //INCLUSÃO DE BIBLIOTECA

Adafruit_SSD1306 display = Adafruit_SSD1306(); //OBJETO DO TIPO Adafruit_SSD1306

void setup(){
  Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //INICIALIZA O DISPLAY COM ENDEREÇO I2C 0x3C
  display.setTextColor(WHITE); //DEFINE A COR DO TEXTO
  display.setTextSize(1); //DEFINE O TAMANHO DA FONTE DO TEXTO
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
}
void loop() {
  display.setCursor(40,1); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Monitor "); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  display.drawLine(0, 12, 127, 12, 1);
  display.setCursor(1,15); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Temperatura: 28 c"); //ESCREVE O TEXTO NO DISPLAY
  display.setCursor(1,25); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Umidade: 28 c"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
}
