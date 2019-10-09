#include <Keypad.h>

/* sketch 3 
turn on a LED when the button is pressed and let it on 
until the button is pressed again
*/
const int OnPinButton = 2;
const int OffPinButton = 4;
const int ledPin = 13;
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; 
byte colPins[COLS] = {8, 7, 6, 5};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);



void setup() {
  pinMode(OnPinButton, INPUT);
  pinMode(OffPinButton, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
  //Serial.print("Success");
 int checkOnButton = digitalRead(OnPinButton);  
 int checkOffButton = digitalRead(OffPinButton);

    if(checkOnButton == HIGH){
   
    digitalWrite(ledPin, LOW);
  }
  

  if(checkOffButton == HIGH){
   
    digitalWrite(ledPin, HIGH);
    
  }

  
}
