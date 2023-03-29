#include <stdio.h>
#include <stdbool.h>
#include "listallcards.h"
#include "addandremove.h"
#include "remote.h"
#include "file.h"

int main(){

/*typedef struct {
    int cardNr;
    bool access;
    char date[100];
} Card;

typedef struct {
    Card *cards;
    int nrOfCards;
    bool lamp;
} State;*/

bool lamp = false;

    while(true){

        int menyChoice = menu();
        if(menyChoice == 1)
            remote(&lamp);
        else if(menyChoice == 2){
            noheap();
        }
        else if(menyChoice == 3){
            addAndRemove2();
            mergeFiles();
            FILE *f1=fopen("cardTemp.ini", "w");  // clear the temp file
            fclose(f1);
        }
        else if(menyChoice == 4)
            break;
        else if(menyChoice == 9)
            fakeScan();
    }
}