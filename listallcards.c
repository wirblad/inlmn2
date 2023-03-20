#include <stdio.h>
#include <stdbool.h>
#include "listallcards.h"

int listAllCards(const State *state){

    printf("ALL CARDS IN SYSTEM\n");

    for(int i = 0; i < state->nrOfCards;i++){
        
        printf("%d ", state->cards[i].cardNr);
        if(state->cards[i].access == true)
            printf("Access ");
        else    
            printf("No access ");
        printf("Added to system: %s\n", state->cards[i].date);
    }

    printf("Press key to continue\n");
    getch();
    return 0;
}