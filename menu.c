#include "menu.h"

//INTERFACE DOS MENUS
int menuPrincipal(){

    int opcao;

    mudar_cor(1);
    printf("\n\n               GERADOR DE ÍCONES");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t 1. Criar um novo ícone.");
    printf("\n\t 2. Mostrar lista de ícones salvos.");
    printf("\n\t 3. Apagar um ícone.");
    printf("\n\t 4. Verificar simetria de um ícone.");
    printf("\n\t 5. Reflexão horizontal ou vertical.");
    printf("\n\t 6. Rotacionar ícone em 90°.");
    printf("\n\t 7. Criar copia aumentada.");
    printf("\n\t 0. Sair do programa.");
    mudar_cor(3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuCriar(){

    int opcao;

    mudar_cor(1);
    printf("\n\n        ESCOLHA A NATUREZA DO SEU ÍCONE");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t 1. Ícone aleatório.");
    printf("\n\t 2. Ícone do usuário.");
    printf("\n\t 0. Voltar ao menu principal.");
    mudar_cor(3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuCriarOutro(){

    int opcao;

    mudar_cor(11);
    printf("\n\n\t 1. Criar outro");
    printf("\n\t 2. Salvar");
    printf("\n\t 0. Voltar ao menu anterior.");
    mudar_cor(3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuReflexao(){

    int opcao;

    mudar_cor(1);
    printf("\n\n        ESCOLHA O TIPO DE REFLEXÃO");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t 1. Reflexão vertical.");
    printf("\n\t 2. Reflexão horizontal.");
    printf("\n\t 0. Voltar ao menu principal");
    mudar_cor(3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;

}

int menuSalvarOutro(){

    int opcao;

    mudar_cor(11);
    printf("\n\n\t 1. Salvar em um novo icone.");
    printf("\n\t 2. Salvar sobrescrevendo o icone atual.");
    printf("\n\t 0. Voltar ao menu principal");
    mudar_cor(3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;

}

int menuRotacionar(){

    int opcao;


    mudar_cor(1);
    printf("\n\n                  ROTACIONAR");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t 1. Rotacionar em 90°.");
    printf("\n\t 0. Voltar ao menu principal");
    mudar_cor(3);
    printf("\n\n Entre com a opção desejada: ");
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
                imprime_erro("ESCOLHA INVÁLIDA TENTE NOVAMENTE.");
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
                imprime_erro("ESCOLHA INVÁLIDA TENTE NOVAMENTE.");
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
                break;
            case 2:
                icone_salva(iconeArr, ic);
                break;
            case 0:
                icone_libera_memoria(ic);
                system("cls");
                break;
            default:
                imprime_erro("ESCOLHA INVÁLIDA TENTE NOVAMENTE.");
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
                break;
            case 2:
                icone_salva(iconeArr, ic);
                break;
            case 0:
                icone_libera_memoria(ic);
                system("cls");
                break;
            default:
                imprime_erro("ESCOLHA INVÁLIDA TENTE NOVAMENTE.");
                break;
        }
    }
}

void menu_criar_reflexao(IconeArr *iconeArr) {

    if(iconeArr->tam == 0){

        imprime_erro("\tNÃO HA ICONES CADASTRADOS.");
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
                imprime_erro("ESCOLHA INVÁLIDA TENTE NOVAMENTE.");
                break;
        }
    }
}


//um submenu para o usuario ter a opção de substituir o icone ou salvar em um novo icone
void menu_salvar_outro(IconeArr *iconeArr, int indice, Icone *newIc) {



    int opcao_menu = -1;

    while (opcao_menu < 0 || opcao_menu > 2) {

        system("cls");

        printf("\n\n");
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
                imprime_erro("ESCOLHA INVÁLIDA TENTE NOVAMENTE.");
                break;
        }
    }
}



//Para não deixar esse codigo todo dentro do menuPrincipal, criei essa função
void interfaceRotacionar(IconeArr *iconeArr){

     system("cls");
     if(iconeArr->tam == 0){

        imprime_erro("\tNÃO HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    int codigo;

    Icone *newIc;
    Icone *ic;

    imprimir_icones(iconeArr);

    printf("\nEntre com o index do ícone que deseja rotacionar-> ");
    scanf("%d", &codigo);
    ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
       system("cls");
       imprime_erro("ÍCONE NÃO ENCONTRADO, VERIFIQUE O CÓDIGO E TENTE NOVAMENTE.");
       return;
    }

    newIc = icone_rotaciona(ic);

    if(newIc == NULL){

        system("cls");
        imprime_erro("NÃO HÁ MEMORIA SUFICIENTE, FECHE ALGUM PROGRAMA E TENTE NOVAMENTE.");
        return;

     }

     menu_salvar_outro(iconeArr, codigo - 1, newIc);


}

void interfaceRefletir(IconeArr *iconeArr, int tipo){

    imprimir_icones(iconeArr);

    int codigo;

    printf("\nEntre com o codigo do ícone que deseja criar reflexão-> ");
    scanf("%d", &codigo);

    Icone *ic = buscar_icone(codigo - 1, iconeArr);


    if(ic == NULL){
        system("cls");
        imprime_erro("ÍCONE NÃO ENCONTRADO, VERIFIQUE O CÓDIGO E TENTE NOVAMENTE.");
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
        imprime_erro("NÃO HÁ MEMORIA SUFICIENTE, PORFAVOR FECHE ALGUM PROCESSO OU APAGUE ALGUM ÍCONE.");
        return;

    }

    menu_salvar_outro(iconeArr, codigo - 1, newIc);

}

void interfaceSimetria(IconeArr *iconeArr){

    if(iconeArr->tam == 0){

        imprime_erro("\tNÃO HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    imprimir_icones(iconeArr);

    int codigo;

    printf("Codigo do icone-> ");

    scanf("%d", &codigo);

    Icone *ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
         system("cls");
         imprime_erro("\tÍCONE NÃO ENCONTRADO, VERIFIQUE O CÓDIGO E TENTE NOVAMENTE.");
         return;
    }


    system("cls");
    printf("ÍCONE %s", icone_simetrico(ic) == 1 ? "SIMÉTRICO" : "ASSIMÉTRICO");
    aperte_enter();


}

void interfaceDeletar(IconeArr *iconeArr){

    if(iconeArr->tam == 0){

        imprime_erro("\tNÃO HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    imprimir_icones(iconeArr);

    int codigo;

    printf("Codigo do icone-> ");

    scanf("%d", &codigo);

    Icone *ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
         system("cls");
         imprime_erro("\tÍCONE NÃO ENCONTRADO, VERIFIQUE O CÓDIGO E TENTE NOVAMENTE.");
         return;
    }

    icone_deletar(codigo - 1, iconeArr);

}

void interfaceDuplicar(IconeArr *iconeArr){

    if(iconeArr->tam == 0){

        imprime_erro("\tNÃO HA ICONES CADASTRADOS.");
        aperte_enter();
        return;

    }

    imprimir_icones(iconeArr);

    int codigo, fator;

    printf("Qual ícone deseja aumentar-> ");

    scanf("%d", &codigo);

    printf("Quantas vezes deseja aumentar o ícone, 2x ou 4x?");

    scanf("%d", &fator);

    Icone *ic = buscar_icone(codigo - 1, iconeArr);

    if(ic == NULL){
         system("cls");
         imprime_erro("\tÍCONE NÃO ENCONTRADO, VERIFIQUE O CÓDIGO E TENTE NOVAMENTE.");
         return;
    }

    Icone *novo;

    novo = icone_multiplicar_tamanho(ic, fator);

    menu_salvar_outro(iconeArr, codigo - 1, novo);
}
