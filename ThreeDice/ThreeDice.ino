#include <MyDice.h>

int _buttonGeneral = 2;
int _diceButton1=11;
int _diceButton2=12;
int _iterateDice[3] = {1,1,1}; //1, 2
int _randomDiceNumber[3] = {0,0.0}; //1, 2
int _buttonStopDicePin[3] = {11,12,12};

MyDice dice1(3,4,5,6);
MyDice dice2(7,8,9,10);
MyDice dice3(A0,A1,A2,A3);
MyDice _AllDice[3] = {dice1,dice2,dice3};

void acknowledgeButtonPress(int diceNumber){
  _AllDice[diceNumber].flashAllLeds(2,200);
  _AllDice[diceNumber].lightNumber(_randomDiceNumber[diceNumber]);
}

void checkDiceStopStartButton(){
    for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){ // maybe use len(_AllDice) instead of two
      if (digitalRead(_buttonStopDicePin[diceNumber]) == LOW){
        if (_iterateDice[diceNumber] == 1){
          _iterateDice[diceNumber] = 0 ; // 0 means do not roll leave as is    
        }
        else {
          _iterateDice[diceNumber] = 1;          
        };  
        acknowledgeButtonPress(diceNumber);
      };
    };      
}

void checkButton() {
  delay (50);
  while (digitalRead(_buttonGeneral) == LOW) {
    checkDiceStopStartButton();
    delay(100);
  };
  delay (50);
  while (digitalRead(_buttonGeneral) == HIGH) {
    checkDiceStopStartButton();  
    delay(100);
  };
  randomSeed(millis());
}

void iterateNumbers(){
  for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){
    if (_iterateDice[diceNumber] == 1){
      _AllDice[diceNumber].turnOffDice();
      delay(300);
    };
  };
  for (int position = 1; position < 7; position++) {
    for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){
      if (_iterateDice[diceNumber] == 1){
          _AllDice[diceNumber].lightNumber(position);
          delay(50);
          _AllDice[diceNumber].turnOffDice();
          delay(50);
      };
    };
  };
}

void assignRandomNumber(){
  for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){
    if (_iterateDice[diceNumber] == 1){
      _randomDiceNumber[diceNumber] = random(1,7);
    };
  };
}

void lightDiceRamdomNumber(){
  for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){
    if (_iterateDice[diceNumber] == 1){
      _AllDice[diceNumber].lightNumber(_randomDiceNumber[diceNumber]);
      Serial.println(_randomDiceNumber[diceNumber]);
    };
  };
}

void throwDice() {
  int throwTimes = random(1,4);
  Serial.println("En Throw dice");
  randomSeed(millis()); //to have different randoms numbers each time the sketch runs
  for (int i = 0; i < throwTimes; i++){
    iterateNumbers();
  };  
  assignRandomNumber();
  lightDiceRamdomNumber();
  delay(20);
}

void twoDiceConcurrently(){
  checkButton();
  throwDice();
}

void oneDiceWithButton(){
  dice1.rollDice();
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,OUTPUT);
  digitalWrite(A0,HIGH);
  pinMode(_buttonGeneral, INPUT_PULLUP);
  pinMode(_diceButton1, INPUT_PULLUP);
  pinMode(_diceButton2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  //Serial.println(digitalRead(2));
  //dice1.rollDice();
  twoDiceConcurrently();
}
