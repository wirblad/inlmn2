#include <stdio.h>
#include <stdbool.h>
#include "listallcards.h"
#include "addandremove.h"
#include "remote.h"
#include "file.h"

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


State state = {NULL, 0, false};

//readNrOfCardsFromFile(&state);
//readAllCardsFromFile(&state);

    while(true){

        int menyChoice = menu();
    
        if(menyChoice == 1)
            remote(&state);
        else if(menyChoice == 2){
            noheap();
            //merge files
            //clear cardTemp
        }
            //listAllCards(&state);
        else if(menyChoice == 3)
            addAndRemove2();
            //merge files
            //clear cardTemp
            //addAndRemove(&state);
        else if(menyChoice == 4)
            break;
        else if(menyChoice == 9)
            fakeScan(&state);
    }
//saveNrOfCardsToFile(&state);
//saveAllCardsToFile(&state);

}