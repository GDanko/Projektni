#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
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
