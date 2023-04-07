#include "Arduino.h"
#include "MyDice.h"
MyDice::MyDice(int diceDiagonal1, int diceDiagonal2,
        int diceMiddleLeds, int diceCenterLed) {
        pinMode(diceDiagonal1, OUTPUT);
        pinMode(diceDiagonal2, OUTPUT);
        pinMode(diceMiddleLeds, OUTPUT);
        pinMode(diceCenterLed, OUTPUT);
        Serial.println("hola");
        lenghtDice =  4;
        lenghtNumber1 =  1;
        lenghtNumber2 =  1;
        lenghtNumber3 =  2;
        lenghtNumber4 =  2;
        lenghtNumber5 =  3;
        lenghtNumber6 =  3;
        _diceDiagonal1 = diceDiagonal1;
        _diceDiagonal2 = diceDiagonal2;
        _diceMiddleLeds = diceMiddleLeds;
        _diceCenterLed = diceCenterLed;
        _dice[0] = _diceDiagonal1;
        _dice[1] = _diceDiagonal2;
        _dice[2] = _diceMiddleLeds;
        _dice[3] = _diceCenterLed;
        number1[0] = _diceCenterLed;
        number2[0] = _diceDiagonal1;
        number3[0] = _diceCenterLed;
        number3[1] = _diceDiagonal1;
        number4[0] = _diceDiagonal1;
        number4[1] = _diceDiagonal2;
        number5[0] = _diceDiagonal1;
        number5[1] = _diceDiagonal2;
        number5[2] = _diceCenterLed;
        number6[0] = _diceDiagonal1;
        number6[1] = _diceDiagonal2;
        number6[2] = _diceMiddleLeds;

    }

void MyDice::rollDice(){
  //iterateLeds(_dice,lenghtDice);
  //flashLeds(_dice,lenghtDice);
  checkButton();
  throwDice(); 
};

void MyDice::throwDice() {
  //light up dice randomly
  //turn on dice number
  Serial.println("En Throw dice");
  randomSeed(millis()); //to have different randoms numbers each time the sketch runs
  int diceNumber = random(1,7);
  int throwTimes = random(1,4);
  Serial.println("diceNumber");
  Serial.println(diceNumber);
  for (int i = 0; i < throwTimes; i++){
    iterateNumbers(_dice,lenghtDice,200);
  }  
  lightNumber(diceNumber);
  delay(20);
}

void MyDice::turnOffDice(){
  turnOffLeds(_dice,lenghtDice);
}

void MyDice::turnOffLeds (int toLight[], int lenghtToLight){
  for (int position = 0; position < lenghtToLight; position++) {
    digitalWrite(toLight[position], LOW);
  };
};

void MyDice::turnOnLeds (int toLight[], int lenghtToLight){
  for (int position = 0; position < lenghtToLight; position++) {
    digitalWrite(toLight[position], HIGH);
  };
};

void MyDice::iterateLeds(int toLight[], int lenghtToLight) {
  //ITERATOR to test all output pins
  for (int position = 0; position < lenghtToLight; position++) {
    digitalWrite(toLight[position], HIGH);
    delay(1000);
    digitalWrite(toLight[position], LOW);
  };
}

void MyDice::flashAllLeds(int flashTimes = 2, int delayLed = 100){
  flashLeds(_dice,lenghtDice,flashTimes,delayLed);
}

void MyDice::flashLeds(int toLight[], int lenghtToLight, int flashTimes = 5, int delayLed = 100){
  for (int i = 0; i < flashTimes; i++){
    turnOnLeds(toLight,lenghtToLight);
    delay(delayLed);
    turnOffLeds(toLight,lenghtToLight);
    delay(delayLed);;
  };
}

void MyDice::lightNumber(int number){
  switch (number)  {
   
    case 1:
        turnOnLeds(number1, lenghtNumber1);
        break;
    case 2:
        turnOnLeds(number2, lenghtNumber2);
        break;
    case 3:
        turnOnLeds(number3, lenghtNumber3);
        break;
    case 4:
        turnOnLeds(number4, lenghtNumber4);
        break;
    case 5:
        turnOnLeds(number5, lenghtNumber5);
        break;
    case 6:
        turnOnLeds(number6, lenghtNumber6);
        break;
    default:
        //do nothing
        Serial.println("Not a valid dice number");
        Serial.println(number);
        break;
  };
}

void MyDice::iterateNumbers(int toLight[], int lenghtToLight, int delayNumbers = 1000){
  turnOffLeds(toLight,lenghtToLight);
  delay(300);
  for (int position = 1; position < 7; position++) {
    lightNumber(position);
    delay(delayNumbers);
    turnOffLeds(toLight,lenghtToLight);
    delay(delayNumbers/2);
  };
}

void MyDice::testDice () {
  flashLeds(_dice,lenghtDice,4,200);
  delay(1000);
  iterateLeds(_dice, lenghtDice);
  delay(1000);
  iterateNumbers(_dice, lenghtDice);
  delay(1000);
  iterateNumbers(_dice, lenghtDice, 150);
  delay(1000);
  turnOffLeds(_dice,lenghtDice);
  delay(1000);
}
