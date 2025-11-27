#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // pro tolower
#include <string.h>

#include "Hudbadb.h" 

struct t_album* prvni = NULL; // Globální ukazatel na začátek seznamu

// Pomocná funkce pro vyčištění bufferu klávesnice
void clean_stdin() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void OnAdd()
{
	char my_interpret[STR_SIZE];
	char my_nazev[STR_SIZE];
	int my_year;

	// Načtení Názvu alba (i s mezerami)
	printf("\nNazev alba : ");
	// " %[^\n]" znamená: přeskoč bílé znaky na začátku a čti vše až do konce řádku (\n)
	scanf_s(" %[^\n]", my_nazev, (unsigned)STR_SIZE);

	// Načtení Interpreta
	printf("Interpret : ");
	scanf_s(" %[^\n]", my_interpret, (unsigned)STR_SIZE);

	// Načtení Roku
	printf("Rok vydani : ");
	scanf_s("%d", &my_year);
	clean_stdin(); // Po čísle zůstane v bufferu enter, musíme ho odstranit

	add(my_interpret, my_nazev, my_year, &prvni);
}

void OnDel()
{
	int my_year;

	printf("\nRok pro smazani: ");
	scanf_s("%d", &my_year);
	clean_stdin();
	del(my_year, &prvni);
}

void ShowAlbums()
{
	struct t_album* aktAlbum = prvni;
	printf("\n\n");
	// Hlavička tabulky zarovnaná dolevy (pomocí mínus u %s)
	printf("%-25s %-25s %s\n", "Nazev alba", "Interpret", "Rok vydani");
	// Oddělovač
	//                                                     Nazev...                  Interpret...              Rok
	//                                                     ------------------------- ------------------------- ---
	// Pozn: Podle obrázku v zadání jen jednoduchý výpis, ale zarovnání je hezčí.

	while (aktAlbum)
	{
		printf("%-25s %-25s %d\n", aktAlbum->nazev, aktAlbum->interpret, aktAlbum->rok);
		aktAlbum = aktAlbum->dalsi;
	}
	printf("\nStisknete Enter pro pokracovani...");
	getchar();
}

// Cvičení 11 - bod 2: Funkce pro rozmezí roků
void OnRange()
{
	int r_od, r_do;
	int nalezeno = 0; // Funguje jako boolean (0 = false, 1 = true)
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
			// Pokud jsme našli první záznam, vypíšeme hlavičku (volitelné, pro hezčí výpis)
			if (nalezeno == 0) {
				// printf("%-25s %-25s %s\n", "Nazev alba", "Interpret", "Rok vydani");
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
		// system("cls") je specifické pro Windows, v Linuxu by to bylo "clear"
		system("cls");

		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("R: Rok od/do     "); // Nová položka
		printf("Q: Konec\n\n");

		// Načtení znaku
		cmd = tolower(getchar());
		clean_stdin(); // Odstranění Enteru z bufferu

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
			OnRange(); // Volání nové funkce
			break;
		}
	} while (cmd != 'q');

	return 0;
}