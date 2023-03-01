const int buzzer = 2; //declaraçao e definiçao de constante da porta digital 2 para o buzzer
const int led = 3; //declaraçao e definiçao de constante da porta digital 3 para o led
const int botao = 4;//declaraçao e definiçao de constante da porta digital 4 para o botão
const int sensorLdr = 0; //declaraçao e definiçao de constante da porta analogia 0 para o buzzer
int estadoBotao = 0; //variavel que recebe valor do ldr
int valorLdr = 0; //declaração da variavel ldr
void setup() {
  pinMode(buzzer, OUTPUT); //definiçao do pino 2 como saida
  pinMode(led, OUTPUT); //definiçao do pino 3 como saida
  pinMode(botao,INPUT); //definição do pino 4 como entrada
  digitalWrite(led, HIGH); //liga o led que faz feixe de luz no sensor ldr
}

void loop() {
  estadoBotao = !digitalRead(botao); //variavel recebe estado HIGH ou LOW do botão/
  analogRead(sensorLdr); //faz leitura da porta analógica 
  valorLdr = analogRead(sensorLdr); //atribuindo valor analogico lido a variavel valorLdr
  if(valorLdr<=700){ //testa se a variavel está abaixo de 700, valor testado e precalibrado
    tone(buzzer,2000); //emite bip de buzzer
  }else{
    if(estadoBotao==HIGH){ //testa se estado do botão é HIGH ele desativa o buzzer
      noTone(buzzer);
    }
  }
}
