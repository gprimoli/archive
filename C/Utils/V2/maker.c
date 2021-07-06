#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maker.h"

FILE *lista_c = NULL;
FILE *lista_h = NULL;
FILE *item_c = NULL;
FILE *item_h = NULL;
FILE *fmain = NULL;
FILE *make = NULL;

char item[30];
char lista[30];

char structitem[50][40];
int nstructitem;


int checklista = 0;
int funzioni_item = 0;
int funzioni_lista = 0;

//==============================================//

static char *stringupper(char *stringa) {
    int i = strlen(stringa);
    int y;
    char *copia = malloc(i * sizeof(char));
    for (y = 0; y < i; y++) {
        copia[y] = stringa[y] - 32;
    }
    return copia;
}

static void checkfile(void *x, char *nome) {
    if (x == NULL) {
        printf("Non è stato possibile creare il file %s\n", nome);
        exit(0);
    }
}

static char *aggiungi_h(char *nome) {
    char *nome_h = malloc((strlen(nome)) * sizeof(char));
    strcpy(nome_h, nome);
    strcat(nome_h, ".h");
    return nome_h;
}

static char *aggiungi_c(char *nome) {
    char *nome_c = malloc((strlen(nome)) * sizeof(char));
    strcpy(nome_c, nome);
    strcat(nome_c, ".c");
    return nome_c;
}

static char *aggiungi_o(char *nome) {
    char *nome_o = malloc((strlen(nome)) * sizeof(char));
    strcpy(nome_o, nome);
    strcat(nome_o, ".o");
    return nome_o;
}

//==============================================//

//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|
//                                          INIZIO CREAZIONE FILE                                               |
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|

void creaitem() {
    if (item_c == NULL && item_h == NULL) {
        printf("Inserisci il nome da dare all'item\n");
        scanf("%s", item);

        item_c = fopen(aggiungi_c(item), "w");
        checkfile(item_c, aggiungi_c(item));
        item_h = fopen(aggiungi_h(item), "w");
        checkfile(item_h, aggiungi_h(item));

        printf("\n\tItem creato correttamente :)\n");

    } else {
        printf("Il file item è già stato creato ed attualmente è aperto\n");
    }
}

void crealista() {
    if (lista_c == NULL && lista_h == NULL) {
        printf("\nInserisci il nome da dare alla lista\n");
        scanf("%s", lista);

        lista_c = fopen(aggiungi_c(lista), "w");
        checkfile(lista_c, aggiungi_c(lista));
        lista_h = fopen(aggiungi_h(lista), "w");
        checkfile(lista_h, aggiungi_h(lista));
        checklista++;
        printf("\n\tLista creata correttamente :)\n");

    } else {
        printf("Il file lista è già stato creato ed attualmente è aperto\n");
    }
}

void creamain() {
    if (fmain == NULL) {
        char nome[] = "main";
        fmain = fopen(aggiungi_c(nome), "w");
        checkfile(fmain, aggiungi_c(nome));

        printf("\n\tMain creato correttamente :)\n");
    } else {
        printf("Il file main è già stato creato ed attualmente è aperto\n");
    }
}

void creamakefile() {
    if (make == NULL) {
        char nome[] = "Makefile";
        make = fopen(nome, "w");
        checkfile(make, nome);

        printf("\n\tMakefile creato correttamente :)\n");
    } else {
        printf("Il file Makefile è già stato creato ed attualmente è aperto\n\n");
    }
}

//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|
//                                          FINE CREAZIONE FILE                                                 |
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|
//                                          INIZIO MODIFICA FILE:                                               |
//                                               FILE ITEM                                                      |
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|

