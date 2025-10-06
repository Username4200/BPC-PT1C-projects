// FunExt.cpp : Defines the entry point for the application.
//

#include "FunExt.h"

using namespace std;

int main()
{
	double maxY = DBL_MAX; // Initialize to maximum possible double value
	int maxX = INT_MAX; // Initialize to maximum possible int value
    for (int x = 10; x <= 20; ++x)
    {
        double y = 5 - 3 * x + 2 * (x - 5) * (x - 5) - (x - 10) * (x - 10) * (x - 10);

		if (y > maxY) // Check for new minimum
        {
			maxY = y; 
			maxX = x;  
        }
    }
    printf("Minimum value: %lf at x=%d\n", maxY, maxX);
    return 0;
}
