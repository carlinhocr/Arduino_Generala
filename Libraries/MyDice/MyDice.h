#ifndef MyDice_h
#define MyDice_h
#include "Arduino.h"
class MyDice {
public:
        MyDice(int diceDiagonal1, int diceDiagonal2,
        int diceMiddleLeds, int diceCenterLed);
        void rollDice();
        void throwDice();
        void turnOffDice();
        void lightNumber(int number);
        void flashAllLeds(int flashTimes, int delayLed);
private:
        int _diceDiagonal1;
        int _diceDiagonal2;
        int _diceMiddleLeds;
        int _diceCenterLed;
        int lenghtDice;
        int lenghtNumber1;
        int lenghtNumber2;
        int lenghtNumber3;
        int lenghtNumber4;
        int lenghtNumber5;
        int lenghtNumber6;
        void turnOffLeds (int dice[], int lenghtDice);
        void turnOnLeds (int dice[], int lenghtDice);
        void iterateLeds(int dice[], int lenghtDice);
        void flashLeds(int dice[], int lenghtDice, int flashTimes = 5, int delayLed = 100);
        void iterateNumbers(int dice[], int lenghtDice, int delayNumbers = 1000);
        void testDice ();
        void checkButton();
        int _dice[4];
        int number1[1];
        int number2[1];
        int number3[2];
        int number4[2];
        int number5[3];
        int number6[3];


};
#endif