void moditem_c() {
    int n = 0, i = 0, j;
    fprintf(item_c, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n");
    fprintf(item_c, "#include \"%s.h\"\n#define MAX 50\n\n", item);

    fprintf(item_c, "struct c_%s{\n", item);
    printf("\nSto realizzando la struct (inserire null per terminare)\n\n");
    do {
        printf("Inserisci il n:%d tipo (char, int, float...)\n", n);
        scanf("%s", structitem[i]);
        if (!strcmp(structitem[i], "null"))
            break;
        fprintf(item_c, "\t%s ", structitem[i]);
        i++;
        printf("Inserisci il nome da dare alla variabile di tipo %s precedentemente dichiarata\n", structitem[i - 1]);
        scanf("%s", structitem[i]);
        if (!strcmp(structitem[i - 1], "char"))
            fprintf(item_c, "%s[MAX];\n", structitem[i]);
        else
            fprintf(item_c, "%s;\n", structitem[i]);
        i++;
        nstructitem++;
        n++;
    } while (1);

//gestione variabili
    printf("\nIl numero di variabili che contiene la struct %s è %d:\n", item, nstructitem);
    for (j = nstructitem, i = 0; j; i = i + 2, j--)
        printf("%s %s\n", structitem[i], structitem[i + 1]);
    fprintf(item_c, "};\n\n");

//staic function
    fprintf(item_c, "//=================================================//\n\n");
    fprintf(item_c,
            "static void checkstruct(void *x){\n\tif(x == NULL){\n\t\tprintf(\"Il %s risulta NULL (bisogna usare la funzione crea%s() !!!)\\n\");\n\t\texit(1);\n\t}\n}\n\n",
            item, item);
    fprintf(item_c,
            "static %s newstruct(){\n\t%s x=malloc(sizeof(struct c_%s));\n\tif(x==NULL){\n\t\tprintf(\"[ERROR] Spazio insufficiente per creare un %s\\n\");\n\t\texit(0);\n\t}else{\n\t\treturn x;\n\t}\n}\n\n",
            item, item, item, item);
    fprintf(item_c, "//=================================================//\n\n\n");

//funzione creaitem
    fprintf(item_c, "%s crea%s(){\n", item, item);
    for (j = nstructitem, i = 0; j; i = i + 2, j--)
        if (!(strcmp(structitem[i], "char")))
            fprintf(item_c, "\t%s %s[MAX];\n", structitem[i], structitem[i + 1]);
        else
            fprintf(item_c, "\t%s %s;\n", structitem[i], structitem[i + 1]);
    for (j = nstructitem, i = 0; j; i = i + 2, j--)
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_c, "\tprintf(\"Inserisci %s\\n\");\n", structitem[i + 1]);
            fprintf(item_c, "\tscanf(\"%%s\", %s);\n", structitem[i + 1]);
        } else {
            fprintf(item_c, "\tprintf(\"Inserisci %s\\n\");\n", structitem[i + 1]);
            fprintf(item_c, "\tscanf(\"%%d\", &%s);\n", structitem[i + 1]);
        }
    fprintf(item_c, "\treturn input_%s(", item);
    for (j = nstructitem, i = 0; j > 1; i = i + 2, j--)
        fprintf(item_c, "%s,", structitem[i + 1]);
    fprintf(item_c, "%s);\n", structitem[(nstructitem * 2) - 1]);
    fprintf(item_c, "}\n\n");
    funzioni_item++;

//funzione inputitem
    fprintf(item_c, "%s input_%s(", item, item);
    for (j = nstructitem, i = 0; j > 1; i = i + 2, j--) {
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_c, "%s *%s, ", structitem[i], structitem[i + 1]);
        } else {
            fprintf(item_c, "%s %s, ", structitem[i], structitem[i + 1]);
        }
    }
    if (!(strcmp(structitem[(nstructitem * 2) - 2], "char"))) {
        fprintf(item_c, "%s *%s", structitem[(nstructitem * 2) - 2], structitem[(nstructitem * 2) - 1]);
    } else {
        fprintf(item_c, "%s %s", structitem[(nstructitem * 2) - 2], structitem[(nstructitem * 2) - 1]);
    }
    fprintf(item_c, "){\n");

    fprintf(item_c, "\t%s x=newstruct();\n\tcheckstruct(x);\n\t", item);
    for (j = nstructitem, i = 0; j; i = i + 2, j--) {
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_c, "strcpy(x->%s,%s);\n\t", structitem[i + 1], structitem[i + 1]);
        } else {
            fprintf(item_c, "x->%s=%s;\n\t", structitem[i + 1], structitem[i + 1]);
        }
    }
    fprintf(item_c, "return x;\n");
    fprintf(item_c, "}\n\n");
    funzioni_item++;
//funzione outputitem
    fprintf(item_c, "void output_%s(%s x){\n", item, item);
    fprintf(item_c, "\tif(x == NULL%s)\n\t\tprintf(\"[ERROR 404] %s non trovato.\\n\");\n\telse{\n", stringupper(item),
            item);
    for (j = nstructitem, i = 0; j; i = i + 2, j--) {
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_c, "\t\tprintf(\"%s:\\t\\t\\t\\t%%s\\n\", x->%s);\n", structitem[i + 1], structitem[i + 1]);
        } else {
            fprintf(item_c, "\t\tprintf(\"%s:\\t\\t\\t\\t%%d\\n\", x->%s);\n", structitem[i + 1], structitem[i + 1]);
        }
    }
    fprintf(item_c, "\t}\n}\n\n");
    funzioni_item++;
