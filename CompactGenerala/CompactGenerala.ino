
int _buttonGeneral = 2;
int _diceButton1=11;
int _diceButton2=12;
int _diceButton3=20;
const int _diceTotal = 5;
const int lenghtDice = 4 ; //amount of pins dice
int _iterateDice[_diceTotal] = {1,1,1,1,1}; //1, 2
int _randomDiceNumber[_diceTotal] = {0,0,0,0,0}; //1, 2
int _buttonStopDicePin[_diceTotal] = {11,12,12,12,12};

//MyDice dice1(47,49,51,53);
int dice1[lenghtDice] = {38,40,42,44};
int dice2[lenghtDice] = {46,48,50,52};
int dice3[lenghtDice] = {31,33,35,37};
int dice4[lenghtDice] = {39,41,43,45};
int dice5[lenghtDice] = {47,49,51,53};
int _AllDice[_diceTotal] = {dice1,dice2,dice3,dice4,dice5};

void turnOnLeds (int toLight[], int lenghtToLight){
  for (int position = 0; position < lenghtToLight; position++) {
    digitalWrite(toLight[position], HIGH);
  };
};

void turnOffLeds (int toLight[], int lenghtToLight){
  for (int position = 0; position < lenghtToLight; position++) {
    digitalWrite(toLight[position], LOW);
  };
};

void flashLeds(int toLight[], int lenghtToLight, int flashTimes = 5, int delayLed = 100){
  Serial.println("En funcion flashleds");
  //Serial.println(toLight);
  for (int i = 0; i < flashTimes; i++){
    turnOnLeds(toLight,lenghtToLight);
    delay(delayLed);
    turnOffLeds(toLight,lenghtToLight);
    delay(delayLed);;
  };
}

void acknowledgeButtonPress(int diceNumber){
  Serial.println(diceNumber);
  Serial.println(_AllDice[diceNumber]);
  flashLeds(_AllDice[diceNumber],lenghtDice,6,100);
  //_AllDice[diceNumber].flashAllLeds(diceNumber,2,200);
  //_AllDice[diceNumber].lightNumber(_randomDiceNumber[diceNumber]);
}
/*
void checkDiceStopStartButton(){
    for  (int diceNumber = 0; diceNumber < _diceTotal; diceNumber ++){ // maybe use len(_AllDice) instead of two
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
  for  (int diceNumber = 0; diceNumber < _diceTotal; diceNumber ++){
    if (_iterateDice[diceNumber] == 1){
      _AllDice[diceNumber].turnOffDice();
      delay(300);
    };
  };
  for (int position = 1; position < 7; position++) {
    for  (int diceNumber = 0; diceNumber < _diceTotal; diceNumber ++){
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
  for  (int diceNumber = 0; diceNumber < _diceTotal; diceNumber ++){
    if (_iterateDice[diceNumber] == 1){
      _randomDiceNumber[diceNumber] = random(1,7);
    };
  };
}

void lightDiceRamdomNumber(){
  for  (int diceNumber = 0; diceNumber < _diceTotal; diceNumber ++){
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
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("En funcion setup");
  pinMode(_buttonGeneral, INPUT_PULLUP);
  pinMode(_diceButton1, INPUT_PULLUP);
  pinMode(_diceButton2, INPUT_PULLUP);
  //pinMode(_diceButton3, INPUT_PULLUP);
  for  (int pin = 31; pin < 54; pin ++){
    pinMode(pin,OUTPUT);
    //digitalWrite(pin,HIGH);
  }

}

void loop() {
  //Serial.println(digitalRead(2));
  //dice1.rollDice();
  //twoDiceConcurrently();
  for  (int i = 0; i < 5; i ++){
    acknowledgeButtonPress(i);
  }
}
