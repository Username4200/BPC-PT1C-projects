#pragma once

#define STR_SIZE 51 // Velikost pro text (Interpret, Nazev)

// Definice struktury alba (nahrazuje t_auto)
struct t_album
{
    char  interpret[STR_SIZE];
    char  nazev[STR_SIZE];
    int   rok;
    struct t_album* dalsi;
};

// Prototypy funkcí
// P?idáváme položky: Interpret, Název, Rok
void add(char* interpret, char* nazev, int rok, struct t_album** uk_prvni);
void del(int rok, struct t_album** uk_prvni);