//funzione get_xxx
    for (j = nstructitem, i = 0; j; i = i + 2, j--)
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_c, "%s *get_%s(%s x){\n", structitem[i], structitem[i + 1], item);
            fprintf(item_c, "\tcheckstruct(x);\n");
            fprintf(item_c, "\tchar *y=malloc(MAX*sizeof(char));\n\tstrcpy(y,x->%s);\n\treturn y;\n",
                    structitem[i + 1]);
            fprintf(item_c, "}\n");
            funzioni_item++;
        } else {
            fprintf(item_c, "%s get_%s(%s x){\n", structitem[i], structitem[i + 1], item);
            fprintf(item_c, "\tcheckstruct(x);\n");
            fprintf(item_c, "\treturn x->%s;\n", structitem[i + 1]);
            fprintf(item_c, "}\n\n");
            funzioni_item++;
        }

//funzione confrontaitem
    char c[50];
    printf("Quale campo vuoi utilizzare per confrontare due item?\n");
    scanf("%s", c);
    i = 0;
    do {
        if (i > nstructitem * 2) {
            printf("[WARNING] Hai inserito una variabile che non coincide con nessuna precedentemente inserita\n");
            printf("Quale campo vuoi utilizzare per confrontare due item?\n");
            scanf("%s", c);
            i = 0;
        }
        if (!strcmp(structitem[i], c)) {
            break;
        }
        i++;
    } while (1);

    fprintf(item_c, "\nint confronta%s(%s x, %s y){\n", item, item, item);
    fprintf(item_c, "\tcheckstruct(x);\n\tcheckstruct(y);\n");
    if (!strcmp(structitem[i - 1], "char")) {
        fprintf(item_c, "\tif(!strcmp(x->%s,y->%s))\n\t\treturn 1;\n\treturn 0;\n", structitem[i], structitem[i]);
    } else {
        fprintf(item_c, "\tif(x->%s == y->%s))\n\t\treturn 1;\n\treturn 0;\n", structitem[i], structitem[i]);
    }
    fprintf(item_c, "}\n\n");
    funzioni_item++;
//funzione duplicaitem
    fprintf(item_c, "%s duplica%s(%s x){\n", item, item, item);
    fprintf(item_c, "\tcheckstruct(x);\n");
    fprintf(item_c, "\t%s y=input_%s(", item, item);
    for (j = nstructitem, i = 1; j > 1; i = i + 2, j--) {
        fprintf(item_c, "get_%s(x),", structitem[i]);
    }
    fprintf(item_c, "get_%s(x)", structitem[(nstructitem * 2) - 1]);
    fprintf(item_c, ");\n\treturn y;\n");
    fprintf(item_c, "}\n\n");
    funzioni_item++;
//funzione destroyitem
    fprintf(item_c, "void destroy%s(%s *x){\n", item, item);
    fprintf(item_c, "\tfree(*x);\n\t*x= NULL;\n");
    fprintf(item_c, "}\n\n");
    funzioni_item++;
}

