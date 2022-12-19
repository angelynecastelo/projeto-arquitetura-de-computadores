//SEMAFORO PARA DEFICIENTES VISUAIS.
//Definição dos pinos para o sistema de semaforo. */

#define pinLedVermelho 13               //Pino do Led vermelho dos carros.
#define pinLedAmarelo 12               //Pino do Led amarelo dos carros.
#define pinLedVerde 11                //Pino do Led verde dos carros.
#define pinVermelhoPedestre 5        //Pino do led vermelho dos pedestres.
#define pinVerdePedestre 6          //Pino do led verde dos pedestres.
#define pinBuzzer 2                // Pino que ligar o Buzzer(alarme) do semaforo.



void setup()
{
  pinMode(pinLedVermelho, OUTPUT);            //Definindo pinLedVermelho 13 como SAIDA.
  pinMode(pinLedAmarelo, OUTPUT);            //Definindo pinLedAmarelo 12 como SAIDA.
  pinMode(pinLedVerde, OUTPUT);             //Definindo pinLedVerde 11 como SAIDA.//Defindo pinLedAmarelo 12 como SAIDA.
  pinMode(pinVermelhoPedestre, OUTPUT);    //Definindo pinVermelhoPedestre 5 como SAIDA.
  pinMode(pinVerdePedestre, OUTPUT);      //Definindo pinVerdePedestre 6 como SAIDA.
  pinMode(pinBuzzer, OUTPUT);            //Definindo pinBuzzer 2 como SAIDA.
}

void loop()
{ 
  /*Parte 1: Verde(LIGADO); Amarelo(DESLIGADO); Vermelho(DESLIGADO). */
  
  digitalWrite(pinLedVerde, HIGH);            //Ligar o led Verde do semaforo.
  digitalWrite(pinLedAmarelo, LOW);          //Desligar led Amarelo do semaforo.
  digitalWrite(pinLedVermelho, LOW);        //Desligar led Amarelo do semaforo.
  
  digitalWrite(pinVermelhoPedestre, HIGH);   //liga o led vermelho dos pedestres.
  digitalWrite(pinVerdePedestre, LOW);      //Desliga o led Verde dos pedestres.
  delay(1500);
  
  //Parte 2: Verde(DESLIGADO); Amarelo(LIGADO); Vermelho(DESLIGADO).
  
  digitalWrite(pinLedVerde, LOW);          //Desiga o led Verde do semaforo.
  digitalWrite(pinLedAmarelo, HIGH);      //Liga o led Amarelo do semaforo.
  digitalWrite(pinLedVermelho, LOW);     //Desliga o led Vermelho.
  
  digitalWrite(pinVermelhoPedestre, HIGH);   //Liga o led Vermelho dos pedestres.
  digitalWrite(pinVerdePedestre, LOW);      //Desliga o led Verde dos pedestres.
  delay(1500);
  
  //Parte 3 Verde(DESLIGADO); Amarelo(DESLIGADO); Vermelho(LIGADO).*/
  
  digitalWrite(pinLedVerde, LOW);            //Desligar o led Verde do semaforo.
  digitalWrite(pinLedAmarelo, LOW);         //Desligar o led Amarelo do semaforo.
  digitalWrite(pinLedVermelho, HIGH);      //Liga o led Vermelho do semaforo.
  
  digitalWrite(pinVermelhoPedestre, LOW);       //Desliga o led Vermelho dos pedestres.
  digitalWrite(pinVerdePedestre, HIGH);        //Liga o led Verde dos pedestres.
  
  /*Parte do Buzzer(alarme). */
  
  tone(pinBuzzer, 398);//Liga o Buzzer(alarme) pelo periodo de 3,5 segundos
  delay(3500);    /*Tempo de 3,5 segundos. */
  noTone(pinBuzzer);    //Desliga o Buzzer. */
  
  digitalWrite(pinVerdePedestre, LOW); //desliga o led vermelho dos pedestres.

  digitalWrite(pinVermelhoPedestre, HIGH); //liga o led vermelho dos pedestres.
  delay(1000);       /*Tempo de 1 segundos. */
  
  digitalWrite(pinVermelhoPedestre, LOW); //desliga o led vermelho dos pedestres.//desliga o led vermelho dos pedestres.
  delay(1000);      /*Tempo de 1 segundos. */
  
  digitalWrite(pinVermelhoPedestre, HIGH); //liga o led vermelho dos pedestres.
  delay(1000);     /*Tempo de 1 segundos. */
  
  digitalWrite(pinVermelhoPedestre, LOW); //desliga o led vermelho dos pedestres.
  delay(1000);     /*Tempo de 1 segundos. */
  
  digitalWrite(pinVermelhoPedestre, HIGH); //liga o led vermelho dos pedestres.
  delay(1000);     /*Tempo de 3,5 segundos. */
}
