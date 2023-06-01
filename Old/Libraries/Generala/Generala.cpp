#include "Arduino.h"
#include "MyDice.h"
#include "Generala.h"


Generala::Generala(){
  Serial.println("hola en la clase Generala DEFAULT CONSTRUCTOR");
  
  // defaults
  for (int i=0;i<4;i++){
    _pinsDice1[i]=defaultPins[i];
    _pinsDice2[i]=defaultPins[i];
  };
  _numberOfPlayers = 2;

  _buttonGeneral = 2;
  _diceButton1=11;
  _diceButton2=12;
  for (int i=0;i<2;i++){
    _iterateDice[i] = 1; //1, 1
    _randomDiceNumber[i] = 0; //1, 1
  };
  _buttonStopDicePin[0] = _diceButton1;  
  _buttonStopDicePin[1] = _diceButton2;

  setPins(_numberOfPlayers,_pinsDice1[4],_pinsDice2[4]);

  pinMode(_buttonGeneral, INPUT_PULLUP);
  pinMode(_diceButton1, INPUT_PULLUP);
  pinMode(_diceButton2, INPUT_PULLUP);
}
Generala::Generala(int numberOfPlayers,int pinsDice1[4], int pinsDice2[4]){
  Serial.println("hola en la clase Generala");
  _buttonGeneral = 2;
  _diceButton1=11;
  _diceButton2=12;
  for (int i=0;i<2;i++){
    _iterateDice[i] = 1; //1, 1
    _randomDiceNumber[i] = 0; //1, 1
  };
  _buttonStopDicePin[0] = _diceButton1;  
  _buttonStopDicePin[1] = _diceButton2;

  setPins(numberOfPlayers,pinsDice1[4],pinsDice2[4]);

  pinMode(_buttonGeneral, INPUT_PULLUP);
  pinMode(_diceButton1, INPUT_PULLUP);
  pinMode(_diceButton2, INPUT_PULLUP);
}

void Generala::setPins(int numberOfPlayers,int pinsDice1[4], int pinsDice2[4]){
  _numberOfPlayers = numberOfPlayers;
  Serial.println("Setting Pins");
  for (int i=0;i<4;i++){
    _pinsDice1[i]=pinsDice1[i];
    _pinsDice2[i]=pinsDice2[i];
  };
  Serial.print("Setting Pins Dice 1 ");
  for (int i=0;i<4;i++){
    Serial.print(_pinsDice1[i]);
    Serial.print(",");
  };
  Serial.println(" ");
  Serial.print("Setting Pins Dice 2 ");
  for (int i=0;i<4;i++){
    Serial.print(_pinsDice2[i]);
    Serial.print(",");
  };
  Serial.println(" ");
  Serial.print("Setting MyDice from Generala ");
  _AllDice[0].setPins(_pinsDice1[0],_pinsDice1[1],_pinsDice1[2],_pinsDice1[3]);
  _AllDice[1].setPins(_pinsDice2[0],_pinsDice2[1],_pinsDice2[2],_pinsDice2[3]);
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
  // MyDice dice1 = MyDice(6,3,5,4);
  // MyDice dice2 = MyDice(7,8,9,10);
  checkButton();
  throwDice();
}

void Generala::oneDiceWithButton(){
  _AllDice[0].rollDice();
}

