#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"
#include "weapons.h"
#include <string.h>
#include "colors.h"

typedef enum {
	PRINT = 1,
	RETURN_STORAGE,
	DELETE,
	
	RETURN = 0
}MENU_OPTIONS;

int numOfWeapons = 0;
extern WEAPON tempWeapon;

int storageMenu() {

	CLEAR_CONSOLE();



	printf("============================================================\n");
	printf("              UPRAVLJANJE SKLADISTEM\n");
	printf("============================================================\n\n");

	printf("[1] ISPISI ORUZJE\n");
	printf("[2] VRATI U PROIZVODNJU\n");
	printf("[3] OBRISI ORUZJE\n\n");

	printf("[0] POVRATAK U GLAVNI IZBORNIK\n\n");

	printf("============================================================\n");
	printf("Odaberite korak: ");

	int status;

	unsigned short option;
	scanf("%hu", &option);
	clearBuffer();

	switch (option) {

	case PRINT:
		printStorage();
		pause();
		break;

	case RETURN_STORAGE:
		status = returnToFactory();
		pause();
		if (status == 1) {
		return 2;
		}
		else
		{
			return 1;
		}

	case DELETE:
		deleteWeapon();
		pause();
		break;
		

	case RETURN:
		return 0;

	default:
		printf("\nNepoznata opcija. Pokusajte ponovno.\n");
		clearBuffer();
		pause();
		break;
	}
	return 1;
}
