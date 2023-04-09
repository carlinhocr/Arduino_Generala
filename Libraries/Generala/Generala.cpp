#include "Arduino.h"
#include "MyDice.h"
#include "Generala.h"
Generala::Generala(int numberOfPlayers) {
        int _buttonGeneral = 2;
        int _diceButton1=11;
        int _diceButton2=12;
        int _numberOfPlayers = numberOfPlayers;
        pinMode(_buttonGeneral, INPUT_PULLUP);
        pinMode(_diceButton1, INPUT_PULLUP);
        pinMode(_diceButton2, INPUT_PULLUP);
        Serial.println("hola en la clase Generala");
        int _iterateDice[2] = {1,1}; //1, 1
        int _randomDiceNumber[2] = {0,0}; //1, 1
        int _buttonStopDicePin[2] = {11,12};
        dice1(6,3,5,4);
        dice2(7,8,9,10);
        _AllDice[2] = {dice1,dice2};
}

void Generala::acknowledgeButtonPress(int diceNumber){
  _AllDice[diceNumber].flashAllLeds(2,200);
  _AllDice[diceNumber].lightNumber(_randomDiceNumber[diceNumber]);
}

void Generala::checkDiceStopStartButton(){
    for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){
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

void Generala::checkButton() {
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

void Generala::iterateNumbers(){
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

void Generala::assignRandomNumber(){
  for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){
    if (_iterateDice[diceNumber] == 1){
      _randomDiceNumber[diceNumber] = random(1,7);
    };
  };
}

void Generala::lightDiceRamdomNumber(){
  for  (int diceNumber = 0; diceNumber < 2; diceNumber ++){
    if (_iterateDice[diceNumber] == 1){
      _AllDice[diceNumber].lightNumber(_randomDiceNumber[diceNumber]);
    };
  };
}

void Generala::throwDice() {
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

void Generala::twoDiceConcurrently(){
  checkButton();
  throwDice();
}

void Generala::oneDiceWithButton(){
  dice1.rollDice();
}