void moditem_h() {
    int i, j;
    fprintf(item_h, "#define NULL%s NULL\n\n", stringupper(item));
    fprintf(item_h, "typedef struct c_%s *%s;\n\n", item, item);
    fprintf(item_h, "%s crea%s();\n", item, item);
    fprintf(item_h, "%s input_%s(", item, item);
    for (j = nstructitem, i = 0; j > 1; i = i + 2, j--) {
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_h, "%s *%s, ", structitem[i], structitem[i + 1]);
        } else {
            fprintf(item_h, "%s %s, ", structitem[i], structitem[i + 1]);
        }
    }
    if (!(strcmp(structitem[(nstructitem * 2) - 2], "char"))) {
        fprintf(item_h, "%s *%s", structitem[(nstructitem * 2) - 2], structitem[(nstructitem * 2) - 1]);
    } else {
        fprintf(item_h, "%s %s", structitem[(nstructitem * 2) - 2], structitem[(nstructitem * 2) - 1]);
    }
    fprintf(item_h, ");\n");
    fprintf(item_h, "void output_%s(%s x);\n\n", item, item);
    for (j = nstructitem, i = 0; j; i = i + 2, j--)
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_h, "%s *get_%s(%s x);\n", structitem[i], structitem[i + 1], item);
        } else {
            fprintf(item_h, "%s get_%s(%s x);\n", structitem[i], structitem[i + 1], item);
        }
    fprintf(item_h, "\nint confronta%s(%s x, %s y);\n", item, item, item);
    fprintf(item_h, "%s duplica%s(%s x);\n", item, item, item);
    fprintf(item_h, "void destroy%s(%s *x);\n", item, item);


    //specifica.

    fprintf(item_h, "\n\n\n/*Specifica della struttura struttura\n");
    fprintf(item_h, "Sintattica:\n\t- Tipi di riferimento: %s\n\t- Tipi usati: boolean\n\n", item);
    fprintf(item_h,
            "Semantica:\n\tIl tipo %s\n\t- Il tipo %s contiene inoltre un elemento nil che rappresenta (!ARTICOLO!) %s vuoto, privo di informazioni.\n\n\n",
            item, item, item);
    fprintf(item_h, "Specifica degli operatori\nSintattica:\n\t\t");
    fprintf(item_h, "crea%s() -> %s\n\t\t", item, item);
    fprintf(item_h, "input_%s(", item);
    for (j = nstructitem, i = 0; j > 1; i = i + 2, j--)
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_h, "string,");
        } else {
            fprintf(item_h, "%s", structitem[i]);
        }
    if (!(strcmp(structitem[(nstructitem * 2) - 2], "char"))) {
        fprintf(item_h, "string");
    } else {
        fprintf(item_h, "%s", structitem[(nstructitem * 2) - 2]);
    }
    fprintf(item_h, ") -> %s\n\t\t", item);

    fprintf(item_h, "output_%s(%s) -> void\n\t\t", item, item);

    for (j = nstructitem, i = 1; j; i = i + 2, j--)
        if (!(strcmp(structitem[i], "char"))) {
            fprintf(item_h, "get_%s(%s) -> string\n\t\t", structitem[i], item);
        } else {
            fprintf(item_h, "get_%s(%s) -> %s\n\t\t", structitem[i], item, structitem[i - 1]);
        }

    fprintf(item_h, "confronta%s(%s,%s) -> boolean\n\t\t", item, item, item);
    fprintf(item_h, "duplica%s(%s) -> %s\n\t\t", item, item, item);
    fprintf(item_h, "destroy%s(%s) -> %s\n\n\n", item, item, item);

    fprintf(item_h, "Semantica:\n\t\t");
    fprintf(item_h, "crea%s() = \n\t\t\tPost:\n\t\t", item);
    fprintf(item_h, "input_%s(", item);
    for (j = nstructitem, i = 1; j > 1; i = i + 2, j--)
        fprintf(item_h, "%s,", structitem[i]);
    fprintf(item_h, "%s", structitem[(nstructitem * 2) - 1]);
    fprintf(item_h, ") =\n\t\t\tPost:\n\t\t");
    fprintf(item_h, "output_%s()\n\t\t\tPost:\n\t\t", item);
    for (j = nstructitem, i = 1; j; i = i + 2, j--)
        fprintf(item_h, "get_%s() = %s\n\t\t\tPost:\n\t\t", structitem[i], structitem[i]);

    fprintf(item_h, "confronta%s() =\n\t\t\tPost:\n\t\t", item);
    fprintf(item_h, "duplica%s() =\n\t\t\tPost:\n\t\t", item);
    fprintf(item_h, "destroy%s() =\n\t\t\tPost:\n*/", item);

}

//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|
//                                          FILE LISTA:                                                         |
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|


