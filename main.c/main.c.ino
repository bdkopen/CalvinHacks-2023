#define column1 PB0
#define column2 PB1
#define column3 PB2
#define column4 PB10

#define row1 PA3
#define row2 PA2
#define row3 PA1
#define row4 PA0

void setup() {
  // put your setup code here, to run once:
  pinMode(column1, OUTPUT);
  pinMode(column2, OUTPUT);
  //pinMode(column3, OUTPUT);
  // pinMode(column4, OUTPUT);
  pinMode(PC13, OUTPUT);

  // pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  // pinMode(row3, INPUT);
  // pinMode(row4, INPUT);
}

void loop() {
  digitalWrite(column1, LOW);
  digitalWrite(column2, HIGH);
  //digitalWrite(column3, LOW);
  // digitalWrite(column4, LOW);

  if(digitalRead(row2) == HIGH) {
    digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level) 
  } else {
    digitalWrite(PC13, LOW); // turn the LED on (HIGH is the voltage level) 
  }
  delay(1);
}