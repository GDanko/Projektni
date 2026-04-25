#include "stdio.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
void pause();
void clearBuffer();
void defineStandard();
void configureEngine();
void sendToStorage();

#endif