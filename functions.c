#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
#include "weaponTypes.h"
#include "functions.h"
#include <conio.h>
#include "colors.h"

extern int numOfWeapons;
extern WEAPON tempWeapon;

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



void createFile() {

    FILE* fp = fopen("storage.bin", "wb");
    if (fp == NULL) {
        CLEAR_CONSOLE();
        perror("\nGreska pri kreiranju datoteke storage.bin.\n");
        pause();
        exit(EXIT_FAILURE);
    }

    numOfWeapons = 0;

    fwrite(&numOfWeapons, sizeof(int), 1, fp);

    fclose(fp);

}



FILE* openFile(const char* mode) {

    FILE* fp = fopen("storage.bin", mode);
    if (fp == NULL) {
        createFile();
        fp = fopen("storage.bin", mode);
        if (fp == NULL) {
            CLEAR_CONSOLE();
            perror("\nGreska pri otvaranju datoteke storage.bin.\n");
            pause();
            exit(EXIT_FAILURE);
        }
    }
    return fp;
}



void readWeapons(WEAPON** arrayWeapons, FILE* fp) {

    rewind(fp);
    fread(&numOfWeapons, sizeof(int), 1, fp);

    *arrayWeapons = (WEAPON*)calloc(numOfWeapons, sizeof(WEAPON));

    if (*arrayWeapons == NULL) {
        printf("\n%s[GRESKA] Nedovoljno memorije za ucitavanje oruzja.%s\n", setColor(RED), setColor(CLEAR));
        fclose(fp);
        pause();
        return;
    }

    fseek(fp, sizeof(int), SEEK_SET);
    fread(*arrayWeapons, sizeof(WEAPON), numOfWeapons, fp);
    fclose(fp);
}



void printStorage() {

    CLEAR_CONSOLE();

    WEAPON* arrayWeapons = NULL;

	FILE* fp = openFile("rb");

    readWeapons(&arrayWeapons, fp);
    if (arrayWeapons == NULL) {
        printf("\nNema oruzja za ispis.\n");
        fclose(fp);
        clearBuffer();
        pause();
        return;
    }

    printf("%-5s %-15s %-30s %-20s %-25s %-30s %-30s \n", "ID", "STANDARD", "TIP MOTORA", "MASA MOTORA[kg]", "BOJNA GLAVA", "MASA BOJNE GLAVE[kg]", "TIP NAVODJENJA");

    printf("-------------------------------------------------------------------------------------------------------------------------------------------------- \n");

    for (int i = 0; i < numOfWeapons; i++) {
        printf("%-5d %-15s %-30s %-20.2f %-25s %-30.2f %-30s\n",
            (arrayWeapons + i)->id, 
            (arrayWeapons + i)->standard,
            (arrayWeapons + i)->engine.type,
            (arrayWeapons + i)->engine.mass,
            (arrayWeapons + i)->explosive.type,
            (arrayWeapons + i)->explosive.mass,
            (arrayWeapons + i)->guidanceType
            );
    }
	fclose(fp);
}



void returnToFactory() {

    if (tempWeapon.standard[0] != '\0') {
        printf("\n%s[GRESKA] Nije moguce vratiti oruzje u proizvodnju jer je traka zauzeta.\n", setColor(RED));
        printf("Dovrsite ili resetirajte trenutno oruzje u tvornici.%s\n\n", setColor(CLEAR));
        return;
    }

    FILE* fp = openFile("rb");

    rewind(fp);
    fread(&numOfWeapons, sizeof(int), 1, fp);

    printStorage();

    int targetId;
    printf("\nOdaberite ID oruzja koje zelite vratiti u proizvodnju: ");
    if (scanf("%d", &targetId) != 1) {
        clearBuffer();
        fclose(fp);
        return;
    }
    clearBuffer();

    WEAPON* arrayWeapons = NULL;

    readWeapons(&arrayWeapons, fp);
    if (arrayWeapons == NULL) {
        printf("\nNema oruzja u skladistu.\n");
        fclose(fp);
        clearBuffer();
        pause();
        return;
    }

    int found = 0;

    for (int i = 0; i < numOfWeapons; i++) {

        if ((arrayWeapons + i)->id == targetId) {
            tempWeapon = *(arrayWeapons + i);
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Oruzje s ID-em %d uspjesno vraceno u proizvodnju.\n", targetId);
    }
    else {
        printf("Oruzje s ID-em %d nije pronadjeno u skladistu.\n", targetId);
    }

    fclose(fp);
}



void sendToStorage(WEAPON* weapon) {

    if (weapon->guidanceType[0] == '\0') {
        printf("\n%s[GRESKA] Nije moguce skladistiti nedovrseno oruzje.%s\n", setColor(RED), setColor(CLEAR));
        return;
    }

    FILE* fp = openFile("rb+");

    if (weapon->id == 0) {

        rewind(fp);
        fread(&numOfWeapons, sizeof(int), 1, fp);


        weapon->id = numOfWeapons + 1;

        fseek(fp, sizeof(int) + numOfWeapons * sizeof(WEAPON), SEEK_SET);
        fwrite(weapon, sizeof(WEAPON), 1, fp);

        numOfWeapons++;

        rewind(fp);
        fwrite(&numOfWeapons, sizeof(int), 1, fp);
        printf("\nOruzje uspijesno poslano u skladiste.\n");
    }
    else {

        WEAPON checkWeapon;

        rewind(fp);
        fread(&numOfWeapons, sizeof(int), 1, fp);

        for (int i = 0; i < numOfWeapons; i++) {
            fseek(fp, sizeof(int) + i * sizeof(WEAPON), SEEK_SET);
            fread(&checkWeapon, sizeof(WEAPON), 1, fp);

            if (checkWeapon.id == weapon->id) {

                fseek(fp, sizeof(int) + i * sizeof(WEAPON), SEEK_SET);
                fwrite(weapon, sizeof(WEAPON), 1, fp);
                break;
            }
        }
        printf("\nOruzje uspijesno vraceno u skladiste.\n");
    }

    memset(weapon, 0, sizeof(WEAPON));


   
    fclose(fp);
}



void pause() {

    printf("\n%sPritisnite bilo koju tipku za nastavak...%s\n", setColor(RED), setColor(CLEAR));
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
