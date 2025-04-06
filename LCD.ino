// C++ code
//
/*
  LiquidCrystal Library - Hello World

   Demonstrates the use of a 16x2 LCD display.
  The LiquidCrystal library works with all LCD
  displays that are compatible with the  Hitachi
  HD44780 driver. There are many of them out
  there, and you  can usually tell them by the
  16-pin interface.

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008  by David
  A. Mellis
  library modified 5 Jul 2009  by Limor Fried
  (http://www.ladyada.net)
  example added 9 Jul 2009  by Tom Igoe
  modified 22 Nov 2010  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

#include <LiquidCrystal.h>
//#include <SevSeg.h>

int seconds = 0;
int i=0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


byte zero[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte one[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};

byte two[] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
};

byte three[] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};

byte four[] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};

byte five[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};


String activities[] = {"Learning a language", "Sport", "Reading" , "Family time"}; 

void setup()
{
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.

  lcd.createChar(0, zero);
  lcd.createChar(1, one);
  lcd.createChar(2, two);
  lcd.createChar(3, three);
  lcd.createChar(4, four);
  lcd.createChar(5, five);
}

void loop() {
  while(i==4)
  {
      lcd.setCursor(0,0);
      lcd.print("                    ");
      lcd.setCursor(0,0);
      lcd.print("Start again?");
      int sensorValue=analogRead(A1);
      float voltage=sensorValue*(5.0/1023.0);
      if(voltage>3)
      {
        i=0;
      }
      delay(100);
  }
  while(i < 4) {
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
  	lcd.print(activities[i]);
    
    for(int i=0; i <= 100; i++)
    {
      //lcd.print("   ");
      lcd.setCursor(16, 1);
      lcd.print(i);
      lcd.setCursor(19, 1);
      lcd.print("%");
      updateProgressBar(i, 100, 1);   //This line calls the subroutine that displays the progress bar.  The 3 arguments are the current count, the total count and the line you want to print on.
      delay(50);
    }

    lcd.setCursor(0, 1);
    lcd.print("                    ");

    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
  	lcd.print("Break :D");
    delay(1500);
    while(i==3)
    {
      lcd.setCursor(0,0);
      lcd.print("                    ");
      lcd.setCursor(0,0);
      lcd.print("Start again?");
      int sensorValue=analogRead(A1);
      float voltage=sensorValue*(5.0/1023.0);
      if(voltage>3)
      {
        i=0;
      }
      delay(100);
    }
    i++;
  }
}


void updateProgressBar(unsigned long count, unsigned long totalCount, int lineToPrintOn)
 {
    double factor = totalCount/80.0;          //See note above!
    int percent = (count+1)/factor;
    int number = percent/5;
    int remainder = percent%5;                                                                      
    if(number > 0)
    {
       lcd.setCursor(number-1,lineToPrintOn);
       lcd.write(5);
    }
   
       lcd.setCursor(number,lineToPrintOn);
       lcd.write(remainder);   
 