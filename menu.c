#include "menu.h"

int menu() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;

    SetConsoleTextAttribute(hConsole, 1);
    printf("\n\n               GERADOR DE ICONES");
    printf("\n-------------------------------------------------");
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n\n\t 1. Criar");
    printf("\n\t 2. Mostrar Icones");
    printf("\n\t 3. Verificar simetria.");
    printf("\n\t 4. Reflexo no espelho.");
    printf("\n\t 5. Rotacionar.");
    printf("\n\t 6. Criar copia aumentada.");
    printf("\n\t 0. Sair do programa.");
    SetConsoleTextAttribute(hConsole, 3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int main_menu(void) {
    system("cls");

    //Iniciando IconeArr struct que armazena o array de icones
    IconeArr *iconeArr = inicArr();

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menu();
        switch(opcao_menu) {
            case 1:
                main_menu1(iconeArr);
                break;
            case 2:
                //printf(setlocale( LC_CTYPE, NULL ));
                system("cls");
                imprimir_icones(iconeArr);
                break;
            case 3:
                //printf(setlocale( LC_CTYPE, NULL ));
                system("cls");
                verificar_simetria(iconeArr);
                break;
            case 0:
                printf("\n\n\nSaindo...\n\n");
                exit(0);
                break;
            default:
                imprime_erro("Escolha inválida tente novamente");
                break;
        }
    }
    return 0;
}

int menu1(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int opcao;

    SetConsoleTextAttribute(hConsole, 1);
    printf("\n\n        ESCOLHA A NATUREZA DO SEU ICONE");
    printf("\n-------------------------------------------------");
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n\n\t 1. Icone Randomizado");
    printf("\n\t 2. Icone Manual - Vazio");
    printf("\n\t 0. Voltar ao menu principal");
    SetConsoleTextAttribute(hConsole, 3);
    printf("\n\n Entre com a opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int main_menu1(IconeArr *iconeArr) {
    system("cls");
    Icone *ic;

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menu1();
        switch(opcao_menu) {
            case 1:
                main_submenu1(iconeArr);
                break;
            case 2:
                ic = criar_icone_especi();
                break;
            case 0:
                system("cls");
                break;
            default:
                imprime_erro("Escolha inválida tente novamente");
                break;
        }
    }
    return 1;
}

int submenu1(){
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

int main_submenu1(IconeArr *iconeArr) {
    system("cls");

    Icone *ic;
    ic = criar_icone_randomico();


    int opcao_menu = -1;
    while (opcao_menu != 0 && opcao_menu != 2) {
        opcao_menu = submenu1();
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
                imprime_erro("Escolha inválida tente novamente");
                break;
        }
    }
    return 1;
}
