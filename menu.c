#include "icone.h"
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
    printf("\n\t 2. Mostras Icone");
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
    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menu();
        switch(opcao_menu) {
            case 1:
                main_menu1();
            case 2:
                printf(setlocale( LC_CTYPE, NULL ));
                break;
            case 0:
                printf("\n\n\nSaindo...\n\n");
                exit(0);
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

int main_menu1(void) {
    system("cls");
    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menu1();
        switch(opcao_menu) {
            case 1:
                main_submenu1();
            case 2:
                break;
            case 0:
                main_menu();
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

int main_submenu1(void) {
    system("cls");
    Icone *ic;
    criar_icone_randomico(ic);
    //ic = icone_cria(16);
    //icone_preenche_aleatorio(ic);
    //icone_imprime(ic);
    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = submenu1();
        switch(opcao_menu) {
            case 1:
                system("cls");
                criar_icone_randomico(ic);
                //icone_imprime(ic);
                break;
            case 2:
                printf("%d", icone_tam(ic));
                break;
            case 0:
                main_menu1();
                break;
            default:
                imprime_erro("Escolha inválida tente novamente");
                break;
        }
    }
    return 1;
}
