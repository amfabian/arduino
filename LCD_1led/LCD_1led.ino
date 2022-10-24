// LCD + LED + Potenciometro
// LED : PINO 08

#include <LiquidCrystal.h>
#define TEMPO_REFRESH 500
int ledBlue = 8;
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
pinMode(ledBlue, OUTPUT);
 
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);

//inicialização do lcd (16 colunas e 02 linhas)
lcd.begin(16,2);
  
lcd.clear();

// posiciona o cursor
lcd.setCursor(0,0);
// imprime
lcd.print("Alexandre");
// imprime na segunda linha
lcd.setCursor(0,1);
lcd.print("IFRS - POA");
delay(5000);
}

void loop() {


delay(1000);

    
  //Rolagem para a direita
  for (int posicao = 0; posicao < 16; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
digitalWrite(ledBlue, HIGH);

lcd.clear();
delay(300);
lcd.setCursor(0,0);
lcd.print("e");
lcd.setCursor(0,1);
lcd.print("");
delay(300);
lcd.scrollDisplayRight();
//lcd.setCursor(0,0);
lcd.print("re");
//lcd.setCursor(0,1);
lcd.print("");
delay(300);
lcd.scrollDisplayRight();
//lcd.setCursor(0,0);
lcd.print("dre");
//lcd.setCursor(0,1);
lcd.print("");
delay(300);

}
