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
int sensorDireito, sensorEsquerdo;
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

  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  if(cmMsec <= 40)
  {
    ataque();
  }
  else
  {
    procurar_esquerdo();

    delay(100);

    procurar_direito();

    delay(100);

    acelera();
    delay(300);
    freio();
  }
  
}

void ataque()
{
  while(cmMsec <= 40)
  {
    if(cmMsec <= 40)
    {
      acelera();
      delay(5000);
      re();
      delay(700);
      microsec = ultrasonic.timing();
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    }
  }
    freio();
}


void procurar_esquerdo()
{
  for(int i = 0; i < 4; i++)
  {  
    gira_MA_antihora();
    delay(100);
    freio();
    delay(100);
    microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    delay(100);
    if(cmMsec <= 40)
    {
      ataque();
      break;
    }
    delay(200);
  }
  gira_MA_hora();
  delay(200);
  freio();
}

void procurar_direito()
{
  for(int i = 0; i < 4; i++)
  {
    gira_MB_antihora();
    delay(100);
    freio();
    delay(100);
    microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    delay(100);
    if(cmMsec <= 40)
    {
      ataque();
      break;
    }
    delay(200);
  }
  gira_MB_hora();
  delay(210);
  freio();
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