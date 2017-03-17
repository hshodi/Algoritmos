#include <stdio.h>
#include <stdlib.h>

typedef struct arvorebinaria{

    int value;
    struct arvorebinaria* direita;
    struct arvorebinaria* esquerda;

}Arvore;

void insere(Arvore **x, int val){

    if(*x == NULL){
        Arvore *aux = (Arvore *)malloc(sizeof(Arvore));
        aux->esquerda = aux->direita = NULL;
        aux->value = val;
        *x = aux;
        printf("Elemento %d inserido com sucesso\n", val);
        return;
    }
    if((*x)->value > val){
        insere(&(*x)->esquerda, val);
        return;
    }
    if((*x)->value < val){
        insere(&(*x)->direita, val);
        return;
    }
    printf("O elemento %d ja existe na arvore\n", val);
}

void insere_iterative(Arvore **a, int val){

    Arvore *first_position = *a;

s2: if(*a != NULL){
        if(val > (*a)->value){
            *a = (*a)->direita;
            goto s2;
        }
        if(val < (*a)->value){
            *a = (*a)->esquerda;
            goto s2;
        }
        if(val == (*a)->value){
            printf("O elemento %d ja existe na arvore\n", val);
            return;
        }
    }
    Arvore *aux = (Arvore *)malloc(sizeof(Arvore));
    aux->esquerda = aux->direita = NULL;
    aux->value = val;
    *a = aux;
    printf("Elemento %d inserido com sucesso\n", (*a)->value);
    *a = first_position;
    return;
}
void find_value(Arvore **a, int val){

    if(*a == NULL){
        printf("VALOR %d NAO ESTA NA ARVORE\n", (*a)->value);
        return;
    }
    if(val > (*a)->value){
        find_value(&(*a)->direita, val);
        return;
    }
    if(val < (*a)->value){
        find_value(&(*a)->esquerda, val);
        return;
    }
    if(val == (*a)->value){
        printf("VALOR %d ENCONTRADO\n", (*a)->value);
        return; 
    }
}

int find_value_iterative(Arvore **a, int val){

    s1: if(*a != NULL){
        printf("VALUE: %d\n", (*a)->value);
        if((*a)->value > val){
            *a = (*a)->esquerda;
            goto s1;
        }
        if((*a)->value < val){
            *a = (*a)->direita;
            goto s1;
        }
        if((*a)->value == val){
            printf("VALOR %d ENCONTRADO\n", (*a)->value);
            return 1;
        }
    }       
    printf("VALOR %d NAO ESTA NA ARVORE\n", (*a)->value);
    return 0;
}

void pre_order(Arvore **a){

    if(*a != NULL){
        printf("VALUE: %d\n", (*a)->value);
        pre_order(&(*a)->esquerda);
        pre_order(&(*a)->direita);
    }

}

void in_order(Arvore **a){

    if(*a != NULL){
        in_order(&(*a)->esquerda);
        printf("VALUE: %d\n", (*a)->value);
        in_order(&(*a)->direita);
    }

}

void post_order(Arvore **a){

    if(*a != NULL){
        post_order(&(*a)->esquerda);
        post_order(&(*a)->direita);
        printf("VALUE: %d\n", (*a)->value);
    }

}

int main(int argc, char* argv[]){

    Arvore *a = NULL;
    insere(&a, 5);
    insere_iterative(&a, 5);
    insere(&a, 1);
    insere_iterative(&a, 10);
    in_order(&a);
    insere(&a, 0);
    insere(&a, 22);
    find_value(&a, 5);
    find_value_iterative(&a, 21);
    free(a);


    return 0;
}