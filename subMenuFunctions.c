#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
#include "functions.h"
#include <conio.h>
#include "colors.h"

void defineStandard(WEAPON* const weapon) {

    if (weapon->engine.type[0] != '\0')
    {
        printf("\nNije moguce mijenjati standard s namontiranim djelovima.\n");
        return;
    }

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



void configureEngine(WEAPON* const weapon) {

    unsigned short choice;
    unsigned short valid = 0;

    do {
        CLEAR_CONSOLE();

        printf("============================================================\n");
        printf("                  ODABERITE TIP MOTORA\n");
        printf("============================================================\n\n");

        printf("[1] ---\n");
        printf("[2] Motor na kruto gorivo\n");
        printf("[3] Motor na tekuce gorivo\n");
        printf("[4] Hibridni motor\n");
        printf("[5] Mlazni motor\n\n");

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
            if (strcmp(weapon->standard, "NATO A1") == 0 ||
                strcmp(weapon->standard, "NATO A2") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "---");
                weapon->engine.mass = 0;
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case 2:
            if (strcmp(weapon->standard, "NATO A1") == 0 ||
                strcmp(weapon->standard, "NATO A2") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Motor na kruto gorivo");
                printf("Odretide masu motora [15-50]kg.\n");
                do
                {
                    scanf("%f", &weapon->engine.mass);
                } while (weapon->engine.mass < 15 || weapon->engine.mass > 50);
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case 3:
            if (strcmp(weapon->standard, "NATO A2") == 0 ||
                strcmp(weapon->standard, "NATO A3") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Motor na tekuce gorivo");
                weapon->engine.mass = 0;
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case 4:
            if (strcmp(weapon->standard, "NATO A3") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Hibridni motor");
                weapon->engine.mass = 0;
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case 5:
            if (strcmp(weapon->standard, "NATO A3") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Mlazni motor");
                weapon->engine.mass = 0;
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        default:
            printf("\nNepoznata opcija. Pokusajte ponovno.\n");
            pause();
            break;
        }
    } while (!valid);

    printf("\nMotor uspjesno postavljen na: %s\n", weapon->engine.type);

}