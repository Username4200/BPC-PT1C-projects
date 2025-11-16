#include <stdio.h>
#include <math.h>
#include "VectorMath.h"


static struct vector3d nactiVektor(char jmeno) {
    struct vector3d v;
    printf("Zadejte vektor %c (hodnoty x, y, z oddelene carkou): ", jmeno);
    scanf("%lf,%lf,%lf", &v.x, &v.y, &v.z);
    return v;
}

struct vector3d operace(enum typOperace typ) {
    struct vector3d u, v, vysledek = { 0,0,0 };

    u = nactiVektor('u');
    v = nactiVektor('v');

    switch (typ) {
    case soucet:
        vysledek.x = u.x + v.x;
        vysledek.y = u.y + v.y;
        vysledek.z = u.z + v.z;
        break;
    case vektorovySoucin:
        vysledek.x = u.y * v.z - u.z * v.y;
        vysledek.y = u.z * v.x - u.x * v.z;
        vysledek.z = u.x * v.y - u.y * v.x;
        break;
    case skalarniSoucin:
        vysledek.x = u.x * v.x + u.y * v.y + u.z * v.z;
        break;
    case velikost:
        vysledek.x = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
        vysledek.y = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        break;
    case porovnani:
        vysledek.x = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
        vysledek.y = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        break;
    }

    tisk(u, v, typ);
    return vysledek;
}

void tisk(struct vector3d u, struct vector3d v, enum typOperace typ) {
    struct vector3d vysl;

    switch (typ) {
    case soucet:
        vysl.x = u.x + v.x;
        vysl.y = u.y + v.y;
        vysl.z = u.z + v.z;
        printf("Součet vektoru u a v je: (%.2lf, %.2lf, %.2lf)\n", vysl.x, vysl.y, vysl.z);
        break;
    case vektorovySoucin:
        vysl.x = u.y * v.z - u.z * v.y;
        vysl.y = u.z * v.x - u.x * v.z;
        vysl.z = u.x * v.y - u.y * v.x;
        printf("Vektorový soucin vektoru u a v je: (%.2lf, %.2lf, %.2lf)\n", vysl.x, vysl.y, vysl.z);
        break;
    case skalarniSoucin:
        printf("Skalarni soucinn je: %.2lf\n", u.x * v.x + u.y * v.y + u.z * v.z);
        break;
    case velikost:
        printf("Velikost vektoru u je: %.2lf\n", sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
        printf("Velikost vektoru v je: %.2lf\n", sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
        break;
    case porovnani: {
        double lenU = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
        double lenV = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        if (fabs(lenU - lenV) < 1e-6)
            printf("Vektory u a v mají stejnou velikost.\n");
        else if (lenU > lenV)
            printf("Vektor u je vetsi nez vektor v.\n");
        else
            printf("Vektor v je vetsi nez vektor u.\n");
        break;
    }
    }
}
