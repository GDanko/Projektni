#ifndef WEAPONS_H
#define WEAPONS_H

typedef struct {

    char type[30];
    float mass;

} ENGINE;

typedef struct {

    char type[30];
    float mass;

} EXPLOSIVE;

typedef struct {

    int id;
    char standard[10];
    char name[20];
    ENGINE engine;
    EXPLOSIVE explosive;
    char guidanceType[30];

} WEAPON;


#endif
