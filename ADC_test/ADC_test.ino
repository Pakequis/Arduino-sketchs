/*
  Arduino ADC Sampling rate test
  Rodrigo Feliciano - 10/01/2018
  www.pakequis.com.br
*/
#define N_SAMPLES 10000

unsigned long test;
float tmp = 0;
word i;
word dumb_read; 

void setup() 
{
  //resolution 8, 10 or 12 bits
  //analogReadResolution(12); //Arduino Due
  //analogReadResolution(10); //Arduino Due
  //analogReadResolution(8);  //Arduino Due
  Serial.begin(9600);
}

void loop() 
{  
  test = millis();

  //ADC Test
  for(i=0;i<N_SAMPLES;i++) dumb_read = analogRead(0);

  tmp = (millis() - test);
  tmp = (N_SAMPLES/tmp) * 1000; //1000ms = 1s
  
  Serial.print(tmp);
  Serial.print(" - ");
  Serial.println(dumb_read);
  delay(1000);
}

