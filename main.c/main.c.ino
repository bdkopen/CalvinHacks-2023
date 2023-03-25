#include <Keyboard.h>

// Pin definitions of columns and rows.
#define column1 PB0
#define column2 PB1
#define column3 PB2
#define column4 PB10
#define row1 PA3
#define row2 PA2
#define row3 PA1
#define row4 PA0

// An array of pin values for columns and rows.
int columns[4] = {column1, column2, column3, column4};
int rows[4] = {row1, row2, row3, row4};

// Records the values of each key stroke.
char key[4][4] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'a', 'b'},
  {'c', 'd', 'e', 'f'}
};

// Array for recording the last state of a button. Used for debouncing.
int lastState[4][4] = {
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW}
};

// The current state of a button after debouncing.
int state[4][4] = {
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW}
};

// The time when a button was initially pressed.
int debounce[4][4] = {
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0}
};

// The milliseconds of delay for a debounce
int debounceDelay = 50;

void setup() {
  // Set all output pins
  pinMode(column1, OUTPUT);
  pinMode(column2, OUTPUT);
  pinMode(column3, OUTPUT);
  pinMode(column4, OUTPUT);
  pinMode(PC13, OUTPUT);

  // Set all input pins.
  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  pinMode(row3, INPUT);
  pinMode(row4, INPUT);


  // Initiate the Keyboard object that communicates over USB.
  Keyboard.begin();
}

void loop() {

  // Loop through
  for(int col = 0; col < 4; col++) {
    digitalWrite(column1, LOW);
    digitalWrite(column2, LOW);
    digitalWrite(column3, LOW);
    digitalWrite(column4, LOW);
    digitalWrite(columns[col], HIGH);

    for(int row = 0; row < 4; row++) {

      // Read the value of the row for the current column.
      int rowReading = digitalRead(rows[row]);

      // If the state has changed, reset the debouncing timer.
      if(rowReading != lastState[col][row]) {
        debounce[col][row] = millis();
      }

      // If the debounce time is longer then the delay trigger the key change.
      if( (millis() - debounce[col][row]) > debounceDelay ) {
          if(rowReading == HIGH && state[col][row] == LOW) {
            // Turn on the blue LED to indicate a key is pressed.
            digitalWrite(PC13, LOW);
            state[col][row] = HIGH;

            // Press the key corresponding to the row and column.
            Keyboard.print(key[row][col]);

            debounce[col][row] = 0; // Reset debouncing
          } else if(rowReading == LOW && state[col][row] == HIGH) {
            // Turn off the blue LED to indicate a key is released.
            digitalWrite(PC13, HIGH);
            state[col][row] = LOW;

            debounce[col][row] = 0; // Reset debouncing
          }
        }
      lastState[col][row] = rowReading;
    }
  }
}