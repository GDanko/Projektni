#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
#include "weaponTypes.h"
#include "functions.h"
#include <conio.h>
#include "colors.h"

extern int numOfWeapons;
int nextID;

const char* setColor(const COLOR color) {
    static const char* colorCodes[] = {
        "\033[0m",      
        "\033[1;31m",   
        "\033[1;32m"   
    };
    if (color < 0 || color >= sizeof(colorCodes) / sizeof(colorCodes[0])) {
        return colorCodes[0];
    }
    return colorCodes[color];
}



const char* checkColor(const char* str) {
    if (str[0] == '\0') {
        return setColor(RED);
    }
    return setColor(GREEN);
}



void sendToStorage() {

	FILE* fp = fopen("storage.bin", "ab");

}



void pause() {

    printf("%sPritisnite bilo koju tipku za nastavak...%s\n", setColor(RED), setColor(CLEAR));
    _getch();

}



void clearBuffer() {

    char c;
    while ((c = getchar()) != '\n' && c != '\0' && c != EOF);

}



void inputEngineMass(float* mass, float min, float max) {
    do {
        CLEAR_CONSOLE();
        printf("Odredite masu motora [%.0f-%.0f]kg: ", min, max);
        if (scanf("%f", mass) != 1) {
            printf("Pogreska, unesite broj.\n");
            clearBuffer();
            pause();
            continue;
        }
    } while (*mass < min || *mass > max);
}



void inputWarheadMass(float* mass, float min, float max) {
    do {
        CLEAR_CONSOLE();
        printf("Odredite masu bojeve glave [%.0f-%.0f]kg: ", min, max);
        if (scanf("%f", mass) != 1) {
            printf("Pogreska, unesite broj.\n");
            clearBuffer();
            pause();
            continue;
        }
    } while (*mass < min || *mass > max);
}



int getChoice(unsigned short* choice) {
    if (scanf("%hu", choice) != 1) {
        printf("Krivi unos, unesite broj.\n");
        clearBuffer();
        pause();
        return 0;
    }
    clearBuffer();
    return 1;
}



int isStandardValid(const char* weaponStandard, int choice) {

    if (choice == E_NONE || choice == W_HIGH_EXPLOSIVE || choice == G_NONE) {
        return (strcmp(weaponStandard, "NATO A1") == 0 || strcmp(weaponStandard, "NATO A2") == 0);
    }

    else if (choice == E_SOLID || choice == W_ARMOR_PIERCING || choice == G_INERTIAL) {
        return (strcmp(weaponStandard, "NATO A2") == 0);
    }

    else if (choice == E_LIQUID || choice == W_FRAGMENTATION || choice == G_LASER) {
        return (strcmp(weaponStandard, "NATO A2") == 0 || strcmp(weaponStandard, "NATO A3") == 0);
    }

    else if (choice == E_HYBRID || choice == E_JET || choice == W_THERMOBARIC || choice == W_CLUSTER || choice == G_INFRARED || choice == G_RADAR) {
        return (strcmp(weaponStandard, "NATO A3") == 0);
    }

    return 0;
}
