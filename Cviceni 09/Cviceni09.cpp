#include <stdio.h>
#include "VectorMath.h"

int main() {
    int volba;
    printf("Zvolte operaci (1 = soucet, 2 = vektorovy soucin, 3 = skalarni soucin, 4 = velikost vektoru, 5 = porovnani vektoru): ");
    scanf_s("%d", &volba);

    if (volba >= 1 && volba <= 5)
        operace((enum typOperace)volba);
    else
        printf("Neplatná volba!\n");

    return 0;
}
