#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int dado;
    struct lista* prox;
    struct lista* ant;
} lis;

struct descritor{
    lis* inicio;
    lis* fim;
    int tamanho;
};

typedef struct descritor Lista;

Lista* criar_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->fim = NULL;
        li->tamanho = 0;
    }
    return li;
}

int inserir_inicio(Lista* li, int dado){
    if(li == NULL){
        return 0;
    }
    lis* novo = (lis*) malloc(sizeof(lis));
    if(novo == NULL){
        return 0;
    }
    novo->dado = dado;
    novo->ant = NULL;
    if(li->inicio != NULL){
        li->inicio->ant = novo;
    }else{
        li->fim = novo;
    }
    novo->prox = li->inicio;
    li->inicio = novo;
    li->tamanho++;
    return 1;
} 
int tamanho_lista(Lista* li){
    if(li == NULL){
        return -1;
    }
    return li->tamanho;
}

int remover_inicio(Lista* li){
    if(li == NULL || li->inicio == NULL){
        return 0;
    }
    lis* aux = li->inicio;
    li->inicio = aux->prox;
    if(li->inicio != NULL){
        li->inicio->ant = NULL;
    }else{
        li->fim = NULL;
    }
    free(aux);
    li->tamanho--;
    return 1;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    if(li->tamanho == 0)
        return 1;
    return 0;
}

int buscar_lista(Lista* li, int valor){
    if(li == NULL)
        return 0;
    lis* aux = li->inicio;
    while(aux != NULL){
        if(aux->dado == valor)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

//colocar as funçoes de lista_vazia, buscar_lista(lista, valor)e insirir tres elementos no final)

int inserir_fim(Lista* li, int dado){
    if(li == NULL){
        return 0;
    }
    lis* novo = (lis*) malloc(sizeof(lis));
    if(novo == NULL){
        return 0;
    }
    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = li->fim;
    if(li->fim != NULL){
        li->fim->prox = novo;
    }else{
        li->inicio = novo;
    }
    li->fim = novo;
    li->tamanho++;
    return 1;
}

void imprimir_lista(Lista* li){
    if(li == NULL || li->inicio == NULL){
        printf("Lista vazia\n");
        return;
    }
    lis* aux = li->inicio;
    printf("Lista: ");
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    Lista* li = criar_lista();
    inserir_inicio(li, 10);
    inserir_inicio(li, 20);
    inserir_inicio(li, 30);
    imprimir_lista(li);
    printf("tamanho da lista: %d\n", tamanho_lista(li));
    printf("removendo o inicio: %d\n", remover_inicio(li));
    imprimir_lista(li);
    printf("tamanho da lista: %d\n", tamanho_lista(li));
    printf("buscando o valor 20: %d\n", buscar_lista(li, 20));
    printf("buscando o valor 40: %d\n", buscar_lista(li, 40));
    printf("lista vazia: %d\n", lista_vazia(li));

    // Inserindo três elementos no final
    inserir_fim(li, 100);
    inserir_fim(li, 200);
    inserir_fim(li, 300);
    imprimir_lista(li);
    printf("tamanho da lista: %d\n", tamanho_lista(li));
    return 0;
}