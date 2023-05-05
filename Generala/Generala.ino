#include <Generala.h>

int dice1[4] = {6,7,8,9};
int dice2[4] = {6,7,8,9};
Generala juego = Generala(2,dice1,dice2);;


void setup() {

}

void loop() {
  juego.twoDiceConcurrently();

}
