#include <stdio.h>
#include <ctype.h>  // knihovna pro funkce isalpha(), isdigit()
#include <string.h>

int PocetPismen(char* text) {
    int pocet = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) pocet++; // isalpha() z <ctype.h> vrací true, pokud je znak písmeno
    }
    return pocet;
}

int PocetCislic(char* text) {
    int pocet = 0;
    for (int i = 0; text[i] != '\0'; i++) { //  projdeme celý text znak po znaku, dokud nenarazíme na konec řetězce '\0'
        if (isdigit((unsigned char)text[i])) pocet++;
    }
    return pocet;
}

int DelkySlov(char* text, int* delky) { //Zjistí délky všech slov v textu a uloží je do pole delky[]
    int delka = 0, pocetSlov = 0; 
    for (int i = 0; text[i] != '\0'; i++) { // aktuální délka právě čteného slova , celkový počet slov nalezených v textu
        if (isalpha((unsigned char)text[i]) || isdigit((unsigned char)text[i])) {  // pokud je znak písmeno nebo číslice, přičti k délce slova

            delka++;
        }
        else if (delka > 0) {
            delky[pocetSlov++] = delka; 
            delka = 0;
        }
    }
    if (delka > 0) delky[pocetSlov++] = delka; // poslední slovo
    return pocetSlov;
}

int main()
{
    char text[] = "Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi. Auto Hyundai ix35 ma pres 120 konskych sil.";

    printf("Dany textovy retezec:\n%s\n", text);

    int pismena = PocetPismen(text);
    int cisla = PocetCislic(text);
    printf("Pocet pismen v danem retezci je %d\n", pismena);
    printf("Pocet cisel v danem retezci je %d\n", cisla);

    int JednotliveDelky[100];
    int pocetSlov = DelkySlov(text, JednotliveDelky);
    printf("Pocet slov je %d\n", pocetSlov);
    printf("Delky slov jsou: ");
    for (int i = 0; i < pocetSlov; i++) {
        printf("%d", JednotliveDelky[i]);
        if (i < pocetSlov - 1) printf(", ");
    }
    printf("\n");

    return 0;
}