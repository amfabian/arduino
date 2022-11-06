#include <SoftwareSerial.h>

const int pinoRX = 0; //PINO DIGITAL 2 (RX)
const int pinoTX = 1; //PINO DIGITAL 3 (TX)

int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
boolean loopLED = false; //VARIÁVEL BOOLEANA QUE FAZ O CONTROLE DE ATIVAÇÃO DO LOOP DO LED
SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL, ONDE
void setup() {
 Serial.begin(9600); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  pinMode(LED_BUILTIN, OUTPUT); //DEFINE O PINO COMO SAÍDA

}

void loop() {
if(bluetooth.available()){ //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
       dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
 
    if(dadoBluetooth == '1'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("LED LIGADO"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(LED_BUILTIN, HIGH); //LIGA O LED
    }
    if(dadoBluetooth == '0'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("LED DESLIGADO"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(LED_BUILTIN, LOW); //DESLIGA O LED
    }
    if(dadoBluetooth == 'b'){ //SE O VALOR RECEBIDO FOR IGUAL A b, FAZ
      Serial.println("LOOP DO LED ATIVADO"); //IMPRIME O TEXTO NA SERIAL
      loopLED = true; //VARIÁVEL RECEBE verdadeiro
    }else{ //SENÃO, FAZ
      loopLED = false; //VARIÁVEL RECEBE falso
    }
  }
 
  //MÉTODO RESPONSÁVEL PELO LOOP (LIGA / DESLIGA) DO LED
  if(loopLED){
    digitalWrite(LED_BUILTIN, HIGH); //LIGA O LED
    Serial.println("LOOP (LED LIGADO)"); //IMPRIME O TEXTO NA SERIAL
    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
    digitalWrite(LED_BUILTIN, LOW); //DESLIGA O LED
    Serial.println("LOOP (LED DESLIGADO)"); //IMPRIME O TEXTO NA SERIAL
    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
  }

}
