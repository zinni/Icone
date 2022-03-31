#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#include "icone.h"
#include "entidade.h"

int menuPrincipal();
void menu_principal(void);
int menuCriar();
void menu_criar(IconeArr *iconeArr);
int menuCriarOutro();
void menu_criar_usuario(IconeArr *iconeArr);
void menu_criar_aleatorio(IconeArr *iconeArr);
void menu_criar_reflexao(IconeArr *iconeArr);
