#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"
#include "weapons.h"
#include <string.h>

typedef enum {
    DEFINE_STANDARD = 1,
    CONFIGURE_ENGINE,
    CONFIGURE_WARHEAD,
    CONFIGURE_GUIDANCE,
    STORE,
    RESTART,
    RETURN
}factoryMenuOptions;

WEAPON tempWeapon;

int factoryMenu() {
    
    CLEAR_CONSOLE();
  
    printf("============================================================\n");
    printf("          POGON ZA SASTAVLJANJE NAORUZANJA\n");
    printf("============================================================\n\n");

    printf("[1] DEFINIRANJE STANDARDA \t\t %s\n", tempWeapon.standard);
    printf("[2] ODABIR POGONSKOG SUSTAVA\n");
    printf("[3] KONFIGURACIJA BOJEVE GLAVE\n");
    printf("[4] INSTALACIJA SUSTAVA NAVODJENJA\n\n");
    
    printf("[5] POSALJI U SKLADISTE\n");
    printf("[6] RESTART\n\n");

    printf("[7] POVRATAK U GLAVNI IZBORNIK\n\n");

    printf("============================================================\n");
    printf("Odaberite korak proizvodnje: ");

    unsigned short option;
    scanf("%hu", &option);
    getchar();

    switch (option) {

    case DEFINE_STANDARD:
        defineStandard(&tempWeapon);
        pause();
        break;

    case CONFIGURE_ENGINE:
        printf("\nwork in progress\n");
        pause();
        break;

    case CONFIGURE_WARHEAD:
        printf("\nwork in progress\n");
        pause();
        break;

    case CONFIGURE_GUIDANCE:
        printf("\nwork in progress\n");
        pause();
        break;

    case STORE:
        printf("\nwork in progress\n");
        pause();
        break;

    case RESTART:
        memset(&tempWeapon, 0, sizeof(WEAPON));
        break;

    case RETURN:
        return 0;
        
    default:
        printf("\nNepoznata opcija. Pokusajte ponovno.\n");
        pause();
        break;
    }
    return 1;
}