#pragma once

#define STR_SIZE 50 

struct t_album
{
    char  interpret[STR_SIZE];
    char  nazev[STR_SIZE];
    int   rok;
    struct t_album* dalsi;
};


void add(char* interpret, char* nazev, int rok, struct t_album** uk_prvni);
void del(char* nazev, struct t_album** uk_prvni);