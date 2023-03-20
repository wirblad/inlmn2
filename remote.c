#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "remote.h"


void remote(State *state){

    state->lamp = true;
    if(state->lamp == true)
        printf("CURRENTLY LAMP IS GREEN\n");
    
    sleep(3);
    state->lamp = false;
}