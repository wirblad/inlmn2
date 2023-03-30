#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "fakescan.h"
#include "safeinput.h"
#include "addandremove.h"
#include "noheap.h"

void fakeScan(bool *lamp){

    int cardNr;
    while(GetInputInt("Please scan card to enter or X(ANY CHAR) to go back to admin menu\n", &cardNr)){
        Card2 card;
        Card2 getCard;
        ReadIniFileWithCallbackGetStruct("server.ini",iniValueCallbackGetStruct, &card,cardNr, &getCard);
        
        if(!strcmp(getCard.access,"no")){
            *lamp = false;
            printf("CURRENTLY LAMP IS RED\n");
        }
        if(!strcmp(getCard.access,"yes")){
            *lamp = true;
            printf("CURRENTLY LAMP IS GREEN\n");
        }
        *lamp = false;
        printf("DIDN*T FIND CARD, TRY AGAIN\n");
        
    }
}