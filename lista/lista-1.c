#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int dado;
    struct lista* prox;
} Lista;
typedef Lista* pLista;

pLista* criar_lista(){
    pLista* li = (pLista*) malloc(sizeof(pLista));
    if(li != NULL){
        *li = NULL;

    }
    return li; 
}

int incerir_inicio(pLista* li, int dado){
    if(li == NULL){
        return 0;
    }
    pLista no = (pLista) malloc(sizeof(Lista));
    if(no == NULL){
        return 0;
    }
    no->dado = dado;
    no->prox = (*li);
    *li = no;
    return 1;
}

int tamanho_lista(pLista* li){
    if(li == NULL){
        return -1;
    }
    int count = 0;
    pLista no = *li;
    while(no != NULL){
        count++;
        no = no->prox;

    }
    return count;

}

int remover_lista(pLista* li){
    if(li == NULL|| *li == NULL){
        return 0;
    }
    pLista no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int inserir_final(pLista* li, int dado){
    if(li == NULL){
        return 0;
    }
    pLista no = (pLista) malloc(sizeof(Lista));
    if(no == NULL){
        return 0;
    }
    no->dado = dado;
    no->prox = NULL;
    if(*li == NULL){
        *li = no;
    } else {
        pLista aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

void liberar_lista(pLista* li){
    if(li != NULL){
        pLista *no;
        while((*li) != NULL){
            no = *li;
            *li = no->prox;
            free(no);
        }
        free(li);
    }
}

//fazer as funçoes de romever final, lista vazia e buscar lista

//cria o int main, insira tres elementos e imprima o tamamnho

int main(){
    pLista* li = criar_lista();
    incerir_inicio(li, 10);
    incerir_inicio(li, 20);
    incerir_inicio(li, 30);
    printf("tamanho da lista: %d\n", tamanho_lista(li));
    return 0;
}
