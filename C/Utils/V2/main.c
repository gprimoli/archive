#include <stdio.h>
#include <stdlib.h>
#include "maker.h"

int main() {
//  char autodestruction[]="rm -f maker.exe";
    int risp, flag;
    printf("\t\t\tBenvenuto :)\n");
    printf("Questo programma è un maker creato da: Gennaro Pio Rimoli\n");
    printf("Serve a creare in maniera semplice e veloce gli item e le ADT lista\n");
    do {
        printf("Cosa vuoi creare?\n[1] Un item \n[2] Una lista \n");
        scanf("%d", &risp);
        switch (risp) {
            case 1:
                creaitem();
                creamain();
                creamakefile();
                //Fine fase di creazione
                moditem_c();
                moditem_h();
                //Fine modifica filei
                modmain();
                modmakefile();
                flag = 0;
                break;
            case 2:
                creaitem();
                crealista();
                creamain();
                creamakefile();
                //Fine fase di creazione
                moditem_c();
                moditem_h();
                modlista_c();
                modlista_h();
                //Fine modifica file
                modmain();
                modmakefile();
                flag = 0;
                break;
            default:
                printf("[WARNING] Inserisci una risposta valida.\n");
                flag = 1;
        }
    } while (flag);

    closeall();

    printf("\nAbracadabra...Il mio compito è terminato\n\t\t\t Bye ^.^\n\n");
//  system(autodestruction);
    return 0;
}
