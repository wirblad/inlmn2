#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "addandremove.h"
#include "safeinput.h"
#include "noheap.h"

void addAndRemove2(){

    int cardNr;
    while(!GetInputInt("Enter cardnumber: ", &cardNr))
        printf("Please enter a number\n");
    Card2 card;
    ReadIniFileWithCallback("server.ini",iniValueCallback, &card, cardNr);

}




