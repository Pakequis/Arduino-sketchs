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

byte buff[255];
int ix = 0;
int stat = 0;
int val[5];

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
  
  Serial.begin(9600);
  while (!Serial){};
}

void loop() {
  // put your main code here, to run repeatedly:

  switch (stat)
  {
    //receive one string
    case 0:
      while(Serial.available() > 0)
      {
        char rx = Serial.read();
        if(rx == '\n')
        {
          stat = 1;
          buff[ix] = '\0';
          ix = 0;
        }else
        {
          buff[ix] = rx;
          ix++;
        }
    }
    break;

    //parse the string
    case 1:
      if (sscanf(buff, "%d,%d,%d,%d,%d", &val[0], &val[1], &val[2], &val[3], &val[4]) == 5) 
      {
        set_servos(val);
        //Serial.println(val[0]);
        //Serial.println(val[1]);
        //Serial.println(val[2]);
        //Serial.println(val[3]);
        //Serial.println(val[4]);
      }
      stat = 0;
      ix = 0;
      break;
    
    default:
      stat = 0;
      ix = 0;
      break;
  }
}

void set_servos(int *val)
{
  finger1.write(map(val[0],0,274,120,30));
  finger2.write(map(val[1],0,121,100,0));
  finger3.write(map(val[2],0,202,100,0));
  finger4.write(map(val[3],0,181,150,0));
  finger5.write(map(val[4],0,284,90,180));
}
