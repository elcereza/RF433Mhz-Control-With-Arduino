/*-------------------------------------------------------------------------------
* Projeto: Controle RF433MHZ com Arduino
* Saiba mais: https://elcereza.com/conectar-a-estacao-meteorologica-com-a-orion/
* Disponibilizado por: https://elcereza.com
* Autor: Suat Özgür
* Editado e Comentado: Gustavo Cereza
---------------------------------------------------------------------------------*/

#include <RCSwitch.h>                                                             // Inclue biblioteca RCSwitch
RCSwitch mySwitch = RCSwitch();                                                   // Atribue variável mySwitch o valor de RCSwitch                                     
void setup() {
  Serial.begin(9600);                                                             // Estabelece 9600 como velocidade de BaudRate
  mySwitch.enableReceive(0);                                                      // Inicializa leitura no pino digital 2
}                                                                                 // Finaliza setup
void loop() {
  if (mySwitch.available()) {                                                     // Avalia se tá recebendo sinal
    Serial.print("Recebido ");                                                
    Serial.print( mySwitch.getReceivedValue() );                                  // Printa o valor recebeido pelo RF
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );                              // Printa a quantidade de bit's
    Serial.print("bit ");
    Serial.print("Protocolo: ");
    Serial.println( mySwitch.getReceivedProtocol() );                             // Printa o protocolo

    /*

     Este 'if' abaixo representa um acionamento da porta digital 13
     de acordo com o botão decodificado selecionado, para implementar
     o botão desejado é só copiar o valor decimal após o '==', 
     da seguinte forma: if(mySwitch.getReceivedValue() == 177963301){}

     para mais informações sobre este projeto, 
     acesse: 
     
     
    if(mySwitch.getReceivedValue() == DECIMAL1)                                  // Se mySwitch receber o valor do programado, vai por a porta 13 em nível alto
    {
     digitalWrite(13,1);                                                         // Liga o LED
    } if(mySwitch.getReceivedValue() == DECIMAL2)                                // Se mySwitch receber o outro valor programado, vai por o nível lógico baixo
    {
      digitalWrite(13,0);                                                        // Desliga o LED
    }

    */ 

    mySwitch.resetAvailable();                                                   // Reinicia leitura
  }
}                                                                                // Finali
