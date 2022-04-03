#include "menu.h"

//INTERFACE DOS MENUS
int menuPrincipal(){

    int opcao;

    mudar_cor(1);
    printf("\n\n               GERADOR DE �CONES");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t1. Criar um novo �cone.");
    printf("\n\t2. Mostrar lista de �cones salvos.");
    printf("\n\t3. Apagar um �cone.");
    printf("\n\t4. Verificar simetria de um �cone.");
    printf("\n\t5. Reflex�o horizontal ou vertical.");
    printf("\n\t6. Rotacionar �cone em 90�.");
    printf("\n\t7. Criar copia aumentada.");
    printf("\n\t0. Sair do programa.");
    mudar_cor(3);
    printf("\n\nEntre com a op��o desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuCriar(){

    int opcao;

    mudar_cor(1);
    printf("\n\n        ESCOLHA A NATUREZA DO SEU �CONE");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t1. �cone aleat�rio.");
    printf("\n\t2. �cone do usu�rio.");
    printf("\n\t0. Voltar ao menu principal.");
    mudar_cor(3);
    printf("\n\nEntre com a op��o desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuCriarOutro(){

    int opcao;

    mudar_cor(11);
    printf("\n\n\t 1.Criar outro");
    printf("\n\t 2.Salvar");
    printf("\n\t 0.Voltar ao menu anterior.");
    mudar_cor(3);
    printf("\n\nEntre com a op��o desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuReflexao(){

    int opcao;

    mudar_cor(1);
    printf("\n\n        ESCOLHA O TIPO DE REFLEX�O");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t1. Reflex�o vertical.");
    printf("\n\t2. Reflex�o horizontal.");
    printf("\n\t0. Voltar ao menu principal");
    mudar_cor(3);
    printf("\n\nEntre com a op��o desejada: ");
    scanf("%d", &opcao);
    return opcao;

}

int menuSalvarOutro(){

    int opcao;

    mudar_cor(11);
    printf("\n\n\t1. Salvar em um novo icone.");
    printf("\n\t2. Salvar sobrescrevendo o icone atual.");
    printf("\n\t0. Voltar ao menu principal");
    mudar_cor(3);
    printf("\n\nEntre com a op��o desejada: ");
    scanf("%d", &opcao);
    return opcao;

}

int menuRotacionar(){

    int opcao;


    mudar_cor(1);
    printf("\n\n                  ROTACIONAR");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t1. Rotacionar em 90�.");
    printf("\n\t0. Voltar ao menu principal");
    mudar_cor(3);
    printf("\n\nEntre com a op��o desejada: ");
    scanf("%d", &opcao);
    return opcao;

}


//PARTE LOGICA MENUS
void menu_principal(void) {
    system("cls");

    //Iniciando IconeArr struct que armazena o array de icones
    IconeArr *iconeArr = inicArr();

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuPrincipal();
        switch(opcao_menu) {
            case 1:
                menu_criar(iconeArr);
                break;
            case 2:
                system("cls");
                imprimir_icones(iconeArr);
                aperte_enter();
                break;
            case 3:
                system("cls");
                interfaceDeletar(iconeArr);
                break;
            case 4:
                system("cls");
                interfaceSimetria(iconeArr);
                break;
            case 5:
                system("cls");
                menu_criar_reflexao(iconeArr);
                break;
            case 6:
                system("cls");
                interfaceRotacionar(iconeArr);
                break;
            case 7:
                system("cls");
                interfaceDuplicar(iconeArr);
                break;
            case 0:
                printf("\n\n\nSaindo...\n\n");
                exit(0);
                break;
            default:
                system("cls");
                imprime_erro("ESCOLHA INV�LIDA TENTE NOVAMENTE.");
                aperte_enter();
                break;
        }
    }
}

void menu_criar(IconeArr *iconeArr) {
    system("cls");

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuCriar();
        switch(opcao_menu) {
            case 1:
                menu_criar_aleatorio(iconeArr);
                break;
            case 2:
                menu_criar_usuario(iconeArr);
                break;
            case 0:
                system("cls");
                break;
            default:
                system("cls");
                imprime_erro("ESCOLHA INV�LIDA TENTE NOVAMENTE.");
                aperte_enter();
                break;
        }
    }
}

void menu_criar_aleatorio(IconeArr *iconeArr) {
    system("cls");

    Icone *ic;
    ic = criar_icone_randomico();


    int opcao_menu = -1;
    while (opcao_menu != 0 && opcao_menu != 2) {
        opcao_menu = menuCriarOutro();
        switch(opcao_menu) {
            case 1:
                system("cls");
                icone_libera_memoria(ic);
                ic = criar_icone_randomico();
                if(ic == NULL){
                   system("cls");
                   imprime_erro("N�O H� MEMORIA SUFICIENTE, FECHE ALGUM PROGRAMA E TENTE NOVAMENTE.");
                   aperte_enter();
                   return;
                }
                break;
            case 2:
                icone_salva(iconeArr, ic);
                break;
            case 0:
                icone_libera_memoria(ic);
                system("cls");
                break;
            default:
                system("cls");
                imprime_erro("ESCOLHA INV�LIDA TENTE NOVAMENTE.");
                aperte_enter();
                break;
        }
    }
}

void menu_criar_usuario(IconeArr *iconeArr) {
    system("cls");

    Icone *ic;
    ic = criar_icone_especi();


    int opcao_menu = -1;
    while (opcao_menu != 0 && opcao_menu != 2) {
        opcao_menu = menuCriarOutro();
        switch(opcao_menu) {
            case 1:
                system("cls");
                icone_libera_memoria(ic);
                ic = criar_icone_especi();

                if(ic == NULL){

                   system("cls");
                   imprime_erro("N�O H� MEMORIA SUFICIENTE, FECHE ALGUM PROGRAMA E TENTE NOVAMENTE.");
                   aperte_enter();
                   return;

                }
                break;
            case 2:
                icone_salva(iconeArr, ic);
                break;
            case 0:
                icone_libera_memoria(ic);
                system("cls");
                break;
            default:
                system("cls");
                imprime_erro("ESCOLHA INV�LIDA TENTE NOVAMENTE.");
                aperte_enter();
                break;
        }
    }
}

void menu_criar_reflexao(IconeArr *iconeArr) {

    if(iconeArr->tam == 0){

        imprime_erro("\tN�O HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuReflexao();

        switch(opcao_menu) {
            case 1:
                interfaceRefletir(iconeArr, opcao_menu);
                break;
            case 2:
                interfaceRefletir(iconeArr, opcao_menu);
                break;
            case 0:
                system("cls");
                break;
            default:
                system("cls");
                imprime_erro("ESCOLHA INV�LIDA TENTE NOVAMENTE.");
                aperte_enter();
                break;
        }
    }
}


//um submenu para o usuario ter a op��o de substituir o icone ou salvar em um novo icone
void menu_salvar_outro(IconeArr *iconeArr, int indice, Icone *newIc, Icone *ic) {

    int opcao_menu = -1;

    while (opcao_menu < 0 || opcao_menu > 2) {

        system("cls");
        printf("\n\t--- �cone original ---\n\n");
        icone_imprime(ic);
        printf("\n\t-- �cone modificado --\n\n");
        icone_imprime(newIc);

        opcao_menu = menuSalvarOutro();

        switch(opcao_menu) {
            case 1:
                icone_salva(iconeArr, newIc);
                break;
            case 2:
                substituir_icone(iconeArr, indice, newIc);
                break;
            case 0:
                system("cls");
                break;
            default:
                system("cls");
                imprime_erro("ESCOLHA INV�LIDA TENTE NOVAMENTE.");
                aperte_enter();
                break;
        }
    }
}


//Para n�o deixar esse codigo todo dentro do menuPrincipal, criei essa fun��o
void interfaceRotacionar(IconeArr *iconeArr){

     system("cls");
     if(iconeArr->tam == 0){

        imprime_erro("\tN�O HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    int codigo;

    Icone *newIc;
    Icone *ic;

    imprimir_icones(iconeArr);

    printf("\nEntre com o c�digo do �cone que deseja rotacionar -> ");
    scanf("%d", &codigo);
    ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
       system("cls");
       imprime_erro("�CONE N�O ENCONTRADO, VERIFIQUE O C�DIGO E TENTE NOVAMENTE.");
       return;
    }

    newIc = icone_rotaciona(ic);

    if(newIc == NULL){

        system("cls");
        imprime_erro("N�O H� MEMORIA SUFICIENTE, FECHE ALGUM PROGRAMA E TENTE NOVAMENTE.");
        aperte_enter();
        return;

     }

     menu_salvar_outro(iconeArr, codigo - 1, newIc, ic);


}

void interfaceRefletir(IconeArr *iconeArr, int tipo){

    system("cls");
    imprimir_icones(iconeArr);

    int codigo;

    printf("\nEntre com o c�digo do �cone que deseja criar reflex�o-> ");
    scanf("%d", &codigo);

    Icone *ic = buscar_icone(codigo - 1, iconeArr);


    if(ic == NULL){
        system("cls");
        imprime_erro("�CONE N�O ENCONTRADO, VERIFIQUE O C�DIGO E TENTE NOVAMENTE.");
        return;
    }


    Icone *newIc;

    switch(tipo){
        case 1:
            newIc = reflexaoVertical(ic);
            break;

        case 2:
            newIc = reflexaoHorizontal(ic);
            break;
    }

    if(newIc == NULL){

        system("cls");
        imprime_erro("N�O H� MEMORIA SUFICIENTE, FECHE ALGUM PROGRAMA E TENTE NOVAMENTE.");
        aperte_enter();
        return;

    }

    menu_salvar_outro(iconeArr, codigo - 1, newIc, ic);

}

void interfaceSimetria(IconeArr *iconeArr){

    if(iconeArr->tam == 0){

        imprime_erro("\tN�O HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    imprimir_icones(iconeArr);

    int codigo;

    printf("Entre o c�digo do �cone que deseja verificar simetria -> ");

    scanf("%d", &codigo);

    Icone *ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
         system("cls");
         imprime_erro("\t�CONE N�O ENCONTRADO, VERIFIQUE O C�DIGO E TENTE NOVAMENTE.");
         return;
    }


    system("cls");
    printf("�CONE %s", icone_simetrico(ic) == 1 ? "SIM�TRICO" : "ASSIM�TRICO");
    aperte_enter();


}

void interfaceDeletar(IconeArr *iconeArr){

    if(iconeArr->tam == 0){

        imprime_erro("\tN�O HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    imprimir_icones(iconeArr);

    int codigo;

    printf("Entre com c�digo do �cone que deseja deletar -> ");

    scanf("%d", &codigo);

    Icone *ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
         system("cls");
         imprime_erro("\t�CONE N�O ENCONTRADO, VERIFIQUE O C�DIGO E TENTE NOVAMENTE.");
         return;
    }

    icone_deletar(codigo - 1, iconeArr);

}

void interfaceDuplicar(IconeArr *iconeArr){

    if(iconeArr->tam == 0){

        imprime_erro("\tN�O HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    imprimir_icones(iconeArr);

    int codigo, fator;

    printf("Entre com o c�digo do �cone que deseja aumentar -> ");

    scanf("%d", &codigo);


    Icone *ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
         system("cls");
         imprime_erro("\t�CONE N�O ENCONTRADO, VERIFIQUE O C�DIGO E TENTE NOVAMENTE.");
         return;
    }

    printf("Quantas vezes deseja aumentar o �cone?");

    scanf("%d", &fator);


    Icone *novo;

    novo = icone_multiplicar_tamanho(ic, fator);

    if(novo == NULL){

        system("cls");
        imprime_erro("N�O H� MEMORIA SUFICIENTE, FECHE ALGUM PROGRAMA E TENTE NOVAMENTE.");
        aperte_enter();
        return;


    }

    menu_salvar_outro(iconeArr, codigo - 1, novo, ic);
}
