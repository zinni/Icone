#include "icone.h"
#include "entidade.h"


//retorna um ponteiro da struct de IconeArr e verifica se ha memoria suficiente não tendo programa fecha
IconeArr* inicArr(){

    IconeArr *iconeArr = (IconeArr*)malloc(sizeof(IconeArr));

    if(iconeArr == NULL){
        printf("ERRO!MEMORIA INSUFICIENTE, FECHE ALGUM PROCESSO E TENTE NOVAMENTE.\n\n");
        system("pause");
        exit(0);
    }

    iconeArr->arr = (Icone**)malloc(BLOCO * sizeof(Icone*));

    if(iconeArr->arr == NULL){

        printf("ERRO!MEMORIA INSUFICIENTE, FECHE ALGUM PROCESSO E TENTE NOVAMENTE.\n\n");
        system("pause");
        exit(0);
    }

    iconeArr->tam = 0;
    iconeArr->blocos = 1;

    return iconeArr;
}

//retorna o icone se encontrar um com o indice informado , se não ele retorna um NULL
Icone* buscar_icone(int indice, IconeArr *iconeArr){

    int tam = iconeArr->tam;

    //tem verificação que eu podia ter deixado somente na função que o chama mas prefiri por aqui tbm
    if(tam == 0 || (indice >= tam || indice < 0)){
        return NULL;
    }

    return iconeArr->arr[indice];

}

void substituir_icone(IconeArr *iconeArr, int indice, Icone *newIc){


    icone_libera_memoria(iconeArr->arr[indice]);

    iconeArr->arr[indice] = newIc;

    system("cls");
    imprime_sucesso("\tÍCONE SALVO COM SUCESSO!");
    aperte_enter();

}

Icone* criar_icone_randomico() {
    int tam;
    mudar_cor(1);
    printf("\n\n               ÍCONE ALEATÓRIO");
    printf("\n-------------------------------------------------\n");
    mudar_cor(11);
    printf("\nEntre com o tamanho do ícone: ");
    scanf("%d", &tam);
    Icone *ic;
    ic = icone_cria(tam);
    icone_preenche_aleatorio(ic);
    setlocale(LC_ALL, "C");
    printf("\n\n");
    icone_imprime(ic);
    setlocale(LC_ALL, "Portuguese");
    return ic;
}

Icone* criar_icone_especi(){

    int tam;

    mudar_cor(1);
    printf("\n\n              ICONE DO USUÁRIO");
    printf("\n-------------------------------------------------\n");
    mudar_cor(11);
    printf("\nEntre com o tamanho do ícone: ");
    scanf("%d", &tam);
    Icone *ic = icone_cria(tam);
    setlocale(LC_ALL, "C");

    for(int i = 0; i < tam; i++){

       for(int j = 0; j < tam ; j++){

            int v;

            do{
                printf("\nUse <1> para marcar e <0> para deixar vazio.");
                printf("\nAtribuir valor para a Linha [%d] e coluna [%d]: ", i+1,j+1);
                scanf("%d", &v);
            }while(v < 0 || v > 1);

            icone_atribui(ic , i, j, v);
            system("cls");

            printf("\n\n");
            printf("\t--------PREVIEW--------\n\n");

            icone_imprime(ic);
       }

    }
    setlocale(LC_ALL, "Portuguese");
    return ic;
}

void imprimir_icones(IconeArr *iconeArr){


    int tam = iconeArr->tam;

    if(iconeArr->tam == 0){
        imprime_erro("\tNÃO HA ICONES CADASTRADOS.");
        return;
    }

    mudar_cor(1);
    printf("\n\n              LISTA DE ÍCONES");
    printf("\n-------------------------------------------------\n\n");
    mudar_cor(11);

    for(int i = 0; i < tam; i++){

        printf("%d) " , i + 1);
        icone_imprime(iconeArr->arr[i]);
        printf("\n\n");
    }

}

void icone_salva(IconeArr *iconeArr, Icone *ic){

    if(ic == NULL){
        imprime_erro("\tERRO AO SALVAR O ICONE.");
        return;
    }else{

        int tam = iconeArr->tam;
        int blocos = iconeArr->blocos;

        if(tam ==  blocos * BLOCO){

            iconeArr->blocos++;
            iconeArr->arr = (Icone**)realloc(iconeArr->arr,blocos * BLOCO * sizeof(Icone*));

        }

        iconeArr->arr[tam] = ic;
        iconeArr->tam++;

        system("cls");
        imprime_sucesso("\tICONE SALVO COM SUCESSO!");
        aperte_enter();
    }
}

void icone_deletar(int indice, IconeArr *iconeArr){

    if(indice > (iconeArr->tam - 1) || indice <  0){

        imprime_erro("\tINDICE INVALIDO!");

    }else{
        icone_libera_memoria(iconeArr->arr[indice]);
        iconeArr->tam--;

        for(int i = indice; i < iconeArr->tam;i++){

            iconeArr->arr[i] = iconeArr->arr[i + 1];

        }
        //iconeArr->arr[indice] = iconeArr->arr[iconeArr->tam - 1];


        imprime_sucesso("\tÍCONE REMOVIDO COM SUCESSO!");
        aperte_enter();
    }
}

int icone_simetrico(Icone *ic){

    int simetricoV = icone_simetricoVertical(ic);
    int simetricoH = icone_simetricoHorizontal(ic);

    if(simetricoV == 1 || simetricoH == 1){

        return 1;

    }else{

        return 0;
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

Icone* reflexaoHorizontal(Icone* ic){

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

Icone* reflexaoVertical(Icone* ic){

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

Icone* icone_duplica(Icone *ic){

    int tam = icone_tam(ic) * 2;
    Icone *icon = icone_cria(tam);



    return icon;
}


Icone * icone_multiplicar_tamanho(Icone *ic, int fator) {
    int novo_tamanho = icone_tam(ic) * fator;
    int i, j, k, ultimo_indice;

    Icone *novo = icone_cria(novo_tamanho);
    for (i = icone_tam(ic)-1; i >= 0; i--) {
        for (j = icone_tam(ic) - 1; j >= 0; j--)
        {
            ultimo_indice = (j+1) * fator -1;
            for (k = 0; k < fator; k++)
            {
                if (ultimo_indice - k >= 0)
                {
                    int v = icone_acessa(ic ,i ,j);
                    icone_atribui(novo ,i ,ultimo_indice - k,v);
                }
            }
        }
        ultimo_indice = (i+1) * fator -1;
        for (k = 0; k < fator; k++) {
            //MARRETA MARRETA MARRETA!!!!!
            novo->pixels[ultimo_indice - k] = novo->pixels[i];
        }
    }

    return novo;
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
}

//Congela a tela esperando input do usuario.
void aperte_enter(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);
    printf("\nPressione ENTER para continuar.");
    getchar();
    getchar();
    system("cls");
}

//Facilita o uso de cores nos menus
void mudar_cor(int cor){

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
}

void cor_padrao(){

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

}
