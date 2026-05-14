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

void printStorage() {

	FILE* fp = openFile("rb");
	//static WEAPON tempWeapon = { 0 };

	rewind(fp);
	fread(&numOfWeapons, sizeof(int), 1, fp);
	putchar('\n');

	for (int i = 0; i < numOfWeapons; i++)
	{
		memset(&tempWeapon, 0, sizeof(WEAPON));
		fseek(fp, sizeof(int) + i * sizeof(WEAPON), SEEK_SET);
		fread(&tempWeapon, numOfWeapons * sizeof(WEAPON), numOfWeapons, fp);

		printf("ID: %d\tSTANDARD: %s\tMOTOR: %s - MASA: %.2f\tBOJNA GLAVA: %s - MASA: %.2f\tNAVODJENJE: %s\n",
			tempWeapon.id,
			tempWeapon.standard,
			tempWeapon.engine.type,
			tempWeapon.engine.mass,
			tempWeapon.explosive.type,
			tempWeapon.explosive.mass,
			tempWeapon.guidanceType
		);
	}

	putchar('\n');
	memset(&tempWeapon, 0, sizeof(WEAPON));
	fclose(fp);
}




void returnToFactory() {

	FILE* fp = openFile("rb");
	int m;

	printf("Odaberite ID oruzja koje zelite vratiti u proizvodnju.\n");
	scanf("%d", &m);


	fseek(fp, sizeof(int) + sizeof(WEAPON) * m, SEEK_SET);
	fread(&tempWeapon, sizeof(WEAPON), 1, fp);

	printf("Orzuje vraceno u proizvodnju.\n");
	fclose(fp);
}



void sendToStorage(WEAPON* weapon) {

    if (weapon->guidanceType[0] == '\0') {
        printf("\nNije moguce skladistiti nedovrseno oruzje.\n");
        return;
    }

    FILE* fp = openFile("rb+");


    rewind(fp);
    fread(&numOfWeapons, sizeof(int), 1, fp);

    weapon->id = numOfWeapons;

    fseek(fp, sizeof(int) + numOfWeapons * sizeof(WEAPON), SEEK_SET);
    fwrite(weapon, sizeof(WEAPON), 1, fp);

    numOfWeapons++;
 
    rewind(fp);
    fwrite(&numOfWeapons, sizeof(int), 1, fp);

    memset(weapon, 0, sizeof(WEAPON));

    printf("\nOruzje uspijesno poslano u skladiste.\n");
    fclose(fp);
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
