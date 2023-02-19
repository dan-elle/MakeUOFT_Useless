#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
char customKey;
int original[5] = {2, 2, 2, 2, 2};
int *checker = original;
int array0[] = {1, 1, 1, 1, 1};
int array1[] = {0, 1, 1, 1, 1};
int array2[] = {0, 0, 1, 1, 1};
int array3[] = {0, 0, 0, 1, 1};
int array4[] = {0, 0, 0, 0, 1};
int array5[] = {0, 0, 0, 0, 0};
int array6[] = {1, 0, 0, 0, 0};
int array7[] = {1, 1, 0, 0, 0};
int array8[] = {1, 1, 1, 0, 0};
int array9[] = {1, 1, 1, 1, 0};

void morseCode(int array[]) {
  for (int i = 0; i < 5; i++) {
    /*digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);*/
    if (array[i] == 0) {
      digitalWrite(13, HIGH);
      delay(500);
    } else if (array[i] == 1) {
      digitalWrite(13, HIGH);
      delay(1500);
    }
    digitalWrite(13, LOW);
    delay(1000);
  }
}

����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������void setup()
{
  //setting up the led light
  pinMode(13, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Enter Number: ");
  //poo();
  // Print a message to the LCD.

}

void loop()
{
  int doneLoop = 0;
  while (doneLoop == 0) {
    char customKey = customKeypad.getKey();
    switch (customKey) {
      case '0':
        lcd.setCursor(0, 1);
        lcd.print('0');
        checker = array0;
        morseCode(checker);
        break;
      case '1':
        lcd.setCursor(0, 1);
        lcd.print('1');
        checker = array1;
        morseCode(checker);
        break;
      case '2':
        lcd.setCursor(0, 1);
        lcd.print('2');
        checker = array2;
        morseCode(checker);
        break;
      case '3':
        lcd.setCursor(0, 1);
        lcd.print('3');
        checker = array3;
        morseCode(checker);
        break;
      case '4':
        lcd.setCursor(0, 1);
        lcd.print('4');
        checker = array4;
        morseCode(checker);
        break;
      case '5':
        lcd.setCursor(0, 1);
        lcd.print('5');
        checker = array5;
        morseCode(checker);
        break;
      case '6':
        lcd.setCursor(0, 1);
        lcd.print('6');
        checker = array6;
        morseCode(checker);
        break;
      case '7':
        lcd.setCursor(0, 1);
        lcd.print('7');
        checker = array7;
        morseCode(checker);
        break;
      case '8':
        lcd.setCursor(0, 1);
        lcd.print('8');
        checker = array8;
        morseCode(checker);
        break;
      case '9':
        lcd.setCursor(0, 1);
        lcd.print('9');
        checker = array9;
        morseCode(checker);
        break;
      case '#':
        lcd.setCursor(0, 1);
        lcd.print("End!");
        doneLoop = 1;
        break;
    }
  }
  /*char customKey = customKeypad.getKey();
    if (customKey) {
    lcd.setCursor(0, 0);
    lcd.print("Enter Number: ");

    }
  */
}
