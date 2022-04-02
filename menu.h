#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#include "icone.h"
#include "entidade.h"

int menuPrincipal();
int menuCriar();
int menuCriarOutro();
int menuSalvarOutro();
int menuRotacionar();

void menu_principal(void);
void menu_criar(IconeArr *iconeArr);
void menu_criar_usuario(IconeArr *iconeArr);
void menu_criar_aleatorio(IconeArr *iconeArr);
void menu_criar_reflexao(IconeArr *iconeArr);
void menu_salvar_outro(IconeArr *iconeArr, int indice, Icone *newIc);


void interfaceRotacionar(IconeArr *iconeArr);
void interfaceRefletir(IconeArr *iconeArr, int tipo);
void interfaceSimetria(IconeArr *iconeArr);
void interfaceDeletar(IconeArr *iconeArr);
void interfaceDuplicar(IconeArr *iconeArr);
