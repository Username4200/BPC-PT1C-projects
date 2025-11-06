#include "bartonek.h";

int prunik(double zacatek1, double konec1,
    double zacatek2, double konec2,
    double* vysl_zacatek, double* vysl_konec)
{
  
    if (zacatek1 > konec1) {
        double temp = zacatek1;
        zacatek1 = konec1;
        konec1 = temp;
    }
    if (zacatek2 > konec2) {
        double temp = zacatek2;
        zacatek2 = konec2;
        konec2 = temp;
    }

   
    double z = (zacatek1 > zacatek2) ? zacatek1 : zacatek2;
    double k = (konec1 < konec2) ? konec1 : konec2;

    
    if (z <= k) {
        *vysl_zacatek = z;
        *vysl_konec = k;
        return 1;  
    }
    else {
        return 0;
    }
}