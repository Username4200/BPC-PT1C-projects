#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hudbadb.h"

void add(char* interpret, char* nazev, int rok, struct t_album** uk_prvni)
{
	struct t_album* noveAlbum;
	struct t_album* aktAlbum;

	noveAlbum = (struct t_album*)malloc(sizeof(struct t_album));
	strcpy_s(noveAlbum->interpret, STR_SIZE, interpret);
	strcpy_s(noveAlbum->nazev, STR_SIZE, nazev);
	noveAlbum->rok = rok;
	noveAlbum->dalsi = NULL;
	if (*uk_prvni == NULL)
	{
		*uk_prvni = noveAlbum;
		return;
	}

	if (strcmp(noveAlbum->interpret, (*uk_prvni)->interpret) < 0)
	{
		noveAlbum->dalsi = *uk_prvni;
		*uk_prvni = noveAlbum;
		return;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum)
	{
		if (aktAlbum->dalsi == NULL)
		{
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		else if (strcmp(noveAlbum->interpret, aktAlbum->dalsi->interpret) < 0)
		{
			noveAlbum->dalsi = aktAlbum->dalsi;
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		aktAlbum = aktAlbum->dalsi;
	}
}

void del(char* nazev, struct t_album** uk_prvni)
{
	struct t_album* aktAlbum;



	while (*uk_prvni && strcmp((*uk_prvni)->nazev, nazev) == 0)
	{
		struct t_album* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni);
		*uk_prvni = newPrvni;
	}


	aktAlbum = *uk_prvni;
	while (aktAlbum && aktAlbum->dalsi)
	{
		if (strcmp(aktAlbum->dalsi->nazev, nazev) == 0)
		{
			struct t_album* newDalsi = aktAlbum->dalsi->dalsi;
			free(aktAlbum->dalsi);
			aktAlbum->dalsi = newDalsi;
		}
		else
		{
			aktAlbum = aktAlbum->dalsi;
		}
	}
}