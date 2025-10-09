// 2. prestup. cv04.cpp : Defines the entry point for the application.
//

#include "2. prestup. cv04.h"

using namespace std;

int jeprestupny(int rok)
{
	if (rok % 4 == 0)
	{
		if (rok % 100 != 0)
			return (1);
	}

	if (rok % 400 == 0)
		return 1;

	else
		return 0;

	



}



 


int main()
{
	
	int start, end;

	printf("Zadejte prvni rok:  ");
	scanf("%d", &start);

	printf("Zadejte poslední rok:   ");
	scanf("%d", &end);

	for (int i = start; i <= end; i++) {
		printf("Rok %d je prestupny: %d \n", i, jeprestupny(i));






	}





	return 0;
}
