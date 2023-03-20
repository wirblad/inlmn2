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
} State;


State state = {NULL,0};

while(true){

    int menyChoice = menu();
    
    if(menyChoice == 2)
        listAllCards(&state);
    else if(menyChoice == 3)
        addAndRemove(&state);
    else if(menyChoice == 4)
        break;
    }
}