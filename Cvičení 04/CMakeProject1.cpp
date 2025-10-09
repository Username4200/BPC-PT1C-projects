// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"

using namespace std;


int jeprestupny(int rok)
{
	if (rok % 4 == 0 )
		

	{
		if (rok % 100 != 0)
			return 1;
		
	}

	if (rok % 400 == 0)
		return 1;
	else
		return 0;




}

int main()
{
	printf(" rok 1000 %d\n", jeprestupny(1000));

	printf(" rok 2000 %d\n", jeprestupny(2000));

	printf(" rok 2002 %d\n", jeprestupny(2002));

	printf(" rok 2012 %d\n", jeprestupny(2012));

	printf(" rok 2022 %d\n", jeprestupny(2022));

	printf(" rok 2200 %d\n", jeprestupny(2200));

	printf(" rok 2024 %d\n", jeprestupny(2024));

	

	return 0;
}
