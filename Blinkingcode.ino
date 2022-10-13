//Homework 14 - Edit by J. Kent Wirant
//Homework 14 - Edit by Paul Kyros

//Setting up i/o
void setup() {
  pinMode(6, OUTPUT);
  pinMode(9, INPUT);
}

//Main  loop that has blinking light function
void loop() {
  if(digitalRead(9)==HIGH)
  {
    digitalWrite(6,HIGH);
    delay(500);
    digitalWrite(6,LOW);
    delay(500);
  }
  else
  {
    digitalWrite(6,LOW);
  }
}
