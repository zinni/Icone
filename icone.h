#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct _icone {
    short int **pixels;
    int tamanho;
} Icone;

Icone * icone_cria(int tam);

void icone_libera_memoria(Icone *ic);

void icone_atribui(Icone *ic, int i, int j, int v);

int icone_acessa(Icone *ic, int i, int j);

int icone_tam (Icone *ic);

void icone_preenche_aleatorio(Icone *ic);

void icone_imprime(Icone *ic);

Icone* icone_copia(Icone *ic);

Icone* icone_rotaciona(Icone *ic1);
