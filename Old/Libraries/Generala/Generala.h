#ifndef Generala_h
#define Generala_h
#include "Arduino.h"
#include "MyDice.h"
class Generala {
public:
        Generala();
        Generala(int numberOfPlayers, int pinsDice1[4], int pinsDice2[4]);  
        void twoDiceConcurrently();
        void setPins(int numberOfPlayers,int pinsDice1[4], int pinsDice2[4]);
        int defaultPins[4] ={6,7,8,9};
private:
        int _buttonGeneral;
        int _diceButton1;
        int _diceButton2;
        int _numberOfPlayers;
        int _iterateDice[2];
        int _randomDiceNumber[2];
        int _buttonStopDicePin[2];
        int _pinsDice1[4];
        int _pinsDice2[4];
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