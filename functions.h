#include "stdio.h"

#ifndef functions
#define functions

#ifdef _WIN32
	#define CLEAR_CONSOLE() system("cls")
#else
	#define CLEAR_CONSOLE() system("clear")
#endif

/*
* Otvara glavni izbornik.
*/
int mainMenu();

/*
* Otvara izbornik za konstrukciju naoruzanja.
*/
int factoryMenu();

/*
* 
*/
void defineStandard();
void configureEngine();
void sendToStorage();

#endif