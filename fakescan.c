#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "fakescan.h"
#include "safeinput.h"
#include "addandremove.h"
#include "noheap.h"

void fakeScan(){

    int cardNr;
    GetInputInt("Please scan card to enter or X(ANY CHAR) to go back to admin menu\n", &cardNr);
    Card2 card;
    Card2 getCard;
    ReadIniFileWithCallbackGetStruct("server.ini",iniValueCallbackGetStruct, &card,cardNr, &getCard);
    
    //FINNS I CARD !!! ÄNDRA I GLOBAL LAMPA!!
 
    if(!strcmp(getCard.access,"no")){
        printf("CURRENTLY LAMP IS RED\n");
    }
    if(!strcmp(getCard.access,"yes")){
        printf("CURRENTLY LAMP IS GREEN\n");
    }
    if(&getCard == NULL)
        printf("DIDN*T FIND\n");
    

    /*Card *card = searchCardNr(state, cardNr);

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
    }*/

}