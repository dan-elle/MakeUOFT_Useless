#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int array[3]={};
void setup(){
   pinMode(13, OUTPUT);
   Serial.begin(9600);
   Serial.println("1"); //prints 1 to see if keypad works (at beginning)
}
  
void loop(){
  digitalWrite(13, HIGH);   // turn the LED on (making the voltage level HIGH)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off (making the voltage level LOW)
  delay(100);              // wait for a second
  
  char key = keypad.getKey();
  
  // storing inputted numbers in array
  if (Serial.available()>=3)
  {
      for (int i=0; i<4; i++)
      {
          array[i] = Serial.read();
      }
  }
  
  //printing keyboard inputs to screen
  if (key){
    Serial.println(key);
  }
  delay(10);
  Serial.flush();
}
