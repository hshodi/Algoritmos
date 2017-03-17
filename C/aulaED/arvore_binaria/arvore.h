// ESTRUTURA BASICA DE UMA ARVORE BINARIA
typedef struct arvorebinaria{

    int value;
    struct arvorebinaria* direita;
    struct arvorebinaria* esquerda;

}Arvore;

// FUNCAO PARA INSERIR UM VALOR NA ARVORE DE FORMA RECURSIVA
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

// FUNCAO PARA INSERIR UM VALOR NA ARVORE DE FORMA ITERATIVA
void insere_iterative(Arvore **a, int val){

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
    return;
}

// FUNCAO PARA PROCURAR UM VALOR NA ARVORE DE FORMA RECURSIVA
void find_value(Arvore **a, int val){

    if(*a == NULL){
        printf("VALOR %d NAO ESTA NA ARVORE\n", val);
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

// FUNCAO PARA PROCURAR UM VALOR NA ARVORE DE FORMA ITERATIVA
int find_value_iterative(Arvore **a, int val){
    Arvore *first_position = *a;
s1: if(*a != NULL){
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
            *a = first_position;
            return 1;
        }
    }
    printf("VALOR %d NAO ESTA NA ARVORE\n", val);
    *a = first_position;
    return 0;
}

// FUNCAO PARA PRINTAR A ARVORE COM O ALGORITMO PRE-ORDEM
void pre_order(Arvore **a){

    if(*a != NULL){
        printf("VALUE: %d\n", (*a)->value);
        pre_order(&(*a)->esquerda);
        pre_order(&(*a)->direita);
    }

}

// FUNCAO PARA PRINTAR A ARVORE COM O ALGORITMO IN-ORDEM
void in_order(Arvore **a){

    if(*a != NULL){
        in_order(&(*a)->esquerda);
        printf("VALUE: %d\n", (*a)->value);
        in_order(&(*a)->direita);
    }

}

// FUNCAO PARA PRINTAR A ARVORE COM O ALGORITMO POS-ORDEM
void post_order(Arvore **a){

    if(*a != NULL){
        post_order(&(*a)->esquerda);
        post_order(&(*a)->direita);
        printf("VALUE: %d\n", (*a)->value);
    }

}

Arvore *twoChildren(Arvore *sub_arvore){
    if(sub_arvore == NULL) return sub_arvore;
    else if(sub_arvore->esquerda == NULL) return sub_arvore;
    else return twoChildren(sub_arvore->esquerda);
}

// FUNCAO PARA REMOVER UM NÓ DA ARVORE
void remove_node(Arvore **a, int value){
    if((*a)->value > value) remove_node(&(*a)->esquerda, value);
    else if((*a)->value < value) remove_node(&(*a)->direita, value);
    else if((*a)->esquerda != NULL && (*a)->direita != NULL){
        Arvore *aux = NULL;
        aux = twoChildren((*a)->direita);
        (*a)->value = aux->value;
        remove_node(&(*a)->direita, (*a)->value);
    }
    else{
        Arvore *aux = *a;
        if((*a)->esquerda == NULL) *a = (*a)->direita;
        else *a = (*a)->esquerda;
        free(aux);
    }
}
/*
    >>
    >>
    >>      EXEMPLO DE FUNCAO MAIN
    >>
    >>
    apenas retire o comentario e adicione as bibliotecas stdlib e stdio

int main(int argc, char* argv[]){

    Arvore *a = NULL;
    insere(&a, 5);
    insere_iterative(&a, 5);
    find_value_iterative(&a, 21);
    find_value(&a, 5);
    insere(&a, 1);
    insere_iterative(&a, 10);
    in_order(&a);
    insere(&a, 0);
    remove_node(&a, 10);
    insere(&a, 22);
    free(a);


    return 0;
}
*/
