#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

typedef enum {
    PROIZVODNJA = 1,
    SKLADISTE,
    ISPORUKA,
    IZLAZ = 0
}mainMenuOptions;

int mainMenu() {

    CLEAR_CONSOLE();

    printf("============================================================\n");
    printf("          SUSTAV ZA UPRAVLJANJE NAORUZANJEM\n");
    printf("============================================================\n\n");

    printf("[1] PROIZVODNJA\n");
    printf("[2] UPRAVLJANJE SKLADISTEM\n");
    printf("[3] ISPORUKA\n\n");

    printf("[0] IZLAZ\n\n");
    printf("============================================================\n");
    printf("Izaberite opciju: ");

    unsigned short option;
    unsigned short condition = 1;
    scanf("%hu", &option);
    getchar();

    switch (option) {

    case PROIZVODNJA:
        while (condition) {
            condition = factoryMenu();
        }
        break;
 
      case SKLADISTE:
          while (condition) {
              condition = 2;
          }
          break;

      case ISPORUKA:
          while (condition) {
              condition = 3;
          }
          break;

      case IZLAZ:
          printf("\nIzlaz iz Sustava.\n");
          return 0;
          break;

      default:
          printf("\nNepoznata opcija. Pokusajte ponovno.\n");
          break;
    }
    return 1;
}