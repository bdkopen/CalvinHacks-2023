#include <Keyboard.h>

#define column1 PB0
#define column2 PB1
#define column3 PB2
#define column4 PB10

#define row1 PA3
#define row2 PA2
#define row3 PA1
#define row4 PA0

int columns[4] = {column1, column2, column3, column4};
int rows[4] = {row1, row2, row3, row4};

int key[4][4] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16}
};

void setup() {
  // put your setup code here, to run once:
  pinMode(column1, OUTPUT);
  pinMode(column2, OUTPUT);
  pinMode(column3, OUTPUT);
  pinMode(column4, OUTPUT);
  pinMode(PC13, OUTPUT);

  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  pinMode(row3, INPUT);
  pinMode(row4, INPUT);

  // Initialize unused pins as inputs in attempt to reduce noise.
  // Ideally these pins would be physically grounded, however this is an oversight in the PCB design.
  pinMode(PA4, INPUT);
  pinMode(PA5, INPUT);
  pinMode(PA6, INPUT);
  pinMode(PA7, INPUT);
  pinMode(PA8, INPUT);
  pinMode(PA9, INPUT);
  pinMode(PA10, INPUT);
  pinMode(PA11, INPUT);
  pinMode(PA12, INPUT);
  pinMode(PA13, INPUT);
  pinMode(PA14, INPUT);
  pinMode(PA15, INPUT);
  pinMode(PC14, INPUT);
  pinMode(PC15, INPUT);
  pinMode(PB3, INPUT);
  pinMode(PB4, INPUT);
  pinMode(PB5, INPUT);
  pinMode(PB6, INPUT);
  pinMode(PB7, INPUT);
  pinMode(PB8, INPUT);
  pinMode(PB9, INPUT);
  pinMode(PB12, INPUT);
  pinMode(PB13, INPUT);
  pinMode(PB14, INPUT);
  pinMode(PB15, INPUT);

  Keyboard.begin();
}

int currentKey = 0;

void loop() {

  for(int i = 0; i < 4; i++) {
    digitalWrite(column1, LOW);
    digitalWrite(column2, LOW);
    digitalWrite(column3, LOW);
    digitalWrite(column4, LOW);
    digitalWrite(columns[i], HIGH);

    if(digitalRead(row1) == HIGH && currentKey == 0) {
      digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level)
      currentKey = (i+1);
      Keyboard.print("Hello");
    } else if(digitalRead(row2) == HIGH && currentKey == 0) {
      digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level) 
      currentKey = (i+1)*2;
      Keyboard.print("There!");
    } else if(digitalRead(row3) == HIGH && currentKey == 0) {
      digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level)
      currentKey = (i+1)*3;
      Keyboard.print("General");
    } else if(digitalRead(row4) == HIGH && currentKey == 0) {
      digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level) 
      currentKey = (i+1)*4;
      Keyboard.print("Kenobi");
    } else {
      digitalWrite(PC13, LOW); // turn the LED on (HIGH is the voltage level) 
      currentKey = 0;
    }
    delay(100);
  }
}