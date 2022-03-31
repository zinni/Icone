#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#define BLOCO 5

#define MSG_SIZE 255


typedef struct _icone_arr {

    Icone **arr;
    int tam;
    int blocos;

} IconeArr;


void substituir_icone(IconeArr *iconeArr, int indice, Icone *newIc);

void icone_reflexao(IconeArr *iconeArr, int tipo);

void verificar_simetria(IconeArr *IconeArr);

Icone* criar_icone_especi();

Icone* buscar_icone(int indice, IconeArr *iconeArr);

void icone_salva(IconeArr *iconeArr, Icone *ic);

void imprimir_icones(IconeArr *iconeArr);

IconeArr* inicArr();

Icone* criar_icone_randomico();

Icone* icone_duplicado(Icone *ic);

int icone_simetrico(Icone *ic);

int icone_simetricoVertical(Icone *ic);

int icone_simetricoHorizontal(Icone *ic);

Icone* reflexaoVertical(Icone *ic);

Icone* reflexaoHorizontal(Icone *ic);

void aperte_enter();

void imprime_sucesso(char sucesso[MSG_SIZE]);

void imprime_erro(char erro[MSG_SIZE]);

void mudar_cor(int cor);

void cor_padrao();
