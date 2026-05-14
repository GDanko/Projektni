#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
#include "functions.h"
#include <conio.h>
#include "colors.h"
#include "weaponTypes.h"


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

        if (!getChoice(&choice)) {
            continue;
        }

        switch (choice) {

        case S_A1:
            strcpy(weapon->standard, "NATO A1");
            valid = 1;
            break;

        case S_A2:
            strcpy(weapon->standard, "NATO A2");
            valid = 1;
            break;

        case S_A3:
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

    if (weapon->standard[0] == '\0')
    {
        printf("\nNije moguce montirati motor s neodredjenim standardom.\n");
        return;
    }

    if (weapon->explosive.type[0] != '\0') {
        printf("\nNije moguce mijenjati motor s namontiranom bojevom glavom.\n");
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

        if (!getChoice(&choice)) {
            continue;
        }

        if (choice == E_DEMONT) {
            if (weapon->explosive.type[0] != '\0') {
                printf("nije moguce demontirati motor s namontiranom bojevom glavom.\n");
                return;
            }
            else if (weapon->engine.type[0] != '\0') {   
                weapon->engine.type[0] = '\0';
                weapon->engine.mass = 0;
                printf("Motor demontiran.\n");
            }
            else {
                printf("Nema se sta demontirat.\n");
            }
            return;
        }

        if (!isStandardValid(weapon->standard, choice)) {
            printf("\nStandard '%s' ne podrzava ovaj tip motora.\n", weapon->standard);
            pause();
            continue;
        }

        valid = 1;

        switch (choice) {
        case E_NONE:
            strcpy(weapon->engine.type, "NONE");
            weapon->engine.mass = 0;
            break;

        case E_SOLID:
            strcpy(weapon->engine.type, "Motor na kruto gorivo");
            inputEngineMass(&weapon->engine.mass, 300, 500);
            break;

        case E_LIQUID:
            strcpy(weapon->engine.type, "Motor na tekuce gorivo");
            inputEngineMass(&weapon->engine.mass, 500, 700);
            break;

        case E_HYBRID:
            strcpy(weapon->engine.type, "Hibridni motor");
            inputEngineMass(&weapon->engine.mass, 500, 800);
            break;

        case E_JET:
            strcpy(weapon->engine.type, "Mlazni motor");
            inputEngineMass(&weapon->engine.mass, 800, 1000);
            break;

        default:
            valid = 0;
            printf("\nNepoznata opcija.\n");
            pause();
        }
    } while (!valid);

    printf("\nMotor uspjesno postavljen na: %s\n", weapon->engine.type);
}



void configureWarhead(WEAPON* const weapon) {

    if (weapon->engine.type[0] == '\0')
    {
        printf("\nNije moguce montirati bojnu glavu bez namontiranog motora.\n");
        return;
    }

    if (weapon->guidanceType[0] != '\0') {
        printf("\nNije moguce mijenjati bojevu glavu s namontiranim sustavom navodjenja.\n");
        return;
    }

    unsigned short choice;
    unsigned short valid = 0;

    do {
        CLEAR_CONSOLE();

        printf("============================================================\n");
        printf("                ODABERITE TIP BOJEVE GLAVE\n");
        printf("============================================================\n\n");

        printf("[1] Visoko-eksplozivna\n");
        printf("[2] Protu-oklopna\n");
        printf("[3] Fragmentacijska\n");
        printf("[4] Termobaricna\n");
        printf("[5] Kasetna\n\n");

        printf("[6] Demontiraj\n\n");

        printf("============================================================\n");
        printf("Izbor: ");

        if (!getChoice(&choice)) {
            continue;
        }

        if (choice == W_DEMONT) {
            if (weapon->explosive.type[0] != '\0') {
                weapon->explosive.type[0] = '\0';
                weapon->explosive.mass = 0;
                printf("Bojeva glava demontirana.\n");
            }
            else {
                printf("Nema se sta demontirat.\n");
            }
            return;
        }

        if (!isStandardValid(weapon->standard, choice)) {
            printf("\nNeodgovarajuci standard za tip bojeve glave. Pokusajte ponovno.\n");
            pause();
            continue;
        }
        valid = 1;

        switch (choice) {
        case W_HIGH_EXPLOSIVE:
            strcpy(weapon->explosive.type, "Visoko-eksplozivna");
            inputWarheadMass(&weapon->explosive.mass, 50, 70);
            break;

        case W_ARMOR_PIERCING:
            strcpy(weapon->explosive.type, "Protu-oklopna");
            weapon->explosive.mass = 0;
            break;

        case W_FRAGMENTATION:
            strcpy(weapon->explosive.type, "Fragmentacijska");
            inputWarheadMass(&weapon->explosive.mass, 30, 50);
            break;

        case W_THERMOBARIC:
            strcpy(weapon->explosive.type, "Termobaricna");
            inputWarheadMass(&weapon->explosive.mass, 100, 120);
            break;

        case W_CLUSTER:
            strcpy(weapon->explosive.type, "Kasetna");
            inputWarheadMass(&weapon->explosive.mass, 15, 20);
            break;

        default:
            valid = 0;
            printf("\nNepoznata opcija.\n");
            pause();
        }
    } while (!valid);

    printf("\nBojeva glava uspjesno postavljena na: %s\n", weapon->explosive.type);
}



void configureGuidance(WEAPON* const weapon) {

    if (weapon->explosive.type[0] == '\0')
    {
        printf("\nNije moguce montirati sustav navodjenja bez namontirane bojne glave.\n");
        return;
    }

    unsigned short choice;
    unsigned short valid = 0;

    do {
        CLEAR_CONSOLE();

        printf("============================================================\n");
        printf("              ODABERITE TIP SUSTAVA NAVODJENJA\n");
        printf("============================================================\n\n");

        printf("[1] ---\n");
        printf("[2] Inercijalno navodjenje\n");
        printf("[3] Lasersko navodjenje\n");
        printf("[4] Infracrveno navodjenje\n");
        printf("[5] Radarsko navodjenje\n\n");

        printf("[6] Demontiraj\n\n");

        printf("============================================================\n");
        printf("Izbor: ");

        if (!getChoice(&choice)) {
            continue;
        }

        if (choice == G_DEMONT) {
            if (weapon->guidanceType[0] != '\0') {
                weapon->guidanceType[0] = '\0';
                printf("Sustav navodjenja demontiran.\n");
            }
            else {
                printf("Nema se sta demontirat.\n");
            }
            return;
        }

        if (!isStandardValid(weapon->standard, choice)) {
            printf("\nNeodgovarajuci standard za tip navodjenja Pokusajte ponovno.\n");
            pause();
            continue;
        }
        valid = 1;

        switch (choice) {
        case G_NONE:
            strcpy(weapon->guidanceType, "NONE");
            break;

        case G_INERTIAL:
            strcpy(weapon->guidanceType, "Inercijsko");
            break;

        case G_LASER:
            strcpy(weapon->guidanceType, "Laser");
            break;

        case G_INFRARED:
            strcpy(weapon->guidanceType, "Infracrveno");
            break;

        case G_RADAR:
            strcpy(weapon->guidanceType, "Radar");
            break;

        default:
            valid = 0;
            printf("\nNepoznata opcija.\n");
            pause();
        }
    } while (!valid);

    printf("\nSustav navodjenja uspjesno postavljen na: %s\n", weapon->guidanceType);
}
