// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include <stdio.h>
#include <math.h>

//Tomáš BARTONĚK 283916

using namespace std;
void soucet(double a[3], double b[3], double c[3])
{
	for (int i = 0; i < 3; i++)
	{
		c[i] = a[i] + b[i];
	}
	return;
}

double velikost(double a[3])
{
		return	sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);

}

double skalarnisoucin(double a[3], double b[3])
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];


}

void vektorovysoucin(double a[3], double b[3], double vc[3]) {
	vc[0] = a[1] * b[2] - a[2] * b[1];
	vc[1] = a[2] * b[0] - a[0] * b[2];
	vc[2] = a[0] * b[1] - a[1] * b[0];
}
int main()
{
	
	double a[3], b[3], c[3], vc[3];

	printf("zadejte souradnice vektoru A(x,y,z): ");
	scanf("%lf,%lf,%lf", &a[0], &a[1], &a[2]);


	printf("zadejte souradnice vektoru B(x,y,z): ");
	scanf("%lf,%lf,%lf", &b[0], &b[1], &b[2]);

	soucet(a, b, c);
	vektorovysoucin(a, b, vc);

	printf("\nSoucet vektoru A a b: (%.2f,%.2,%.f)\n", c[0], c[1], c[2]);
	printf("Velikost Vektoru A: %.2f\n", velikost(a));
	printf("Velikost Vektoru B: %.2f\n", velikost(b));
	printf("Skalarny součin vektor A a B: %.2f\n", skalarnisoucin(a, b));
	printf("Vektory soucin A a B:( %lf, %lf, %lf)\n", vc[0], vc[1], vc[2]);

	return 0;

}

