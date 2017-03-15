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

int find_value(Arvore **a, int val){

    if(*a == NULL){
        printf("VALOR NAO ESTA NA ARVORE\n");
        return 0;
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
        printf("VALOR ENCONTRADO\n");
        return 1; 
    }
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
    insere(&a, 5);
    insere(&a, 10);
    insere(&a, 1);
    insere(&a, 0);
    insere(&a, 22);
    find_value(&a, 31);
    free(a);


    return 0;
}