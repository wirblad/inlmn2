#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"


void saveNrOfCardsToFile(State *state){

    FILE *outfile;    
    outfile = fopen ("state.txt", "w");

    if (outfile == NULL){
        fprintf(stderr, "\nError opened file\n");
        return;
    }

    fprintf(outfile, "%d", state->nrOfCards);
        
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
    
    fclose (outfile);
}

void readNrOfCardsFromFile(const State *state){

    FILE *infile;
    infile = fopen ("state.txt", "r");

    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }
      
    fscanf (infile, "%d", &state->nrOfCards);  
    fclose (infile);
   
}

void saveAllCardsToFile(State *state){

    FILE *outfile;    
    outfile = fopen ("cards.dat", "w");

    if (outfile == NULL){
        fprintf(stderr, "\nError opened file\n");
        return;
    }

    for(int i = 0 ; i < state->nrOfCards ; i++){
        
        fwrite(&state->cards[i], sizeof(Card), 1, outfile);

    }
        
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
    
    fclose (outfile);
}

void readAllCardsFromFile(State *state){

    FILE *infile;
    infile = fopen ("cards.dat", "r");

    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }

    state->cards = (Card *)malloc(state->nrOfCards * sizeof(Card));
    for(int i = 0 ; i < state->nrOfCards ; i++){ 
        
        fread(&state->cards[i], sizeof(Card), 1, infile);

    }
    fclose (infile);
   
}


void mergeFiles(){

    FILE *fResult = fopen("server.ini", "w");
    FILE *f1=fopen("cardTemp.ini", "r");
    
    if(f1 == NULL  || fResult == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(f1);
        fclose(fResult);
        return;
   }

    char line[250];
    while(fgets(line,250,f1)){
        fputs(line,fResult);
    }
    fclose(f1);
    fputs("\n", fResult); 
    fclose(fResult);
}