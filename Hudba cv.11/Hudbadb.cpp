#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hudbadb.h"

void add(char* interpret, char* nazev, int rok, struct t_album** uk_prvni)
{
	struct t_album* noveAlbum;
	struct t_album* aktAlbum;

	// 1. Alokace paměti (v C není nutné přetypování void*, ale pro kompatibilitu s C++ kompilátorem ho necháme)
	noveAlbum = (struct t_album*)malloc(sizeof(struct t_album));

	// 2. Naplnění daty
	// Poznámka: strcpy_s je bezpečnější verze pro Visual Studio. 
	// V čistém Linux C by se použilo strncpy nebo strcpy.
	strcpy_s(noveAlbum->interpret, STR_SIZE, interpret);
	strcpy_s(noveAlbum->nazev, STR_SIZE, nazev);
	noveAlbum->rok = rok;
	noveAlbum->dalsi = NULL;

	// 3. Zařazení do seznamu

	// A) Seznam je prázdný
	if (*uk_prvni == NULL)
	{
		*uk_prvni = noveAlbum;
		return;
	}

	// B) Vkládáme na začátek (podle abecedy Interpreta)
	// strcmp vrací < 0, pokud je první řetězec abecedně "menší" (dříve) než druhý
	if (strcmp(noveAlbum->interpret, (*uk_prvni)->interpret) < 0)
	{
		noveAlbum->dalsi = *uk_prvni;
		*uk_prvni = noveAlbum;
		return;
	}

	// C) Procházíme seznam a hledáme místo
	aktAlbum = *uk_prvni;
	while (aktAlbum)
	{
		// Jsme na konci seznamu -> připojíme nakonec
		if (aktAlbum->dalsi == NULL)
		{
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		// Máme vložit před následující prvek? (porovnáváme s následujícím interpretem)
		else if (strcmp(noveAlbum->interpret, aktAlbum->dalsi->interpret) < 0)
		{
			noveAlbum->dalsi = aktAlbum->dalsi; // Vložíme "mezi"
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		aktAlbum = aktAlbum->dalsi; // Posun na další
	}
}

void del(int rok, struct t_album** uk_prvni)
{
	struct t_album* aktAlbum;

	// Mazání na začátku seznamu (pokud rok odpovídá)
	while (*uk_prvni && (*uk_prvni)->rok == rok)
	{
		struct t_album* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni);  // Uvolnění paměti
		*uk_prvni = newPrvni;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum && aktAlbum->dalsi) // Procházení seznamu
	{
		if (aktAlbum->dalsi->rok == rok) // Následující je ke smazání
		{
			struct t_album* newDalsi = aktAlbum->dalsi->dalsi;
			free(aktAlbum->dalsi);
			aktAlbum->dalsi = newDalsi;
		}
		else
		{
			aktAlbum = aktAlbum->dalsi; // Posun jen pokud nemažeme (aby jsme nepřeskočili více záznamů za sebou)
		}
	}
}