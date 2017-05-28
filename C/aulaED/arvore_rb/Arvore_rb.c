#include <stdio.h>
#include <stdlib.h>


#define BLACK 0
#define RED 1


typedef struct no_arvore_rubronegra{

    int value;
    unsigned int color: 1;
    struct no_arvore_rubronegra *esquerda, *direita, *pai;

}No;

typedef struct arvore{

    int (*inserir) (No**, int);
    int (*busca) (No *, int);
    int (*remover) (No**, int);
    No *raiz;

}Arvore;

void change_color(No *x){
    x->color = !x->color;
    if(x->esquerda != NULL)
        x->esquerda->color = !x->esquerda->color;
    if(x->direita != NULL)
        x->direita->color = !x->direita->color;
}

int color(No* x){
    if(x == NULL)
        return BLACK;
    else
        return x->color;
}

No* left_rotation(No* x){
    //child é filho direito
    No* child = x->direita;
    x->direita = child->esquerda;
    child->esquerda = x;
    child->color = x->color;
    x->color = RED;
    return child;
}

No* right_rotation(No* x){
    //child é filho esquerdo
    No* child = x->esquerda;
    x->esquerda = child->direita;
    child->direita = x;
    child->color = x->color;
    x->color = RED;
    return child;
}

No* esqRED(No *x){
    change_color(x);
    if(color(x->direita->esquerda) == RED){
        x->direita = right_rotation(x->direita);
        x = left_rotation(x);
        change_color(x);
    }
    return x;
}

No* dirRED(No* x){
    change_color(x);
    if(color(x->esquerda->esquerda) == RED){
        x = right_rotation(x);
        change_color(x);
    }
    return x;
}

No* balance(No* x){
    if(color(x->direita) == RED)
        x = left_rotation(x);
    if(x->esquerda != NULL && color(x->direita) == RED && color(x->esquerda->esquerda) == RED)
        x = right_rotation(x);
    if(color(x->esquerda) == RED && color(x->direita) == RED)
        change_color(x);
    return x;
}

No* insere_no(No* x, int value, int *resp){
    if(x == NULL){
        No* aux = (No *)malloc(sizeof(No));
        if(aux == NULL){
            *resp = 0;
            return NULL;
        }
        aux->value = value;
        aux->color = RED;
        aux->direita = aux->esquerda = NULL;
        *resp = 1;
        return aux;
    }
    if(x->value == value)
        *resp = 0;
    else{
        if(x->value > value)
            x->esquerda = insere_no(x->esquerda, value, resp);
        else
            x->direita = insere_no(x->direita, value, resp);
    }
    if(color(x->direita) == RED && color(x->esquerda) == BLACK)
        x = left_rotation(x);
    if(color(x->esquerda) == RED && color(x->esquerda->esquerda) == RED)
        x = right_rotation(x);
    if(color(x->esquerda) == RED && color(x->direita) == RED)
        change_color(x);

    return x;
}

No* removerMenor(No* x){
	if(x->esquerda == NULL){
		free(x);
		return NULL;
	}
	if(color(x->esquerda) == BLACK && color(x->esquerda->esquerda) == BLACK)
		x = esqRED(x);

	x->esquerda = removerMenor(x->esquerda);
	return balance(x);
}

No* procuraMenor(No* current){
	No* no1 = current;
	No* no2 = current->esquerda;
s1:	if(no2 != NULL){
		no1 = no2;
		no2 = no2->esquerda;
		goto s1;
	}
	return no1;
}

No* remove_NO(No* x, int value){
	if(value < x->value){
		if(color(x->esquerda) == BLACK && color(x->esquerda->esquerda) == BLACK)
			x = esqRED(x);
		x->esquerda = remove_NO(x->esquerda, value);
	} else {
		if(color(x->esquerda) == RED)
			x = right_rotation(x);
		if(value == x->value && (x->direita == NULL)){
			free(x);
			return NULL;
		}
		if(color(x->direita) == BLACK && color(x->direita->esquerda) == BLACK)
			x = dirRED(x);
		if(value == x->value){
			No* aux = procuraMenor(x->direita);
			x->value = aux->value;
			x->direita = removerMenor(x->direita);
		}else
			x->direita = remove_NO(x->direita, value);
	}
	return balance(x);
}

int busca(No *x, int value){
	if(x != NULL){
		if(value == x->value){
			printf("VALOR %d ENCONTRADO\n", x->value);
			return 1;
		}
		if(value > x->value)
			busca(x->direita, value);
		else if(value < x->value)
			busca(x->esquerda, value);
	}
	printf("VALOR NAO ENCONTRADO\n");
	return 0;
}

int remove_arvore(No** raiz, int value){
    if(busca(*raiz, value)){
        No* x = *raiz;
        *raiz = remove_NO(x, value);
        if(*raiz != NULL)
            (*raiz)->color = BLACK;
	    return 1;
    }else{
	    return 0;
    }
}

int insere_arvore(No** raiz, int value){
    int resp;
    *raiz = insere_no(*raiz, value, &resp);
    if(*raiz != NULL)
        (*raiz)->color = BLACK;
    return resp;
}

Arvore *init_arvore(){
    Arvore *aux = (Arvore *)malloc(sizeof(Arvore));
    aux->remover = &remove_arvore;
    aux->inserir = &insere_arvore;
    aux->busca = &busca;
    aux->raiz = NULL;
    return aux;
}

int main(int argc, char *argv[]){
    Arvore *a = init_arvore();
    a->inserir(&(a->raiz), 5);
    a->inserir(&(a->raiz), 6);
    a->inserir(&(a->raiz), 4);
    a->inserir(&(a->raiz), 2);

    a->busca(a->raiz, 1);
    a->busca(a->raiz, 5);


    a->remover(&(a->raiz), 6);

    return 0;
}
