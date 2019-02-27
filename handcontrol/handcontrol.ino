/*
  Code for LewanSoul hand controler

  Rodrigo Feliciano - 10/02/2019
  https://www.pakequis.com.br

*/
#include <SoftwareSerial.h>

#define LED1  2
#define LED2  3
#define LED3  4
#define LED4  5
#define LED5  6

#define FINGER1 0
#define FINGER2 1
#define FINGER3 2
#define FINGER4 3
#define FINGER5 6

SoftwareSerial BTSerial(11,12);
int val[5];

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  BTSerial.begin(9600);
  BTSerial.print("AT+ROLE=S");
  delay(100);
  BTSerial.print("AT+RESET");
  delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:

 /* digitalWrite(LED1,0);
  digitalWrite(LED2,0);
  digitalWrite(LED3,0);
  digitalWrite(LED4,0);
  digitalWrite(LED5,0);

  delay(250);*/

  digitalWrite(LED1,1);
  digitalWrite(LED2,1);
  digitalWrite(LED3,1);
  digitalWrite(LED4,1);
  digitalWrite(LED5,1);

  delay(250);
  
  val[0] = analogRead(FINGER1);
  val[1] = analogRead(FINGER2);
  val[2] = analogRead(FINGER3);
  val[3] = analogRead(FINGER4);
  val[4] = analogRead(FINGER5);
  BTSerial.print(val[0]);
  BTSerial.print(",");
  BTSerial.print(val[1]);
  BTSerial.print(",");
  BTSerial.print(val[2]);
  BTSerial.print(",");
  BTSerial.print(val[3]);
  BTSerial.print(",");
  BTSerial.print(val[4]);
  BTSerial.println(";");
  delay(1000);
}
