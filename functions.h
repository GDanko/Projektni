#include "stdio.h"
#include "weapons.h"

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
* Pauzira program i ceka potvrdu za nastavak.
*/
void pause();

/*
* Cisti svaki znak u bufferu.
*/
void clearBuffer();

/*
* Menu za izbor standarda oruzja.
*/
void defineStandard(WEAPON* const);

/*
* Menu za odredjivanje tipa i mase pogona oruzja.
*/
void configureEngine();

/*
* Funkcija za spremanje konstruiranog oruzja u datoteku.
*/
void sendToStorage();

#endif