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

char key[4][4] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'a', 'b'},
  {'c', 'd', 'e', 'f'}
};

int lastState[4][4] = {
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW}
};

int state[4][4] = {
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW}
};

int debounce[4][4] = {
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0}
};

int debounceCount[4][4] = {
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0}
};

int debounceDelay = 10;

void setup() {
  pinMode(column1, OUTPUT);
  pinMode(column2, OUTPUT);
  pinMode(column3, OUTPUT);
  pinMode(column4, OUTPUT);
  pinMode(PC13, OUTPUT);

  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  pinMode(row3, INPUT);
  pinMode(row4, INPUT);

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

void loop() {

  for(int col = 0; col < 4; col++) {
    for(int row = 0; row < 4; row++) {
      digitalWrite(column1, LOW);
      digitalWrite(column2, LOW);
      digitalWrite(column3, LOW);
      digitalWrite(column4, LOW);
      digitalWrite(columns[col], HIGH);

      int rowReading = digitalRead(rows[row]);

      if(rowReading != lastState[col][row]) {
        debounce[col][row] = millis();
      }

      if( (millis() - debounce[col][row]) > debounceDelay ) {

        if(debounceCount[col][row] < 10) {
          if(rowReading == lastState[col][row]) {
            debounce[col][row] = 0;
            debounceCount[col][row]++;
          } else {

            Keyboard.print("Reset");
            debounce[col][row] = 0;
            debounceCount[col][row] = 0;
          }
        } else {
          if(rowReading == HIGH && state[col][row] == LOW) {
            digitalWrite(PC13, LOW); // turn the LED on (HIGH is the voltage level)
            state[col][row] = HIGH;

            Keyboard.print(key[row][col]);

            debounce[col][row] = 0; // Reset debouncing
            debounceCount[col][row] = 0;
          } else if(rowReading == LOW && state[col][row] == HIGH) {
            digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level)
            state[col][row] = LOW;

            debounce[col][row] = 0; // Reset debouncing
            debounceCount[col][row] = 0;
          }
        }
      }
      lastState[col][row] = rowReading;
    }

    // if(digitalRead(row1) == HIGH && state[i][1] == LOW) {
    //   digitalWrite(PC13, LOW); // turn the LED on (HIGH is the voltage level)
    //   state[i][1] = HIGH;
    //   Keyboard.print("Hello");
    // } else if(digitalRead(row1) == HIGH) {
    //   digitalWrite(PC13, LOW); // turn the LED on (HIGH is the voltage level)
    // } else if(digitalRead(row1) == LOW) {
    //   digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level)
    //   state[i][1] = LOW;
    // }
    
    // if(digitalRead(row2) == HIGH && state[i][1] == OFF) {
    //   digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level) 
    //   currentKey = (i+1)*2;
    //   Keyboard.print("There!");
    // } else if(digitalRead(row3) == HIGH && state[i][1] == OFF) {
    //   digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level)
    //   currentKey = (i+1)*3;
    //   Keyboard.print("General");
    // } else if(digitalRead(row4) == HIGH && state[i][1] == OFF) {
    //   digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level) 
    //   currentKey = (i+1)*4;
    //   Keyboard.print("Kenobi");
    // } else {
    //   digitalWrite(PC13, LOW); // turn the LED on (HIGH is the voltage level) 
    //   currentKey = 0;
    // }
  }
}