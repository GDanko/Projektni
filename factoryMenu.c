#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

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

    printf("============================================================\n");
    printf("          POGON ZA SASTAVLJANJE NAORUZANJA\n");
    printf("============================================================\n\n");

    printf("[1] DEFINIRANJE STANDARDA\n");
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
        defineStandard();
        break;

    case CONFIGURE_ENGINE:
        configureEngine();
        break;

    case STORE:
     
        break;

    case RETURN:
        return 0;
        
    default:
        printf("\nNepoznata opcija. Pokusajte ponovno.\n");
        break;
    }
    return 1;
}