#include <stdio.h>
#include "menu.h"
#include "safeinput.h"

int menu(){
    
    int menuChoice;
    GetInputInt("Admin menu\n1. Remote open door\n2. List all cards in system\n3. Add/remove access\n4. Exit\n9. FAKE TEST SCAN CARD\n", &menuChoice);
    return menuChoice;
}