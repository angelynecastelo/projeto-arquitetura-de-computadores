int nivelAgua = 0; // define a variável nivelAgua do tipo inteiro
int interruptor = 0; // define a variável interruptor do tipo interruptor
int bomba = 0; // define a variável bomba do tipo inteiro

int LedVemelho = 6; // variável LedVermelho rebece o pino 6
int LedVerde = 5; // variável LedVerde recebe o pino 5
int LedAzul = 4; // variável LedAzul recebe o pino 4
int Buzzer = 3; // variável Buzzer recebe o pino 3
int pinInterruptor = 7; // variável pinInterruptor recebe o pino 7

void setup()
{
  // liga o monitor serial
  Serial.begin(9600);
  
  //pinMode indica o modo do pino
  
  pinMode(pinInterruptor, INPUT); // pino 7 ligado no modo de leitura
  pinMode(LedVemelho, OUTPUT);// pino 6 ligado no modo de saída
  pinMode(LedVerde, OUTPUT);// pino 5 ligado no modo de saída
  pinMode(LedAzul, OUTPUT);// pino 4 ligado no modo de saída
  pinMode(Buzzer, OUTPUT);// pino 3 ligado no modo de saída
}

void loop()
{
  // Bloco de água
  if(nivelAgua != 0)// Se o nivelAgua for diferente de 0, faça:
    nivelAgua -= 1; // nivelAgua diminui 1
  
  //Bloco do interruptor
  interruptor = digitalRead(7); /*interruptor recebe a leitura do
  pino 7*/
  if(interruptor == HIGH){ //se o interruptor estiver ligado, faça:
    digitalWrite(LedVemelho, LOW); // desliga o LED vermelho
    digitalWrite(LedVerde, HIGH); // liga o LED verde
    
    // Bloco do bombeamento
    if(nivelAgua >= 29) { /* Se nivel da agua for maior ou igual
    30*/
      bomba = 0; // Bomba recebe o valor de 0
      digitalWrite(Buzzer, LOW); // Desliga o BUZZER
      digitalWrite(LedAzul, LOW); // Desliga o LED azul
      Serial.println("Bomba desligada"); /* Exibe a mensagem no 
      monitor serial*/
    }
    if(nivelAgua <= 15){
      bomba = 1; // Bomba recebe valor de 1
      Serial.println("Bomba ligada!"); /* Exibe a mensagem no 
      monitor serial*/
    }
    
    // Bloco da bomba
    if(bomba == 1){ // Se bomba for igual a 1
      nivelAgua += 2; // incrementa 2 no nivel da agua
      digitalWrite(Buzzer, HIGH); // liga o BUZZER
      digitalWrite(LedAzul, HIGH); // Liga o LED azul
      /* funcao tone recebe três parâmetros: 
      	pino do BUZZER, a frrquência, e o intervalo 
        de tempo em milissegundos 
      */
      tone(Buzzer, 250, 200); /* liga o BUZZER na frequência 250
      por 200 milissegundos*/
      Serial.println("Bombeando agua!"); /* Exibe a mensagem 
      no monitor serial*/
    }
  } else { //caso contrario 
    bomba = 0; // bomba recebe 0
    digitalWrite(LedVemelho, HIGH); // Liga o LED vermelho
    digitalWrite(LedVerde, LOW); // desliga o LED verde
    digitalWrite(LedAzul, LOW); // desliga o LED azul
    digitalWrite(Buzzer, LOW); // desliga o BUZZER
  }
  Serial.print("Nivel da agua: "); //Exibe a mensagem no monitor serial
  Serial.println(nivelAgua); // Exibe o nivel de agua do reservatório
  
  delay(400); // intervalo de 400 milissegundos
}