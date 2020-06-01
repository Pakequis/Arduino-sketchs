#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

File data_file;

const int temp = A0; 
float temperature;  
int chip_select_pin = 10;     
int count = 0;
int sample;

void setup() {

  Serial.begin(9600);
  pinMode(temp, INPUT);
  pinMode(chip_select_pin, OUTPUT);
  if (SD.begin())
  {
    Serial.println("Initialization Successful. Ready to use");
  } else
  {
    Serial.println("Initialization failed. Check your pin connections or change your SD card");
    return;
  }
}

void loop() 
{
  int i = 0;
  sample = 0;

  for (i = 0; i < 20; i++)
  {
    sample = sample + analogRead(temp);
    delay(50);
  }

  temperature = sample/20;
  temperature = (temperature * 500) / 1023;

  data_file = SD.open("temp.csv", FILE_WRITE);

  if (data_file) 
  {       
    count++;
    Serial.print(count);
    data_file.print(count);
    data_file.print(",");
    Serial.print(",");
    Serial.println(temperature);
    data_file.println(temperature);
    data_file.close();
  }
  else 
  {
    Serial.println("error opening your SD card file. Try again");
  }

  delay(9000);
}