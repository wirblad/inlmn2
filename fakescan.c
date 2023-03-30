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
    Card2 card;
    Card2 getCard;

    while(GetInputInt("Please scan card to enter or X(ANY CHAR) to go back to admin menu\n", &cardNr)){
        
        ReadIniFileWithCallbackGetStruct("server.ini",iniValueCallbackGetStruct, &card,cardNr, &getCard);
         
        if(!strcmp(getCard.access,"no")){
            *lamp = false;
            printf("CURRENTLY LAMP IS RED\n");
        }
        if(!strcmp(getCard.access,"yes")){
            *lamp = true;
            printf("CURRENTLY LAMP IS GREEN\n");
        }
        if(!strcmp(getCard.access,"NOFIND")){ 
            printf("NO SUCH CARD IN SYSTEM, TRY AGAIN\n");
        }
        
    }
}