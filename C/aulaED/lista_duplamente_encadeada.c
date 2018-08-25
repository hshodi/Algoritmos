#include <stdio.h>
#include "LDE.h"

int main(int arc, char **argv) {
    LDE_t *lista;
    init(&lista, 2);
    insere(lista, 5);
    insere(lista, 2);
    insere(lista, 0);
    insere(lista, 1);
    print_list(lista);
    destroy(lista);
    print_list(lista);
    return 0;
}