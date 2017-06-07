#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 101
#define generate_hash(key) key % TABLE_SIZE

typedef struct item{

    char* nome;
    int id;

}Item;

typedef struct hash_table{

    int qtd_itens;
    Item **itens;

}Hash_t;

Hash_t* init_hash_table(){

    Hash_t* aux = (Hash_t *)malloc(sizeof(Hash_t));
    if(aux != NULL){
        int i = 0;
        aux->qtd_itens = 0;
        aux->itens = (Item **)malloc(TABLE_SIZE * sizeof(Item *));
        
    s1:if(i < TABLE_SIZE){
            aux->itens[i] = NULL;
            i++;
            goto s1;
        }

    }
    return aux;

}

void free_hash_t(Hash_t* hash){
    if(hash != NULL){
        int i = 0;
     s1:if(i < TABLE_SIZE){
            // if(hash->itens[i] != NULL)
                free(hash->itens[i]);
            i++;
            goto s1;
        }
        free(hash->itens);
        free(hash);
    }
}

Item* busca(Hash_t* table, int id){

    int hash = generate_hash(id);
    if(table->itens[hash] != NULL){
        printf("Nome: %s\n", table->itens[hash]->nome);
        printf("ID: %d\n", table->itens[hash]->id);
        return table->itens[hash];
    }
    printf("NAO FOI ENCONTRADO VALORES NA HASH: %d\n", hash);
    return NULL;

}

int remover(Hash_t* table, int id){
    int hash = generate_hash(id);
    if(table->itens[hash] != NULL){
        free(table->itens[hash]);
        table->itens[hash] = NULL;
        return 1;
    }
    printf("ELEMENTO NAO ENCONTRADO\n");
    return 0;
}

int insert(Hash_t* table, int id, char *nome){
    int hash = generate_hash(id);
    Item* aux = (Item *)malloc(sizeof(Item));
    if(aux != NULL && table != NULL){
        aux->nome = nome;
        aux->id = id;
	    table->itens[hash] = aux;
	    return 1;
    }
    return 0;
}

int main(int argc, char **argv[]){

    Hash_t* hash = init_hash_table();
    insert(hash, 1348, "Henrique");
    insert(hash, 1548, "Shodi");
    busca(hash, 1548);
    busca(hash, 1548);
    remover(hash, 1548);
    remover(hash, 1111);
    busca(hash, 1347);
    busca(hash, 1348);
    free_hash_t(hash);
}
