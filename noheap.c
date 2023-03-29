#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "noheap.h"
#include "safeinput.h"

/*typedef struct {
    char cardNr[100];
    char access[100];
    char date[100];
} Card2;*/


#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(key, n) == 0

void noheap(){
    Card2 card;
    ReadIniFileWithCallback("server.ini",iniValueCallback, &card, NULL);
    //writeStructtoFile(&card);
}


void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

void writeStructtoFile(Card2* card){
    
    FILE *f=fopen("cardTemp.ini","a");
    fputs("[Card]\ncardNr=",f);
    fputs(card->cardNr,f);
    fputs("\naccess=",f);
    fputs(card->access,f);
    fputs("\ndate=",f);
    fputs(card->date,f);
    fputs("\n\n",f);
    fclose(f);
}

void ReadIniFileWithCallback(const char *fileName,void(*func)(const char *, const char *, const char *, void *, int, bool *), void *payload, int cardNr){
    FILE *f=fopen(fileName,"r");
    bool foundCardnr = false;
    char row[255];
    char currentGroup[255];
    while (fgets(row, sizeof(row), f) != NULL)  {
        removeChar(row,' ');
        removeChar(row,'\n');
        removeChar(row,'\r');
        if(row[0] == '[')
        {
            removeChar(row,'[');
            removeChar(row,']');
            strcpy(currentGroup,(const char *)row);
            continue;
        }
        char *part = strchr(row,'=');
        if(part == NULL) continue;
        int index = (int)(part - row);

        char value[100];
        memcpy(value, (const char *)row,index);
        value[index] = 0;
        func((const char *)currentGroup,(const char *)value, (const char *)part+1,payload,cardNr,&foundCardnr);
    }
    if(foundCardnr == false){
        printf("HITTADE INTE LÄGG TILL");
        char str[100];
        sprintf(str, "%d", cardNr); 
        Card2* card;
        strcpy(card->cardNr, str);
        strcpy(card->access, "true");
        strcpy(card->date, "010101");
        writeStructtoFile(card);
    }
    fclose(f);
}

void iniValueCallback(const char *section, const char *key, const char *value, void *payload, int cardNr, bool *foundCardnr){
    Card2* pConfig = (Card2*)payload;
    
    if (MATCH("Card", "cardNr")) {
        strcpy(pConfig->cardNr, value);
        printf("CardNr: %s\n", pConfig->cardNr);
    }
    if (MATCH("Card", "access")) {
        strcpy(pConfig->access, value);
        printf("Access: %s\n", pConfig->access);
    }
    if (MATCH("Card", "date")) {
        strcpy(pConfig->date, value);
        printf("Date: %s\n\n", pConfig->date);
        char str[100];
        sprintf(str, "%d", cardNr); 
        if(strcmp(pConfig->cardNr,str) == 0){
            *foundCardnr = true;
            printf("HITTADE cardnr"); 
            printf("This card has %s", pConfig->access);
            int choice;
            GetInputInt("Enter 1 for access, 2 for No access", &choice);  //WHILE LOOP
            if(choice == 1)
                strcpy(pConfig->access, "true");
            if(choice == 2)
                strcpy(pConfig->access, "false");
            else
                printf("Please enter 1 or 2");
        }
        writeStructtoFile(pConfig);
    }
   
}




