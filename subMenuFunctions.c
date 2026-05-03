#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
#include "functions.h"
#include <conio.h>
#include "colors.h"

typedef enum {

    A1 = 1,
    A2,
    A3,

}STANDARD_TYPE;

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

        case A1:
            strcpy(weapon->standard, "NATO A1");
            valid = 1;
            break;

        case A2:
            strcpy(weapon->standard, "NATO A2");
            valid = 1;
            break;

        case A3:
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

typedef enum {

    NONE = 1,
    SOLID,
    LIQUID,
    HYBRID,
    JET,
    DEMONT

}ENGINE_TYPE;

void configureEngine(WEAPON* const weapon) {

    if (weapon->standard[0] == '\0')
    {
        printf("\nNije moguce montirati motor s neodredjenim standardom.\n");
        return;
    }

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

        printf("[6] Demontiraj\n\n");

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

        case NONE:
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

        case SOLID:
            if (strcmp(weapon->standard, "NATO A2") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Motor na kruto gorivo");
           
                do
                {
                    CLEAR_CONSOLE();
                    printf("Odretide masu motora [300-500]kg.\n");
                    if (scanf("%f", &weapon->engine.mass) != 1) {
                        printf("Pogreska, unesite broj\n");
                        clearBuffer();
                        continue;
                    }
                    
                } while (weapon->engine.mass < 300 || weapon->engine.mass > 500);
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case LIQUID:
            if (strcmp(weapon->standard, "NATO A2") == 0 ||
                strcmp(weapon->standard, "NATO A3") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Motor na tekuce gorivo");

                do
                {
                    CLEAR_CONSOLE();
                    printf("Odretide masu motora [500-700]kg.\n");
                    if (scanf("%f", &weapon->engine.mass) != 1) {
                        printf("Pogreska, unesite broj\n");
                        clearBuffer();
                        continue;
                    }

                } while (weapon->engine.mass < 500 || weapon->engine.mass > 700);
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case HYBRID:
            if (strcmp(weapon->standard, "NATO A3") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Hibridni motor");

                do
                {
                    CLEAR_CONSOLE();
                    printf("Odretide masu motora [500-800]kg.\n");
                    if (scanf("%f", &weapon->engine.mass) != 1) {
                        printf("Pogreska, unesite broj\n");
                        clearBuffer();
                        continue;
                    }

                } while (weapon->engine.mass < 500 || weapon->engine.mass > 800);
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case JET:
            if (strcmp(weapon->standard, "NATO A3") == 0)
            {
                valid = 1;
                strcpy(weapon->engine.type, "Mlazni motor");

                do
                {
                    CLEAR_CONSOLE();
                    printf("Odretide masu motora [800-1000]kg.\n");
                    if (scanf("%f", &weapon->engine.mass) != 1) {
                        printf("Pogreska, unesite broj\n");
                        clearBuffer();
                        continue;
                    }

                } while (weapon->engine.mass < 800 || weapon->engine.mass > 1000);
            }
            else
            {
                printf("\nNeodgovarajuci standard za tip motora. Pokusajte ponovno.\n");
                pause();
            }
            break;

        case DEMONT:
            if (weapon->engine.type[0] != '\0') {
                strcpy(weapon->engine.type, "\0");
                weapon->engine.mass = 0;
                printf("Motor demontiran.\n");
            }
            else
            {
                printf("Nema se sta demontirat.\n");
            }
            return;
         
        default:
            printf("\nNepoznata opcija. Pokusajte ponovno.\n");
            pause();
            break;
        }
    } while (!valid);

    printf("\nMotor uspjesno postavljen na: %s\n", weapon->engine.type);

}