#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define MSG_SIZE 255

Icone* criar_icone_randomico(Icone * ic);

Icone* icone_duplicado(Icone *ic);

void icone_simetrico(Icone *ic);

int icone_simetricoVertical(Icone *ic);

int icone_simetricoHorizontal(Icone *ic);

Icone* reflexaoVertical(Icone *ic);

Icone* reflexaoHorizontal(Icone *ic);

void aperte_enter();

void imprime_sucesso(char sucesso[MSG_SIZE]);

void imprime_erro(char erro[MSG_SIZE]);
