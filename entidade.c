#include "icone.h"
#include "entidade.h"

typedef struct _icone_arr {
    int qtd;
    Icone *arr;
} IconeArr;

Icone * criar_icone_randomico(Icone * ic) {
    int tam;
    printf("\nEntre com o tamanho do ícone: ");
    scanf("%d", &tam);
    ic = icone_cria(tam);
    icone_preenche_aleatorio(ic);
    setlocale(LC_ALL, "C");
    printf("\n\n");
    icone_imprime(ic);
    setlocale(LC_ALL, "Portuguese");
    return ic;
}

void icone_salva(IconeArr* icones){
    int *temp;
    Icone icone;
    if (icones->qtd > 0){
        temp = (Icone *) realloc((icones->arr), sizeof(Icone) * (icones->qtd + 1));
    } else {
        temp = (Icone *) malloc(sizeof(Icone) * (icones->qtd + 1));
    }
    if(temp != NULL) {
        icones->arr = temp;
        icones->qtd++;
    } else {
        printf("Erro tentando realocar memoria para o novo icone.");
    }
    icones->arr[icones->qtd - 1] = icone;
}

void icone_simetrico(Icone *ic){

    int simetricoV = icone_simetricoVertical(ic);
    int simetricoH = icone_simetricoHorizontal(ic);

    if(simetricoV == 1){
        printf("Icone simetrico(vertical)");
    }else if(simetricoH == 1){
        printf("Icone simetrico(horizontal)");
    }else{
        printf("Icone assimetrico");
    }
}


int icone_simetricoVertical(Icone* ic){

    int tam = icone_tam(ic);

    for(int i = 0; i < tam; i++){
        printf("\n");
        for(int j = 0; j < (tam / 2); j++){

            int vLadoA = icone_acessa(ic, i, j);
            int vLadoB = icone_acessa(ic, i, (tam - 1) - j);

            if(vLadoA != vLadoB){

                return 0;
            }
        }
    }
    return 1;
}

int icone_simetricoHorizontal(Icone* ic){

    int tam = icone_tam(ic);

    for(int i = 0; i < (tam / 2); i++){
        printf("\n");
        for(int j = 0; j < tam; j++){

            int vLadoA = icone_acessa(ic, i, j);
            int vLadoB = icone_acessa(ic, (tam - 1) - i, j);

            if(vLadoA != vLadoB){

                return 0;
            }
        }
    }

    return 1;

}

Icone* reflexaoVertical(Icone* ic){

    int tam = icone_tam(ic);
    Icone *icon = icone_cria(tam);

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
           int v = icone_acessa(ic ,i ,j);
           icone_atribui(icon ,(tam - 1) - i ,j ,v);

        }
    }
    return icon;
}

Icone* reflexaoHorizontal(Icone* ic){

    int tam = icone_tam(ic);
    Icone *icon = icone_cria(tam);

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){

           int v = icone_acessa(ic ,i ,j);

           icone_atribui(icon ,i ,(tam - 1) - j ,v);

        }
    }
    return icon;
}


Icone* icone_duplicado(Icone *ic){

    int tam = icone_tam(ic) * 2;
    Icone *icon = icone_cria(tam);



    return icon;
}

//Essas duas funções dão cor padrão as mensagens de sucesso ou erro do programa.
void imprime_erro(char erro[MSG_SIZE]) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    printf("\n%s\n", erro);
}

void imprime_sucesso(char sucesso[MSG_SIZE]) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    printf("\n%s\n", sucesso);
    SetConsoleTextAttribute(hConsole, 7);
}

//Congela a tela esperando input do usuario.
void aperte_enter(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);
    printf("\nPressione ENTER para continuar.");
    getchar();
    getchar();
}
