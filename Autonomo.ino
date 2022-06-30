//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Definicoes pinos Arduino ligados a entrada da Ponte H
#define IN1 5
#define IN2 6
#define IN3 10
#define IN4 11
 
// Sensor ultrassom
#define pino_trigger 4
#define pino_echo 3
 
// Sensor infravermlho
#define sensor_direito 2
#define sensor_esquerdo 3

float cmMsec, inMsec;
long microsec;
int ver = 0;

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  // Pinos do infravermelho
  pinMode(sensor_direito, INPUT);
  pinMode(sensor_esquerdo, INPUT);

  int ver = 0;

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
  Serial.println("Lendo dados do sensor ");
  Serial.println(cmMsec);

  //sensor infravermelho
  int sensorDireito = digitalRead(sensor_direito);
  int sensorEsquerdo = digitalRead(sensor_esquerdo);

  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  if(cmMsec <= 40  || sensorDireito == 1 || sensorEsquerdo == 1)
  {
    freio();
    re();
    delay(300);
    while(cmMsec <= 40 || sensorDireito == 1 || sensorEsquerdo == 1)
    {
      esquerdo();
      delay(300);
      microsec = ultrasonic.timing();
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
      if(cmMsec >= 40)
      {
        freio();
        break;
      }
    }
  }
  else
  {
    acelera();
  }
  
}

void acelera()
{
   gira_MA_hora();
   gira_MB_hora();
}

void freio()
{
  para_MA();
  para_MB();
}

void re()
{
  gira_MA_antihora();
  gira_MB_antihora();
}

//Gira o Motor A no sentido horario
void gira_MA_hora()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void gira_MA_hora_potente()
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

void gira_MB_hora_potente()
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
void esquerdo()
{
  gira_MB_hora();  
  gira_MA_antihora();
}

void direito()
{
  gira_MA_hora();
  gira_MB_antihora();
}
//Gira o Motor A no sentido anti-horario
void gira_MA_antihora()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void gira_MA_antihora_potente()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}

void gira_MB_antihora_potente()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

//Gira o Motor B no sentido anti-horario
void gira_MB_antihora()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}