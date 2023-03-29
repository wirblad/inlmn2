#ifndef ADDREMOVE_H
#define ADDREMOVE_H

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


int addAndRemove(State *state);
Card* searchCardNr(const State *state, int cardNr);
void foundCard(Card* card);
void addAndRemove2();

#endif