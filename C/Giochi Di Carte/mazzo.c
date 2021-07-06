#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "carta.h"
#include "mazzo.h"
//  printf("testa %d, coda %d full %d fine %d\n", x->testa, x->coda, x->full, x->fine ); //debug only!

struct c_mazzo {
    carta *deck;
    int size;
    int full;
    int fine;
    int testa;
    int coda;
};

static mazzo newmazzo() {
    mazzo x = malloc(sizeof(struct c_mazzo));
    if (x == NULL) {
        printf("[ERROR] Memoria insufficiente per creare un mazzo. Libera RAM!\n");
        exit(0);
    }
    return x;
}

void debug(mazzo x) {
//  printf("Full: %d\n", x->full);
    printf("Fine: %d\n", x->fine);
    printf("Coda: %d\n", x->coda);
    printf("Testa: %d\n", x->testa);
//  printf("Size: %d\n", x->size);

}

mazzo crea_mazzo(int tipo) {
    mazzo x = newmazzo();
    switch (tipo) {
        case 1:
            x->deck = malloc((NUM_CARTE_IT + 1) * sizeof(carta));
            x->size = NUM_CARTE_IT;
            break;
        case 2:
            x->deck = malloc((NUM_CARTE_FR + 1) * sizeof(carta));
            x->size = NUM_CARTE_FR;
            break;
        default:
            printf("Tipo di carte non valido!\n");
            return NULL;
    }
    x->full = 0;
    x->fine = 0;
    x->testa = 0;
    x->coda = 0;
    return x;
}

int inserisci_carta(mazzo x, carta y) {
    if (x != NULL) {
        if (x->full) {
            printf("Impossibile effettuare l'inserimetno il mazzo è pieno\n");
            return 0;
        } else {
            x->deck[x->testa] = y;
            x->testa = (x->testa + 1) % x->size;
            if (x->fine)
                x->fine = 0;
            if (x->testa == x->coda)
                x->full = 1;
            return 1;
        }
    } else {
        printf("Impossibile inserire la carta mazzo inesistente\n");
        return 0;
    }
}


void inizialliza_mazzo(mazzo x) {
    //DA AGGIORNARE [CARTE FR !]
    int i, y;
    if (x->full == 0 && x->testa == 0 && x->coda == 0) {
        for (y = 1; y <= 4; y++)
            for (i = 1; i <= 10; i++)
                inserisci_carta(x, crea_carta(i, y));
        mischia_mazzo(x, -1);
    } else {
        printf("Impossibile iniziallizare il mazzo, il mazzo contiene delle carte.\n");
    }
}

int output_mazzo(mazzo x) {
    int i = x->coda;
    if (x->full == 0 && x->testa == 0 && x->coda == 0) {
        printf("Il mazzo è vuoto!\n");
        return 0;
    }
    do {
        output_carta(x->deck[i]);
        i = (i + 1) % x->size;
    } while (i != x->testa);
}

carta getcarta(mazzo x) {
    int i = x->coda;
    if (x->full == 0 && x->testa == 0 && x->coda == 0) {
        printf("Il mazzo è vuoto!\n");
        return NULL;
    }
    if (x->fine) {
        printf("Sono finite le carte\n");
        return NULL;
    } else {
        if ((x->coda + 1) % x->size == x->testa) {
            x->fine = 1;
        }
        x->coda = (x->coda + 1) % x->size;
        return x->deck[i];
    }
}

static void scambia(carta *a, carta *b) {
    carta c = *a;
    *a = *b;
    *b = c;
}

void reset_mazzo(mazzo x) {
    int i;
    for (i = 0; i < x->size; i++)
        del_carta(&(x->deck[i]));
    x->testa = 0;
    x->coda = 0;
    x->full = 0;
    x->fine = 0;
}

void del_mazzo(mazzo *x) {
    free(*x);
    *x = NULL;
}

void mischia_mazzo(mazzo x, int tentativo) {
    srand(time(NULL));
    if (x->full) {
        x->testa = x->coda = (rand() + tentativo) % x->size;
        x->fine = 0;
        int n_mischiate = ((rand() + tentativo) % 9999) + 80;
        int i, y;
        for (i = 0; i < n_mischiate; i++)
            scambia(&(x->deck[(rand() + tentativo) % 40]), &(x->deck[(rand() + tentativo) % 40]));
        printf("Il mazzo è stato mischiato [%d]\n", n_mischiate);
    } else {
        printf("Impossibile mischiare il mazzo, mancano delle carte!\n");
    }
}
