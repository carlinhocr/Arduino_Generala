#ifndef Generala_h
#define Generala_h
#include "Arduino.h"
#include "MyDice.h"
class Generala {
public:
        Generala();
        void twoDiceConcurrently();
private:
        int _buttonGeneral;
        int _diceButton1;
        int _diceButton2;
        int _iterateDice[2];
        int _randomDiceNumber[2];
        int _buttonStopDicePin[2];
        MyDice dice1;
        MyDice dice2;
        MyDice _AllDice[2];
        void acknowledgeButtonPress(int diceNumber);
        void checkDiceStopStartButton();
        void checkButton();
        void iterateNumbers();
        void assignRandomNumber();
        void lightDiceRamdomNumber();
        void throwDice();
        void oneDiceWithButton();
};
#endif