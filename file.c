#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"

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