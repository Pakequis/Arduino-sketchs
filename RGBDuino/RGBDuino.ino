/*
  Test sketch for RGBDuino board
  Rodrigo Feliciano
  https://www.pakequis.com.br
*/
#include <Adafruit_NeoPixel.h>

int n = 0;
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, 13, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, 12, NEO_GRB + NEO_KHZ800);

void setup() {
  for (n = 2; n <= 13; n++)
  {
    pinMode(n, OUTPUT); //LED pins
  }

  //Neopixel LEDs start
  strip1.begin();
  strip2.begin();
  strip1.show();
  strip2.show();
}

void loop() {
  //LED test
  for(n = 2; n <= 13; n++)
  {
    digitalWrite(n, HIGH);  
    delay(100);
  }

  for(n = 2; n <= 13; n++)
  {
    digitalWrite(n, LOW);
    delay(100);
  }

  delay (100);

  //Buzzer two tones test
  for(n = 0; n < 10; n++)
  {
    tone(8, 500);
    delay(250);
    tone(8, 1000);
    delay(250);
  }

  noTone(8);  //Tone off

  //RGB LEDs test
  strip1.setPixelColor(0,strip1.Color(255,0,0));
  strip2.setPixelColor(0,strip2.Color(0,0,255));
  strip1.show();
  strip2.show();
  delay(500);

  strip1.setPixelColor(0,strip1.Color(0,0,255));
  strip2.setPixelColor(0,strip2.Color(255,0,0));
  strip1.show();
  strip2.show();
  delay(500);

  strip1.setPixelColor(0,strip1.Color(255,255,0));
  strip2.setPixelColor(0,strip2.Color(255,0,255));
  strip1.show();
  strip2.show();
  delay(500);

  strip1.setPixelColor(0,strip1.Color(255,0,255));
  strip2.setPixelColor(0,strip2.Color(255,255,0));
  strip1.show();
  strip2.show();
  delay(500);

  strip1.setPixelColor(0,strip1.Color(0,0,0));
  strip2.setPixelColor(0,strip2.Color(0,0,0));
  strip1.show();
  strip2.show();
  delay(500);  
  
}
