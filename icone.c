#include "icone.h"

Icone* icone_cria(int tam){


    Icone *ic = (Icone*)malloc(sizeof(Icone));

    ic->tamanho = tam;
    ic->pixels = (short int **) malloc(tam * sizeof(short int*));

    for(int i = 0; i < tam; i++){

       ic->pixels[i] = (short int *) malloc(tam * sizeof(short int));

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

}

Icone* icone_copia(Icone *ic){

    Icone *icon = icone_cria(ic->tamanho);

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

    for(int i = 0;i < tam; i++){
        for(int j = 0;j < tam; j++){

            ic->pixels[j][(tam - 1) - i] = ic1->pixels[i][j];

        }
    }

    return ic;

}
