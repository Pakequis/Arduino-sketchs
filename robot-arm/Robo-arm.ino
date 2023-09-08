/*
  Arduino controle de braco robotico
  com joystick de 3 eixos
  por Rodrigo Feliciano
  https://www.youtube.com/pakequis
*/

#include <Servo.h>

#define EIXO1 0 
#define EIXO2 1
#define EIXO3 2
#define EIXO4 3

/* Posicao inicial dos servos ao ligar */
#define START1 90
#define START2 180
#define START3 90
#define START4 95

/* Minimo angulo dos servos */
#define MIN1  0
#define MIN2  90
#define MIN3  10
#define MIN4  10

/* Maximo angulo dos servos */
#define MAX1  180
#define MAX2  180
#define MAX3  120
#define MAX4  95

/* Leituras analogicas minimas e maximas */
#define AN_BASE_MIN   125
#define AN_BASE_MAX   913
#define AN_ELEV_MIN   145
#define AN_ELEV_MAX   975
#define AN_TOPO_MIN   64
#define AN_TOPO_MAX   968
#define AN_GARRA_MIN  30
#define AN_GARRA_MAX  1023

/* Numero de amostras analogicas*/
#define NSAMPLES  10

/* Servos */
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

/* Variaveis dos angulos */
int ang1 = START1;
int ang2 = START2;
int ang3 = START3;
int ang4 = START4;

/* Incremento dos angulos */
int inc1 = 0;
int inc2 = 0;
int inc3 = 0;
int inc4 = 0;

int i = 0;

/* Passo dos angulos */
const int steps[12] = {20, 15, 10, 5, 1, 0, -1, -5, -10, -15, -20, 0};

void setup() 
{
  /* Servos nos pinos */
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);

  /* Posiciona servos no inicio */
  servo1.write(ang1);
  servo2.write(ang2);
  servo3.write(ang3);
  servo4.write(ang4);
}

void loop() 
{
  /* 10 leituras por canal */
  for (i = 0; i < NSAMPLES; i++)
  {
    inc1 += analogRead(EIXO1);
    inc2 += analogRead(EIXO2);
    inc3 += analogRead(EIXO3);
    inc4 += analogRead(EIXO4);
    delay(5);
  }
  /* Media das leituras */
  inc1 = inc1 / NSAMPLES;
  inc2 = inc2 / NSAMPLES;
  inc3 = inc3 / NSAMPLES;
  inc4 = inc4 / NSAMPLES;

  /* Converte o valor analogico para indice de incremento de angulo */
  inc3 = map(inc3, AN_BASE_MIN, AN_BASE_MAX, 0, 12);
  inc2 = map(inc2, AN_ELEV_MIN, AN_ELEV_MAX, 0, 12);
  inc1 = map(inc1, AN_TOPO_MIN, AN_TOPO_MAX, 0, 12);

  /* Atualiza os angulos */
  ang1 = ang1 + steps[inc3];
  ang2 = ang2 + steps[inc1];
  ang3 = ang3 + steps[inc2];

  /* Garra eh controlada por um potenciometro */
  ang4 = map(inc4, AN_GARRA_MIN, AN_GARRA_MAX, MIN4, MAX4);

  /* Checa limites dos angulos */
  if (ang1 < MIN1) ang1 = MIN1; 
  if (ang1 > MAX1) ang1 = MAX1;
  if (ang2 < MIN2) ang2 = MIN2;
  if (ang2 > MAX2) ang2 = MAX2;
  if (ang3 < MIN3) ang3 = MIN3;
  if (ang3 > MAX3) ang3 = MAX3;
  if (ang4 < MIN4) ang4 = MIN4;
  if (ang4 > MAX4) ang4 = MAX4;

  /* Atualiza servos com os angulos */
  servo1.write(ang1);
  servo2.write(ang2);
  servo3.write(ang3);
  servo4.write(ang4);
  
  delay(10); // Delay entre as atualizacoes dos servos
}
