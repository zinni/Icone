#include "icone.h"

//FUNçÂO DE CRIAR ICONE COM TESTE DE VALIDADE DE MEMÓRIA
Icone * icone_cria(int tam) {
    int i;
    short int **tempPP;
    short int *tempP;
    Icone *ic = (Icone *)malloc(sizeof(Icone));

    if(ic == NULL){
        return NULL;
    }

    ic->tamanho = tam;
    tempPP = (short int **)malloc(sizeof(short int *) * tam);
    if(tempPP == NULL) {
        //printf("\nErro tentando criar icone.\n");
        free(ic);
        return NULL;
    }
    ic->pixels = tempPP;
    for (i = 0; i < tam; i++) {
        tempP = (short int *)malloc(tam * sizeof(short int));
        if(tempP == NULL) {
            //printf("\nErro tentando criar icone.\n");
            free(ic);
            free(ic->pixels);
            return NULL;
        }
        ic->pixels[i] = tempP;
    }
    return ic;
}

void icone_libera_memoria(Icone *ic){

    int tam = ic->tamanho;

    for(int i = 0; i < tam; i++){

        free(ic->pixels[i]);
    }

    free(ic->pixels);
    free(ic);

}

void icone_atribui(Icone *ic, int i, int j, int v){

    ic->pixels[i][j] = v;

}

int icone_acessa(Icone *ic, int i, int j){

    int v = ic->pixels[i][j];

    return v;
}

int icone_tam (Icone *ic){

    int tam = ic->tamanho;

    return tam;
}


void icone_preenche_aleatorio(Icone *ic){

    srand(time(NULL));
    int tam = ic->tamanho;

    for(int i = 0; i < tam ; i++){

        for(int j = 0; j < tam; j++){
            int v = rand() % 2;
            icone_atribui(ic, i, j, v);
        }
    }


}

void icone_imprime(Icone *ic){

    int tam = ic->tamanho;

    setlocale(LC_ALL, "C");

    for(int i = 0; i < tam ; i++){

        printf("\t\t|");

        for(int j = 0; j < tam; j++){

            int v = icone_acessa(ic, i, j);

            if(v == 1){

              printf("%c%c", 219, 219);

            }else{

              printf("  ");
            }
        }
        printf("|\n");
    }

    setlocale(LC_ALL, "Portuguese");

}

Icone* icone_copia(Icone *ic){

    Icone *icon = icone_cria(ic->tamanho);

    if(icon == NULL){
        return NULL;
    }

    for(int i = 0;i < icon->tamanho; i++){
        for(int j = 0;j < icon->tamanho; j++){

            int v = icone_acessa(ic ,i ,j);
            icone_atribui(icon ,i ,j ,v);

        }
    }

    return icon;
}

Icone* icone_rotaciona(Icone *ic1){

    int tam = ic1->tamanho;

    Icone *ic = icone_cria(tam);

    if(ic == NULL){
        return NULL;
    }

    for(int i = 0;i < tam; i++){
        for(int j = 0;j < tam; j++){

            ic->pixels[j][(tam - 1) - i] = ic1->pixels[i][j];

        }
    }

    return ic;

}
