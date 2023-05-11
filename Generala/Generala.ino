#include <Generala.h>

int dice1[4] = {3,4,5,6};
int dice2[4] = {7,8,9,10};
Generala juego = Generala(2,dice1,dice2);;


void setup() {
Serial.begin(9600);
}

void loop() {
  Serial.println("Comenzando");
  juego.twoDiceConcurrently();

}
