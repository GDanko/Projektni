#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"
#include "weapons.h"
#include <string.h>
#include "colors.h"

typedef enum {
    DEFINE_STANDARD = 1,
    CONFIGURE_ENGINE,
    CONFIGURE_WARHEAD,
    CONFIGURE_GUIDANCE,
    STORE,
    RESTART,
    RETURN = 0
}MENU_OPTIONS;


int factoryMenu() {

    CLEAR_CONSOLE();

    static WEAPON tempWeapon;

 
    printf("============================================================\n");
    printf("          POGON ZA SASTAVLJANJE NAORUZANJA\n");
    printf("============================================================\n\n");

    printf("[1] DEFINIRANJE STANDARDA \t\t %s %s \033[0m\n",
        checkColor(tempWeapon.standard),
        tempWeapon.standard[0] == '\0' ? "NIJE DEFINIRANO" : tempWeapon.standard);
 
    printf("[2] ODABIR POGONSKOG SUSTAVA \t\t %s %s \033[0m\n",
        checkColor(tempWeapon.engine.type),
        tempWeapon.engine.type[0] == '\0' ? "NIJE DEFINIRANO" : tempWeapon.engine.type);

    printf("[3] KONFIGURACIJA BOJEVE GLAVE \t\t %s %s \033[0m\n",
        checkColor(tempWeapon.explosive.type),
        tempWeapon.explosive.type[0] == '\0' ? "NIJE DEFINIRANO" : tempWeapon.explosive.type);
        
    printf("[4] INSTALACIJA SUSTAVA NAVODJENJA \t %s %s \033[0m\n\n",
        checkColor(tempWeapon.guidanceType),
        tempWeapon.guidanceType[0] == '\0' ? "NIJE DEFINIRANO" : tempWeapon.guidanceType);

    
    printf("[5] POSALJI U SKLADISTE\n");
    printf("[6] RESTART\n\n");

    printf("[0] POVRATAK U GLAVNI IZBORNIK\n\n");

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
        configureEngine(&tempWeapon);
        pause();
        break;

    case CONFIGURE_WARHEAD:
        configureWarhead(&tempWeapon);
        pause();
        break;

    case CONFIGURE_GUIDANCE:
        configureGuidance(&tempWeapon);
        pause();
        break;

    case STORE:
        sendToStorage(&tempWeapon);
        pause();
        break;

    case RESTART:
        memset(&tempWeapon, 0, sizeof(WEAPON));
        printf("\nOruzje je uklonjeno iz proizvodnje.\n");
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