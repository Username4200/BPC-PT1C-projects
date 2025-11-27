


using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
#include <string.h>

#include "hudbadb.h" 

struct t_album* prvni = NULL;


void clean_stdin() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void OnAdd()
{
	char my_interpret[STR_SIZE];
	char my_nazev[STR_SIZE];
	int my_year;


	printf("\nNazev alba : ");

	scanf_s(" %[^\n]", my_nazev, (unsigned)STR_SIZE);


	printf("Interpret : ");
	scanf_s(" %[^\n]", my_interpret, (unsigned)STR_SIZE);


	printf("Rok vydani : ");
	scanf_s("%d", &my_year);
	clean_stdin();

	add(my_interpret, my_nazev, my_year, &prvni);
}

void OnDel()
{
	char nazev_smazat[STR_SIZE];

	printf("\nZadejte nazev alba pro smazani: ");


	scanf_s(" %[^\n]", nazev_smazat, (unsigned)STR_SIZE);


	del(nazev_smazat, &prvni);
}

void ShowAlbums()
{
	struct t_album* aktAlbum = prvni;
	printf("\n\n");

	printf("%-25s %-25s %s\n", "Nazev alba", "Interpret", "Rok vydani");


	while (aktAlbum)
	{
		printf("%-25s %-25s %d\n", aktAlbum->nazev, aktAlbum->interpret, aktAlbum->rok);
		aktAlbum = aktAlbum->dalsi;
	}
	printf("\nStisknete Enter pro pokracovani...");
	getchar();
}


void OnRange()
{
	int r_od, r_do;
	int nalezeno = 0;
	struct t_album* aktAlbum = prvni;

	printf("\nZadejte rozmezi roku od do (napr. 2000 2010): ");
	if (scanf_s("%d %d", &r_od, &r_do) != 2) {
		clean_stdin();
		return;
	}
	clean_stdin();

	printf("\n");
	while (aktAlbum)
	{
		if (aktAlbum->rok >= r_od && aktAlbum->rok <= r_do)
		{

			if (nalezeno == 0) {

				nalezeno = 1;
			}
			printf("%-25s %-25s %d\n", aktAlbum->nazev, aktAlbum->interpret, aktAlbum->rok);
		}
		aktAlbum = aktAlbum->dalsi;
	}

	if (nalezeno == 0)
	{
		printf("V seznamu neni album vydany od roku %d, do roku %d.\n", r_od, r_do);
	}
	printf("\nStisknete Enter pro pokracovani...");
	getchar();
}

int main()
{
	char cmd;

	do
	{

		system("cls");

		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("R: Rok od/do     ");
		printf("Q: Konec\n\n");


		cmd = tolower(getchar());
		clean_stdin();

		switch (cmd)
		{
		case 'a':
			OnAdd();
			break;
		case 'd':
			OnDel();
			break;
		case 'p':
			ShowAlbums();
			break;
		case 'r':
			OnRange();
			break;
		}
	} while (cmd != 'q');

	return 0;
}
