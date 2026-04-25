#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
#include "functions.h"
#include <conio.h>

extern int numOfWeapons;
int nextID;

void defineStandard(WEAPON* const weapon) {

    unsigned short choice;
    unsigned short valid = 0;

    do {
        CLEAR_CONSOLE();
        
        printf("============================================================\n");
        printf("                  ODABERITE STANDARD\n");
        printf("============================================================\n\n");

        printf("[1] NATO A1\n");
        printf("[2] NATO A2\n");
        printf("[3] NATO A3\n\n");
        printf("============================================================\n");
        printf("Izbor: ");

        if (scanf("%hu", &choice) != 1) {
            printf("Krivi unos, unesite broj.\n");
            clearBuffer();
            pause();
            continue;
        }
        clearBuffer();

        switch (choice) {
        case 1:
            strcpy(weapon->standard, "NATO A1");
            valid = 1;
            break;

        case 2:
            strcpy(weapon->standard, "NATO A2");
            valid = 1;
            break;

        case 3:
            strcpy(weapon->standard, "NATO A3");
            valid = 1;
            break;

        default:
            printf("\nNepoznata opcija. Pokusajte ponovno.\n");
            pause();
            break;
        }
    } while (!valid);

    printf("\nStandard uspjesno postavljen na: %s\n", weapon->standard);
}



void configureEngine() {



}



void sendToStorage() {

	FILE* fp = fopen("storage.bin", "ab");

}



void pause() {

    printf("\033[37;41m Pritisnite bilo koju tipku za nastavak...\033[0m\n");
    _getch();

}



void clearBuffer() {

    char c;
    while ((c = getchar()) != '\n' && c != '\0' && c != EOF);

}