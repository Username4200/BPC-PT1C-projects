#include <stdio.h>
#include <ctype.h> // Potřeba pro funkce isalpha a isdigit

int main() {
   
    const char* vstupniSoubor = "vstup.txt";
    const char* vystupniSoubor = "vysledky.txt";

    // 1. Otevření souboru pro čtení
    FILE* f_in = fopen(vstupniSoubor, "r");

    if (f_in == NULL) {
        printf("Chyba: Nelze otevrit soubor %s\n", vstupniSoubor);
        return 1;
    }

    
    char text[2000]; 
    int pocetPismen = 0;
    int pocetCislic = 0;
    int i = 0;
    char c;

    
    while ((c = fgetc(f_in)) != EOF) {
        text[i] = c; 

        if (isalpha(c)) {
            pocetPismen++;
        }
        else if (isdigit(c)) {
            pocetCislic++;
        }

        i++; 

        // Ochrana proti přeplnění pole (pro jistotu)
        if (i >= 1999) break;
    }
    text[i] = '\0'; // Ukončení řetězce nulovým znakem, aby to byl platný text
    fclose(f_in);   

    // 3. Výpis obsahu na obrazovku (podle zadání)
    printf("Cv10 - Cteni textu ze souboru\n\n");
    printf("Soubor: ../../../%s\n", vstupniSoubor); 
    printf("Obsahuje:\n");
    printf("%s\n", text);

    // 4. Zadání znaku uživatelem
    char hledanyZnak;
    printf("\nZadejte libovolny znak pro pocitani vyskytu v textu: ");
    scanf(" %c", &hledanyZnak); 

    // 5. Spočítání výskytů zadaného znaku
    int pocetVyskytu = 0;
    for (int j = 0; text[j] != '\0'; j++) {
        if (text[j] == hledanyZnak) {
            pocetVyskytu++;
        }
    }

    
    printf("\nStatistika souboru: ../../../%s\n", vstupniSoubor);
    printf("Pocet pismen v textu: %d\n", pocetPismen);
    printf("Pocet cislic v textu: %d\n", pocetCislic);
    printf("Pocet vyskytu znaku %c v textu: %d\n", hledanyZnak, pocetVyskytu);

    
    FILE* f_out = fopen(vystupniSoubor, "w");

    if (f_out == NULL) {
        printf("Chyba: Nelze zapsat do souboru %s\n", vystupniSoubor);
        return 1;
    }

    
    fprintf(f_out, "Cv10 - Cteni textu ze souboru\n\n");
    fprintf(f_out, "Vstupni soubor obsahuje:\n");
    fprintf(f_out, "%s\n", text);

    fprintf(f_out, "Statistika souboru: ../../../%s\n", vstupniSoubor);
    fprintf(f_out, "Pocet pismen v textu: %d\n", pocetPismen);
    fprintf(f_out, "Pocet cislic v textu: %d\n", pocetCislic);
    fprintf(f_out, "Pocet vyskytu znaku %c v textu: %d\n", hledanyZnak, pocetVyskytu);

    fclose(f_out); // Důležité: zavřít soubor pro uložení změn

    return 0;
}