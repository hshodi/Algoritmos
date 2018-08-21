#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_DUPLAMENTE_ENCADEADA
    #define LISTA_DUPLAMENTE_ENCADEADA
    typedef struct LDE {
        int value;
        struct LDE *next;
        struct LDE *prev;
    } LDE_t;

    void init(LDE_t **lista, int valor) {
        (*lista) = (LDE_t *)malloc(1 * sizeof(LDE_t));
        (*lista)->value = valor;
        (*lista)->next = NULL;
        (*lista)->prev = NULL;
    }

    void insere(LDE_t *lista, int value) {
        if (lista->next) insere(lista->next, value);
        // final da lista
        else {
            lista->next = (LDE_t *)malloc(sizeof(LDE_t));
            lista->next->value = value;
            lista->next->prev = lista;
            lista->next->next = NULL;
        }
    }

    void print_list(LDE_t *lista) {
        if (lista) {
            printf("valor: %d\n", lista->value);
            print_list(lista->next);
        }
    }

    void remove_last(LDE_t *lista) {
        if (lista->next) remove_last(lista->next);
        else {
            LDE_t *rem;
            rem = lista;
            if (lista->prev != NULL)
                lista->prev->next = lista->next;
            free(rem);
        } 
    }

    void destroy(LDE_t *lista) {
        LDE_t *aux;
        for (aux = lista; aux->next != NULL;) {
            remove_last(lista);   
        }
        free(lista);
    }
#endif