#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int qtd;
    char dados[100];
}pilha;

pilha* criar(){
    pilha* pi;
    pi = (pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void destruir(pilha* pi){
    free(pi);
}

int verificar_vazia(pilha* pi){
    if(pi == NULL){
        return -1;
    }
    if(pi->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int verificar_tamanho(pilha* pi){
    if(pi == NULL){
        return -1;
    }else{
        return pi->qtd;
    }
}

int inserir(pilha* pi , char valor){
    if(pi == NULL){
        return 0;
    }
    if (pi->qtd == 100){
        return 0;
    }
    pi->dados[pi->qtd] = valor;
    pi->qtd++;
    return 1;
}

int remover_Pilha(pilha* pi){
    if(pi == NULL){
        return 0;
    }
    pi->qtd--;
    return 1;
}

int consultar_topo(pilha* pi , char* valor){
    if(pi == NULL){
        return 0;
    }
    *valor = pi->dados[pi->qtd - 1];
    return 1;       
}
