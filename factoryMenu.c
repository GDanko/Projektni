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



int factoryMenu() {
    
    CLEAR_CONSOLE();

    static char setColor[16] = "\033[0m";
    static WEAPON tempWeapon;
  
    printf("============================================================\n");
    printf("          POGON ZA SASTAVLJANJE NAORUZANJA\n");
    printf("============================================================\n\n");

    printf("[1] DEFINIRANJE STANDARDA \t\t %s %s \033[0m\n", setColor, tempWeapon.standard);
    printf("[2] ODABIR POGONSKOG SUSTAVA \t\t %s \033[0m\n", tempWeapon.engine.type);
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
        strcpy(setColor, "\033[37;42m");
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
        printf("\nZbog ostecenja, oruzje je poslano na popravak.\n");
        strcpy(setColor, "\033[0m");
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