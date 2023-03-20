#include <stdio.h>
#include <stdbool.h>
#include "listallcards.h"
#include "addandremove.h"

int main(){

typedef struct {
    int cardNr;
    bool access;
    char date[100];
} Card;

typedef struct {
    Card *cards;
    int nrOfCards;
    bool lamp;
} State;


State state = {NULL,0, false};

while(true){

    int menyChoice = menu();
    
    if(menyChoice == 1)
        remote(&state);
    else if(menyChoice == 2)
        listAllCards(&state);
    else if(menyChoice == 3)
        addAndRemove(&state);
    else if(menyChoice == 4)
        break;
    else if(menyChoice == 9)
        fakeScan(&state);
    }
}