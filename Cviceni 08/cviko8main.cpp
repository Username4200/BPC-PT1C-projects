#include <stdio.h>
#include "bartonek.h"

int main() {
    double a1, b1, a2, b2;
    double pr_zac, pr_kon;

    printf("Zadejte 1. interval:\n");
    scanf("%lf %lf", &a1, &b1);

    printf("Zadejte 2. interval:\n");
    scanf("%lf %lf", &a2, &b2);

    if (prunik(a1, b1, a2, b2, &pr_zac, &pr_kon)) {
        printf("Prunik intervalu (%.1f, %.1f) a (%.1f, %.1f) je (%.1f %.1f)\n",
            a1, b1, a2, b2, pr_zac, pr_kon);
    }
    else {
        printf("Prunik intervalu (%.1f, %.1f) a (%.1f, %.1f) neexistuje\n",
            a1, b1, a2, b2);
    }

    return 0;
}