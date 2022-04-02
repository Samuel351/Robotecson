//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

int pinoLed = 12; //Pino digital utilizado pelo led
int pinoSensor = 8; //Pino digital utilizado pelo sensor

void setup() {
  
  //Define o pino do sensor como entrada e o do led como saída
  pinMode(pinoSensor, INPUT);
  pinMode(pinoLed, OUTPUT);

  //Define os pinos como saida (Ponte H)
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 
  Serial.begin(9600);
 
  while (digitalRead(2) == 0) 
  {
    delay(1);
    stop();
    Serial.println("aguardando");
  }
}
 
void loop() {

 //Se a leitura do pino for igual a low
 if(digitalRead(pinoSensor) == LOW)
 { 
      digitalWrite(pinoLed, HIGH); //Acende o led
      parar();
      delay(1);
      re();
      delay(300);
      parar();
      delay(1);
      girar();
      delay(600);
      parar();
      digitalWrite(pinoLed, LOW); // Apaga led
  }

  acelera();
  delay(1);
}

// Motores giram em sentido anti-horário
void re() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Motores giram em sentido horário
void acelera() 
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Girar o carrinho
void girar() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
// Para os motores
void parar() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}