void modlista_c() {
    fprintf(lista_c, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n");
    fprintf(lista_c, "#include \"%s.h\"\n#include \"%s.h\"\n", item, lista);
    fprintf(lista_c, "#define MAX 30\n\n");
    fprintf(lista_c, "struct c_%s{\n\tchar *nome;\n\tint size;\n\tstruct node *first;\n};\n\n", lista);
    fprintf(lista_c, "struct node{\n\t%s value;\n\tstruct node *next;\n};\n\n", item);


    //static
    fprintf(lista_c, "//=================================================//\n\n");
    fprintf(lista_c,
            "static void checkstruct(void *x){\n\tif(x == NULL){\n\t\tprintf(\"Il %s risulta NULL (bisogna usare la funzione crea%s() !!!)\\n\");\n\t\texit(1);\n\t}\n}\n\n",
            lista, lista);
    fprintf(lista_c, "//=================================================//\n\n");

    fprintf(lista_c, "%s crea%s(){\n\t", lista, lista);
    fprintf(lista_c,
            "%s x=malloc(sizeof(struct c_%s));\n\tif(x==NULL){\n\t\tprintf(\"[ERROR] Spazio insufficiente per creare un %s\\n\");\n\t\texit(0);\n\t}else{\n\t\tx->nome = malloc(MAX*sizeof(char));\n\t\tx->size = 0;\n\t\tx->first = NULL;\n\t\treturn x;\n\t}\n}\n\n",
            lista, lista, lista);
    fprintf(lista_c, "%s input%s(int n){\n\t\n}\n\n", lista, lista);
    fprintf(lista_c, "void output%s(%s l){\n\t\n}\n\n", lista, lista);
    fprintf(lista_c, "void destroy%s(%s *l){\n\t\n}\n\n", lista, lista);
}

void modlista_h() {
    fprintf(lista_h, "typedef struct c_%s *%s;\n\n", lista, lista);
    fprintf(lista_h, "%s crea%s();\n", lista, lista);
    fprintf(lista_h, "%s input%s(int n);\n", lista, lista);
    fprintf(lista_h, "void output%s(%s l);\n", lista, lista);
    fprintf(lista_h, "void destroy%s(%s *l);\n", lista, lista);
}

//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|
//                                          FILE MAIN:                                                          |
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|


void modmain() {
    int i;
    fprintf(fmain, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n");

    if (checklista)
        fprintf(fmain, "#include \"%s.h\"\n#include \"%s.h\"\n", item, lista);
    else
        fprintf(fmain, "#include \"%s.h\"\n", item);

    fprintf(fmain, "\n\nint main(){\n");
    fprintf(fmain, "\tint risp;\n\tchar pausa[3];\n\tdo{\n");
    fprintf(fmain, "\t\tprintf(\"Fa la tua scelta. (-1 per uscire dal programma)\\n\");\n");

    if (checklista)
        for (i = 1; i <= funzioni_item + funzioni_lista; i++)
            fprintf(fmain, "\t\tprintf(\"[%d] \\n\");\n", i);
    else
        for (i = 1; i <= funzioni_item; i++)
            fprintf(fmain, "\t\tprintf(\"[%d] \\n\");\n", i);

    fprintf(fmain, "\t\tscanf(\"%%d\", &risp);\n");
    fprintf(fmain, "\t\tswitch(risp){\n");

    if (checklista)
        for (i = 1; i <= funzioni_item + funzioni_lista; i++)
            fprintf(fmain,
                    "\t\t\tcase %d: \t printf(\"Premi inserisci una lettera per continuare\\n\"); scanf(\"%%s\", pausa); break;\n",
                    i);
    else
        for (i = 1; i <= funzioni_item; i++)
            fprintf(fmain,
                    "\t\t\tcase %d: \t printf(\"Premi inserisci una lettera per continuare\\n\"); scanf(\"%%s\", pausa); break;\n",
                    i);

    fprintf(fmain, "\t\t\tcase -1: printf(\"Fine del programma\\n\"); return 0;\n");
    fprintf(fmain, "\t\t\tdefault: printf(\"Hai inserito un valore non valido, riprova.\\n\"); break;\n\t\t}\n");
    fprintf(fmain, "\t}while(1);\n\tprintf(\"\\n\\n\\n\\n\\n\");\n");
    fprintf(fmain, "\treturn 0;\n}\n\n");
    fprintf(fmain, "/*\n\n");
    fprintf(fmain, "*/\n");
}

//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|
//                                          FILE MAKEFILE:                                                      |
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|

void modmakefile() {
    if (checklista) {
        fprintf(make, "main.exe:\t %s.o %s.o main.o\n\tgcc %s.o %s.o main.o -o main.exe\n\n", item, lista, item, lista);
        fprintf(make, "%s.o:\t%s.c\n\tgcc -c %s.c\n\n", item, item, item);
        fprintf(make, "%s.o:\t%s.h %s.c\n\tgcc -c %s.c\n\n", lista, item, lista, lista);
        fprintf(make, "main.o:\t%s.h %s.h main.c\n\tgcc -c main.c\n", item, lista);
    } else {
        fprintf(make, "main.exe:\t %s.o main.o\n\tgcc %s.o main.o -o main.exe\n\n", item, item);
        fprintf(make, "%s.o:\t%s.c\n\tgcc -c %s.c\n\n", item, item, item);
        fprintf(make, "main.o:\t%s.h main.c\n\tgcc -c main.c\n", item);
    }

    fprintf(make, "del:\n\trm -f *.exe *.o");
}

//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|
//                                          FINE MODIFICA FILE                                                  |
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=|

void closeall() {
    if (checklista) {
        fclose(lista_c);
        fclose(lista_h);
    }
    fclose(item_c);
    fclose(item_h);
    fclose(fmain);
    fclose(make);
}
