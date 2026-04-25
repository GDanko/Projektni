#ifndef WEAPONS_H
#define WEAPONS_H

typedef struct {

    char type[10];
    float mass;

} ENGINE;

typedef struct {

    char type[10];
    float mass;

} EXPLOSIVE;

typedef struct {

    int id;
    char standard[20];
    char name[20];
    ENGINE engine;
    EXPLOSIVE explosive;
    char guidanceType[20];

} WEAPON;


#endif
