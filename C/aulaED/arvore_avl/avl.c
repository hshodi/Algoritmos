#include <stdio.h>
#include <stdlib.h>

/*
- Verificação (dada uma árvore, decidir se a árvore é ou não AVL).
*/

typedef struct arvore_avl{
    int value;
    int alt;
    struct arvore_avl *esquerda, *direita;
}No;

int alt(No* no){
    if(no == NULL)
        return -1;
    else
        return no->alt;
}

int balanceamento(No* no){
	int diff = alt(no->esquerda) - alt(no->direita);
	if(diff < 0) diff *= -1;
	return diff;
}

int is_avl(No** raiz){
	if(*raiz != NULL){
		if(balanceamento(*raiz) > 1) return 0;
		is_avl(&(*raiz)->esquerda);
		is_avl(&(*raiz)->direita);
	}
	return 1;
}

int grater(int x, int y){
    return x >= y ? x : y;
}

void RDE(No** raiz){

	No* no;
	no = (*raiz)->esquerda;
	(*raiz)->esquerda = no->direita;
	no->direita = *raiz;
	(*raiz)->alt = grater(alt((*raiz)->esquerda), alt((*raiz)->direita)) + 1;
	no->alt = grater(alt(no->esquerda), ((*raiz)->alt) + 1);

	*raiz = no;

}

void RDD(No** raiz){

	No* no;
	no = (*raiz)->direita;
	(*raiz)->direita = no->esquerda;
	no->esquerda = (*raiz);
	(*raiz)->alt = grater(alt((*raiz)->esquerda), alt((*raiz)->direita)) + 1;

	no->alt = grater(alt(no->direita), (*raiz)->alt + 1);
	(*raiz) = no;

}

void RotacaoLR(No** raiz){
	RDD(&(*raiz)->esquerda);
	RDE(raiz);
}

void RotacaoRL(No** raiz){
	RDE(&(*raiz)->direita);
	RDD(raiz);
}

void busca(No **raiz, int val){

    if(*raiz == NULL){
        printf("VALOR %d NAO ESTA NA ARVORE\n", val);
        return;
    }
    if(val > (*raiz)->value){
        busca(&(*raiz)->direita, val);
        return;
    }
    if(val < (*raiz)->value){
        busca(&(*raiz)->esquerda, val);
        return;
    }
    if(val == (*raiz)->value){
        printf("VALOR %d ENCONTRADO\n", (*raiz)->value);
        return; 
    }
}

int insere(No **raiz, int value){
	int res;
	if(*raiz == NULL){
		No *aux;
		aux = (No *)malloc(sizeof(No));
		if(aux == NULL) return 0;
		aux->value = value;
		aux->alt = 0;
		aux->esquerda = NULL;
		aux->direita = NULL;
		*raiz = aux;
		printf("VALOR %d INSERIDO NA ARVORE\n", aux->value);
		return 1;
	}
	No *current = *raiz;
	if(value < current->value){
		if((res=insere(&current->esquerda, value)) == 1){
			if(balanceamento(current) >= 2){
				if(value < (*raiz)->esquerda->value){
					RDE(raiz);
				}else{
					RotacaoLR(raiz);
				}
			}
		}
	}else{
		if(value > current->value){
			if((res=insere(&current->direita, value) == 1)){
				if(balanceamento(current) >= 2){
					if((*raiz)->direita->value < value){
						RDD(raiz);
					}else{
						RotacaoRL(raiz);
					}
				}
			}
		}else{
			return 0;
		}
	}
	current->alt = grater(alt(current->esquerda), alt(current->direita)) + 1;
	return res;
}

No* findMinor(No* current){
	No* no1 = current;
	No* no2 = current->esquerda;
	if(no2 != NULL){
		no1 = no2;
		no2 = no2->esquerda;
	}
	return no1;
}

int remover(No** raiz, int value){
	if(*raiz == NULL){
		printf("O VALOR %d NAO ESTA NA ARVORE\n", value);
		return 0;
	}
	int res;
	if(value < (*raiz)->value){
		if((res=remover(&(*raiz)->esquerda, value)) == 1){
			if(balanceamento(*raiz) >= 2){
				if(alt((*raiz)->direita->esquerda) <= alt((*raiz)->direita->direita)){
					RDD(raiz);
				}
				else{
					RotacaoRL(raiz);
				}
			}
		}
	}
	if(value > (*raiz)->value){
		if((res=remover(&(*raiz)->direita, value)) == 1){
			if(balanceamento(*raiz) >= 2){
				if(alt((*raiz)->esquerda->direita) <= alt((*raiz)->esquerda->esquerda)){
					RDE(raiz);
				}else{
					RotacaoLR(raiz);
				}
			}
		}
	}
	if((*raiz)->value == value){
		if(((*raiz)->esquerda == NULL || (*raiz)->direita == NULL)){
			No *to_remover = (*raiz);
			if((*raiz)->esquerda != NULL){
				*raiz = (*raiz)->esquerda;
			}else{
				*raiz = (*raiz)->direita;
			}
			printf("REMOVIDO O VALOR %d\n", to_remover->value);
			free(to_remover);
		}else{
			No *aux = findMinor((*raiz)->direita);
			(*raiz)->value = aux->value;
			remover(&(*raiz)->direita, (*raiz)->value);
			if(balanceamento(*raiz) >= 2){
				if(alt((*raiz)->esquerda->direita) <= alt((*raiz)->esquerda->esquerda)){
					RDE(raiz);
				}else{
					RotacaoLR(raiz);
				}
			}
		return 1;
		}
	}
	return res;
}

int main(){
    No* avl = NULL;

	insere(&avl, 5);
	insere(&avl, 6);
	insere(&avl, 7);
	insere(&avl, 10);
	insere(&avl, 9);
	insere(&avl, 2);
	remover(&avl, 1);
	busca(&avl, 32);
	busca(&avl, 10);
	remover(&avl, 2);
	printf("A ARVORE %s AVL\n", is_avl(&avl) ? "É" : "NAO É");
}
