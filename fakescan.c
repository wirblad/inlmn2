#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "fakescan.h"
#include "safeinput.h"
#include "addandremove.h"

void fakeScan(State *state){

    int cardNr;
    while(GetInputInt("Please scan card to enter or X(ANY CHAR) to go back to admin menu\n", &cardNr)){

    Card *card = searchCardNr(state, cardNr);

        if(card != NULL){          
            if(card->access == false){
                state->lamp = false;
                printf("CURRENTLY LAMP IS RED\n");
            }
            else if(card->access == true){
                state->lamp = true;
                printf("CURRENTLY LAMP IS GREEN\n");
            }
        }
        else
            printf("COULD NOT FIND CARD\n");
    }
}