#ifndef WEAPON_TYPES_H
#define WEAPON_TYPES_H

typedef enum {

    E_NONE = 1,
    E_SOLID,
    E_LIQUID,
    E_HYBRID,
    E_JET,
    E_DEMONT

} ENGINE_TYPE;

typedef enum {

    S_A1 = 1,
    S_A2,
    S_A3

} STANDARD_TYPE;

typedef enum {

    W_HIGH_EXPLOSIVE = 1,
    W_ARMOR_PIERCING,
    W_FRAGMENTATION,
    W_THERMOBARIC,
    W_CLUSTER,
    W_DEMONT

} WARHEAD_TYPE;

typedef enum {

    G_NONE = 1,
    G_INERTIAL,
    G_LASER,
    G_INFRARED,
    G_RADAR,
    G_DEMONT

} GUIDANCE_TYPE;

#endif // !WEAPON_TYPES_H