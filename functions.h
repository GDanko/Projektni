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

int storageMenu();

void printStorage();

void readWeapons(WEAPON**, FILE*);

void returnToFactory();

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
* Menu za odredjivanje tipa i mase pogona.
*/
void configureEngine(WEAPON* const);

/*
* Menu za odredjivanje tipa i mase eksplozivne glave.
*/
void configureWarhead(WEAPON* const weapon);

/*
* Funkcija za spremanje konstruiranog oruzja u datoteku.
*/
void sendToStorage(WEAPON*);

/*
* Funkcija za otvaranje datoteke.
*/
FILE* openFile(const char* mode);

/*
* Funkcija za kreiranje datoteke.
*/
void createFile();

/*
* Funkcija za odredjivanje tipa eksploziva.
*/
void configureWarhead(WEAPON* const);

/*
* Vraca boju kao string.
*/
const char* setColor(const COLOR color);

/*
* Provjerava da li je uneseni unak broj.
*/
int getChoice(unsigned short* choice);

/*
* Provjerava da li je string prazan i prema tome odredjuje boju.
*/
const char* checkColor(const char* string);


/*
* Omogucava unos mase motora.
*/
void inputEngineMass(float* mass, float min, float max);

/*
* Omogucava unos mase bojeve glave.
*/
void inputWarheadMass(float* mass, float min, float max);

/*
* Funkcija za odredjivanje tipa navodjenja.
*/
void configureGuidance(WEAPON* const weapon);

/*
* Funkcija za provjeru standarda.
*/
int isStandardValid(const char* weaponStandard, int engineChoice);

#endif
