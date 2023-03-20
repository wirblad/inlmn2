#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "addandremove.h"
#include "safeinput.h"

int addAndRemove(State *state){

    int cardNr;
    while(!GetInputInt("Enter cardnumber: ", &cardNr))
        printf("Please enter a number\n");

    Card *card = searchCardNr(state, cardNr);  // RETURNERA CARD PEKARE ISTÄLLET

    //printf("TEST::::%d", &card->cardNr);

    if(card != NULL){           // LÄGG I FUNC

        if(card->access == true)
            printf("This card has access\n");
        else
            printf("This card has No access\n");

        int changeAccess;
        while(!GetInputInt("Enter 1 for access, 2 for no access ", &changeAccess) || (changeAccess != 1 && changeAccess != 2))
            printf("Please enter 1 or 2\n");

        if(changeAccess == 1){
            card->access = true;
        }
        else if(changeAccess == 2)   
            card->access = false;

        return 0; 
    }
        
    state->nrOfCards++;
    if(state->nrOfCards == 1)
        state->cards = (Card *)malloc(1 * sizeof(Card));
    else
        state->cards = (Card *)realloc(state->cards, state->nrOfCards * sizeof(Card));
    
    state->cards[state->nrOfCards-1].cardNr = cardNr;  // FUNC FÖR ATT SKAPA CARD ISTÄLLET
    state->cards[state->nrOfCards-1].access = true;
    setDate(state);
     
}

Card* searchCardNr(const State *state, int cardNr){

    for(int i = 0; i < state->nrOfCards;i++){

        if(cardNr == state->cards[i].cardNr)
            return &state->cards[i];
    }
    return NULL;
}

void setDate(State *state){

    char buff[100];
    time_t now = time(0);
    struct tm now_t = *localtime(&now);
    strftime (buff, 100, "%d-%m-%Y ", &now_t);

    strcpy(state->cards[state->nrOfCards-1].date, buff);    
}

