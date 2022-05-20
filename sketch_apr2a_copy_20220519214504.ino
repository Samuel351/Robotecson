//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Definicoes pinos Arduino ligados a entrada da Ponte H
#define IN1 = 6;
#define IN2 = 7;
#define IN3 = 8;
#define IN4 = 9;
 
// Sensor ultrassom
#define pino_trigger 4
#define pino_echo 5
 
// Sensor infravermlho
#define sensor_direito 2
#define sensor_esquerdo 3

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  // Pinos do infravermelho
  pinMode(sensor_direito, INPUT);
  pinMode(sensor_esquerdo, INPUT);

  // Pinos do motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Sensor ultrassom
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  //Sensor infravermelho
  int sensorDireito = digitalRead(sensor_direito);
  int sensorEsquerdo = digitalRead(sensor_esquerdo);

  // Lógica do robo

/*
  //Debug do ultrassom
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.println("");


  //Debug do infravermlho (direito e esquerda)
  Serial.print("Sensor direito: ");
  Serial.print(sensorDireito);
  Serial.print("Sensor esquerdo: ");
  Serial.print(sensorEsquerdo);
  Serial.println("");
*/

  delay(1000);
}

//Gira o Motor A no sentido horario
void gira_MA_hora()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

//Para o motor A
void para_MA()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}

//Gira o Motor B no sentido horario
void gira_MB_hora()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//Para o motor B
void para_MB()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
} 

//Gira o Motor A no sentido anti-horario
void gira_MA_antihora()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

//Gira o Motor B no sentido anti-horario
void gira_MB_antihora()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


 

 





