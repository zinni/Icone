#include "menu.h"

//INTERFACE DOS MENUS
int menuPrincipal() {
    int opcao;

    mudar_cor(1);
    printf("\n\n               GERADOR DE ICONES");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t 1. Criar");
    printf("\n\t 2. Mostrar Icones");
    printf("\n\t 3. Verificar simetria.");
    printf("\n\t 4. Reflexo no espelho.");
    printf("\n\t 5. Rotacionar.");
    printf("\n\t 6. Criar copia aumentada.");
    printf("\n\t 0. Sair do programa.");
    mudar_cor(3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuCriar(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int opcao;

    SetConsoleTextAttribute(hConsole, 1);
    printf("\n\n        ESCOLHA A NATUREZA DO SEU ICONE");
    printf("\n-------------------------------------------------");
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n\n\t 1. Icone aleatório.");
    printf("\n\t 2. Icone do usuário.");
    printf("\n\t 0. Voltar ao menu principal");
    SetConsoleTextAttribute(hConsole, 3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuCriarOutro(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int opcao;

    SetConsoleTextAttribute(hConsole, 11);
    printf("\n\n\t 1. Criar outro");
    printf("\n\t 2. Salvar");
    printf("\n\t 0. Voltar ao menu anterior.");
    SetConsoleTextAttribute(hConsole, 3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int menuReflexao(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int opcao;

    SetConsoleTextAttribute(hConsole, 1);
    printf("\n\n        ESCOLHA O TIPO DE REFLEXÃO");
    printf("\n-------------------------------------------------");
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n\n\t 1. Reflexão vertical.");
    printf("\n\t 2. Reflexão horizontal.");
    printf("\n\t 0. Voltar ao menu principal");
    SetConsoleTextAttribute(hConsole, 3);
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
                break;
            case 3:
                system("cls");
                verificar_simetria(iconeArr);
                break;
            case 4:
                system("cls");
                menu_criar_reflexao(iconeArr);
                break;
            case 0:
                printf("\n\n\nSaindo...\n\n");
                exit(0);
                break;
            default:
                imprime_erro("ESCOLHA INVALIDADE TENTE NOVAMENTE.");
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
                imprime_erro("ESCOLHA INVALIDADE TENTE NOVAMENTE.");
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
                imprime_erro("ESCOLHA INVALIDADE TENTE NOVAMENTE.");
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
                imprime_erro("ESCOLHA INVALIDADE TENTE NOVAMENTE.");
                break;
        }
    }
}

void menu_criar_reflexao(IconeArr *iconeArr) {
    system("cls");

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuReflexao();

        switch(opcao_menu) {
            case 1:
                icone_reflexao(iconeArr, 1);
                break;
            case 2:
                icone_reflexao(iconeArr, 2);
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
