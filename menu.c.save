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
    printf("\n\t 3. Verificar simetria em um ícone.");
    printf("\n\t 4. Reflexão horizontal ou vertical..");
    printf("\n\t 5. Rotacionar ícone em 90°.");
    printf("\n\t 6. Criar copia aumentada.");
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
                imprimir_icones(iconeArr);
                verificar_simetria(iconeArr);
                break;
            case 4:
                system("cls");
                menu_criar_reflexao(iconeArr);
                break;
            case 5:
                system("cls");
                menu_rotacionar(iconeArr);
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
                system("cls");
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
                system("cls");
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

    int codigo;

    Icone *newIc;

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuReflexao();

        switch(opcao_menu) {
            case 1:
            case 2:
                imprimir_icones(iconeArr);
                printf("\nEntre com o index do ícone que deseja criar reflexão-> ");
                scanf("%d", &codigo);
                newIc = icone_reflexao(iconeArr, opcao_menu, codigo - 1);

                if(newIc == NULL){
                    system("cls");
                    imprime_erro("ÍCONE NÃO ENCONTRADO, VERIFIQUE O CÓDIGO E TENTE NOVAMENTE.");
                    break;
                }

                menu_salvar_outro(iconeArr, codigo - 1, newIc);
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

void menu_salvar_outro(IconeArr *iconeArr, int indice, Icone *newIc) {



    int opcao_menu = -1;

    while (opcao_menu < 0 || opcao_menu > 2) {

        system("cls");

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

void menu_rotacionar(IconeArr *iconeArr){

    int codigo;

    Icone *newIc;
    Icone *ic;

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuRotacionar();

        switch(opcao_menu) {
            case 1:
                system("cls");
                imprimir_icones(iconeArr);
                printf("\nEntre com o index do ícone que deseja rotacionar-> ");
                scanf("%d", &codigo);
                ic = buscar_icone(codigo - 1, iconeArr);

                if(ic == NULL){
                    system("cls");
                    imprime_erro("ÍCONE NÃO ENCONTRADO, VERIFIQUE O CÓDIGO E TENTE NOVAMENTE.");
                    break;
                }

                newIc = icone_rotaciona(ic);

                if(newIc == NULL){

                    system("cls");
                    //imprime_erro("ICONE NÃO ENCONTRADO, VERIFIQUE O CODIGO E TENTE NOVAMENTE.");
                    break;

                }

                menu_salvar_outro(iconeArr, codigo - 1, newIc);
                break;
            case 0:
                system("cls");
                break;
            default:
                imprime_erro("ESCOLHA INVALIDADE TENTE NOVAMENTE.");
                break;
        }
    }

}
