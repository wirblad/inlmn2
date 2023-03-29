#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "remote.h"


void remote(bool *lamp){

    *lamp = true;
    if(*lamp == true)
        printf("CURRENTLY LAMP IS GREEN\n");
    
    sleep(3);
    *lamp = false;
}