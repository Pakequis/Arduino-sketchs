/*******************************************
    SORTEADOR
    - Sorteia um numero entre 1 e 100

    Rodrigo Feliciano - 18/11/2017
    www.pakequis.com.br
    www.youtube.com/pakequis

    Como código original do shield de LCD e keypad
*/
#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

long rnd_n = 0;

// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);      // read the value from the sensor

  // For V1.0 comment the other threshold and use the one below:
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;

  return btnNONE;  // when all others fail, return this...
}

void setup()
{
  randomSeed(analogRead(1));  //Inicia o gerador de numeros aleatorios com o ruido
                              //do conversor AD

  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0, 0);
  lcd.print("pakequis.com.br");
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("   Sorteador   "); // print a simple message
}

void loop()
{
  lcd.setCursor(0, 1);           // move to the begining of the second line

  lcd.print("Pressione botao");
  lcd_key = read_LCD_buttons();

  while (lcd_key == btnNONE)
  {
    lcd_key = read_LCD_buttons();  // read the buttons
  }

  while (lcd_key != btnNONE)
  {
    rnd_n = random(1, 100); //Numero aleatorio de 1 a 100
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(7, 1);
    lcd.print(rnd_n);
    delay(50);
    lcd_key = read_LCD_buttons();
  }

  while (lcd_key == btnNONE)
  {
    lcd_key = read_LCD_buttons();
  }

  delay (1000);
}
