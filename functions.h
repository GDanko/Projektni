#include "stdio.h"
#include "weapons.h"
#include "colors.h"

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
void configureEngine(WEAPON* const);

/*
* Funkcija za spremanje konstruiranog oruzja u datoteku.
*/
void sendToStorage();

/*
* Funkcija za odredjivanje tipa eksploziva.
*/
void configureWarhead(WEAPON* const);

/*
* Vraca boju kao string 
*/
const char* setColor(const COLOR);

/*
* Provjerava da li je string prazan i prema tome odredjuje boju
*/
const char* checkColor(const char*);

#endif