#ifndef FILE_H
#define FILE_H

#include "addandremove.h"

void saveNrOfCardsToFile(State *state);
void readNrOfCardsFromFile(const State *state);
void readAllCardsFromFile(State *state);
void saveAllCardsToFile(State *state);


#endif