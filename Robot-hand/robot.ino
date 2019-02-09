//Robotic hand test for find the servos angles...
// Rodrigo - 02/02/2019
//https://www.pakequis.com.br

#include <Servo.h>

Servo finger1;
Servo finger2;
Servo finger3;
Servo finger4;
Servo finger5;

/*
  Dedo 5 - 90 - 170
  Dedo 4 - 0 - 150
  Dedo 3 - 0 - 100
  Dedo 2 - 0 - 100
  Dedo 1 - 30 - 120
*/

int teste;

void setup() {
  finger1.attach(6);
  finger2.attach(7);
  finger3.attach(8);
  finger4.attach(9);
  finger5.attach(10);

  finger1.write(30);
  finger2.write(0);
  finger3.write(0);
  finger4.write(0);
  finger5.write(90);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
//Dedo 1 - 30 - 120
  digitalWrite(LED_BUILTIN, HIGH);
  for (teste = 30; teste <= 120; teste++)
  {
    finger1.write(teste);
    delay(5);
  }
  
  digitalWrite(LED_BUILTIN, LOW);
  for (teste = 120; teste >= 30; teste--)
  {
    finger1.write(teste);
    delay(5);
  }
 
  //Dedo 2 - 0 - 100
    digitalWrite(LED_BUILTIN, HIGH);
  for (teste = 0; teste <= 100; teste++)
  {
    finger2.write(teste);
    delay(5);
  }
  
  digitalWrite(LED_BUILTIN, LOW);
  for (teste = 100; teste >= 0; teste--)
  {
    finger2.write(teste);
    delay(5);
  }

//Dedo 3 - 0 - 100
    digitalWrite(LED_BUILTIN, HIGH);
  for (teste = 0; teste <= 100; teste++)
  {
    finger3.write(teste);
    delay(5);
  }
  
  digitalWrite(LED_BUILTIN, LOW);
  for (teste = 100; teste >= 0; teste--)
  {
    finger3.write(teste);
    delay(5);
  }

//Dedo 4 - 0 - 150
    digitalWrite(LED_BUILTIN, HIGH);
  for (teste = 0; teste <= 150; teste++)
  {
    finger4.write(teste);
    delay(5);
  }
  
  digitalWrite(LED_BUILTIN, LOW);
  for (teste = 150; teste >= 0; teste--)
  {
    finger4.write(teste);
    delay(5);
  }

//Dedo 5 - 90 - 170
    digitalWrite(LED_BUILTIN, HIGH);
  for (teste = 180; teste >= 90; teste--)
  {
    finger5.write(teste);
    delay(5);
  }
  
  digitalWrite(LED_BUILTIN, LOW);
  for (teste = 90; teste <= 180; teste++)
  {
    finger5.write(teste);
    delay(5);
  }

//Dedo 5 - 90 - 170
    digitalWrite(LED_BUILTIN, HIGH);

    finger1.write(30);
    finger2.write(0);
    finger3.write(0);
    finger4.write(0);
    finger5.write(170);
    delay(100);

  
  digitalWrite(LED_BUILTIN, LOW);

    finger1.write(120);
    finger2.write(100);
    finger3.write(100);
    finger4.write(150);
    finger5.write(90);
  delay(2000);

      digitalWrite(LED_BUILTIN, HIGH);

    finger1.write(30);
    finger2.write(0);
    finger3.write(0);
    finger4.write(0);
    finger5.write(170);
    delay(2000);

}
