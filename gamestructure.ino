//Gamestate 0 = start screen
//Gamestate 1 = Playing screen
//Gamestate 2 = Game Over Screen
//Gamestate 3 = Pause Screen
//Got correctanswer, wronganswer, game won, and game end will all be functions called for intermittent screen choices


//Setting global variables
const byte interruptPin = 2;
int level = 0, randtest = 0, timevar, lives, gamestate = 0;
String randteststr, answer;
bool answerb, gamestartb;

//-----------Setup-------------------
void setup() {
//For Serial communications. Can be taken out later
Serial.begin(9600);

//Setting up interupt for pause screen
pinMode(interruptPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin), buttonPressed1, FALLING);
}

//-------------Interupts---------------
void buttonPressed1()          
{
  //The goal is to save the previous screen state here. Then switch to pause screen state. Then in the exit button, it returns to original screen state                   
   bool exitb = true;
   Serial.println("You are now in the pause screen");
   Serial.println("Please press 0 to exit");
   while(!exitb){
        if(Serial.available()){
          if(Serial.readStringUntil('\n').toInt() == 1){
            exitb = true;
        }
      }
    }
}

//--------------Functions---------------------
//void setscreento(){}

//void restartgame(){level = 0}

//--------------Main Loop--------------------
void loop() {

//--Base Level---
if (level == 0){
  //set everything back to base one
  gamestate = 0;
  //setscreento(gamestate);
  level = 1;
  lives = 3;
  Serial.println("Please enter 1 to start the game: ");
  while(gamestate = 0){
        if(Serial.available()){
          if(Serial.readStringUntil('\n').toInt() == 1){
            gamestate = 1;
            //setscreento(gamestate);
        }
      }
    }
  }
  
//----Levels 1 to 100-------------
else if(level >=1 or level < 100){
  //Randomly picks the actions and prompts the user to complete
  Serial.print("You're cuurently on level ");
  Serial.println(level);
  randtest = random(0,3);
  if (randtest == 0)     {Serial.println("Please enter the number 0");}
  else if (randtest == 1){Serial.println("Please enter the number 1");}
  else if (randtest == 2){Serial.println("Please enter the number 2");}
  else if (randtest == 3){Serial.println("Please enter the number 3");}

  //Prompts the user to enter input and compares
  answer = "N/A";
  
  timevar = millis();
  while(millis()-timevar <= 5000){
    if(Serial.available()){
        answer = Serial.readStringUntil('\n');
        break;
      }
    }

  if(randtest == answer.toInt()){Serial.println("You entered the correct answer!"); 
    if(level == 100){Serial.println("YOU WON!"); level = 0;}
    level +=1 ;}
  else{
    if(lives == 0){
      Serial.println("GAME OVER");
      level = 0;
      }
    Serial.println("You entered the incorrect answer :( "); lives -= 1;
    Serial.print("You have "); Serial.print(lives); Serial.println(" lives left");}
    
}

}
