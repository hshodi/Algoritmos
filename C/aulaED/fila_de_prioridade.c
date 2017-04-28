#include <stdio.h>

typedef struct fila_de_prioridade{

    struct fila_de_prioridade *anterior;
    struct fila_de_prioridade *proximo;
    int val;

}Fila;

void cria_fila(Fila *fila){

        fila = (Fila *)malloc(1 * sizeof(Fila));


}

int main(int argc, char *argv[]){



    return 0;
}