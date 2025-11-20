#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // Pro system("pause")

int main() {
    // Názvy souborů
    const char* vstupniSoubor = "vstup.txt";
    const char* vystupniSoubor = "vysledky.txt"; 

    // 1. Otevření souboru
    FILE* f_in = fopen(vstupniSoubor, "r");

    if (f_in == NULL) {
        printf("Chyba: Soubor '%s' nebyl nalezen.\n", vstupniSoubor);
        printf("Ujistete se, ze je ve slozce s projektem.\n");
        system("pause");
        return 1;
    }

    char text[2000];
    int pocetPismen = 0;
    int pocetCislic = 0;
    int i = 0;
    char c;

    // 2. Načítání
    while ((c = fgetc(f_in)) != EOF) {
        text[i] = c;
        if (isalpha(c)) pocetPismen++;
        else if (isdigit(c)) pocetCislic++;

        i++;
        if (i >= 1999) break;
    }
    text[i] = '\0';
    fclose(f_in);

    // 3. Výpis
    printf("Cv10 - Cteni textu ze souboru\n\n");
    printf("Obsahuje:\n%s\n", text);

    // 4. Vstup od uživatele
    char hledanyZnak;
    printf("\nZadejte libovolny znak: ");
    scanf(" %c", &hledanyZnak);

    int pocetVyskytu = 0;
    for (int j = 0; text[j] != '\0'; j++) {
        if (text[j] == hledanyZnak) pocetVyskytu++;
    }

    // 5. Výpis statistik
    printf("\nStatistika:\n");
    printf("Pocet pismen: %d\n", pocetPismen);
    printf("Pocet cislic: %d\n", pocetCislic);
    printf("Pocet vyskytu znaku '%c': %d\n", hledanyZnak, pocetVyskytu);

    // 6. Uložení
    FILE* f_out = fopen(vystupniSoubor, "w+");
    if (f_out != NULL) {
        fprintf(f_out, "Vysledky:\n%s\n", text);
        fprintf(f_out, "Pismena: %d, Cislice: %d, Znak '%c': %d\n", pocetPismen, pocetCislic, hledanyZnak, pocetVyskytu);
        fclose(f_out);
        printf("\nVysledky ulozeny do '%s'.\n", vystupniSoubor);
    }

    printf("\nKonec programu.\n");
    system("pause"); // Čekání na stisk klávesy
    return 0;
}