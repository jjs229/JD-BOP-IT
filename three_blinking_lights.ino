//Homework 14 - Edit by J. Kent Wirant

void setup() {
  //Setting up I/O
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
}
void loop() {
  //This is the loop that goes across the three LED's
  if(digitalRead(9)==HIGH)
  {
    digitalWrite(6,HIGH);
    delay(500);
    digitalWrite(6,LOW);
    delay(500);
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(500);
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    delay(500);
  }
  else
  {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
}
