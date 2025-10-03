#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct pilha {
    int qtd;
    char dados[MAX];
} Pilha;

Pilha* criar_Pilha() {
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha)); 
    if (pi != NULL) { 
        pi->qtd = 0;  
    }
    return pi; 
}

void destruir_pilha(Pilha* pi){
    free(pi);
}

int inserir_Pilha(Pilha* pi, char dado){ 
    if(pi == NULL || pi->qtd == MAX){
        return 0;
    }
    pi->dados[pi->qtd] = dado;
    pi->qtd++;
    return 1;
}

int remover_Pilha(Pilha* pi, char *dado){ 
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    *dado = pi->dados[pi->qtd - 1];
    pi->qtd--;
    return 1;
}

int main() {
    char palavra[MAX];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    Pilha* pi = criar_Pilha();

    
    for(int i = 0; i < strlen(palavra); i++){
        inserir_Pilha(pi, palavra[i]);
    }

    printf("Palavra invertida: ");
    char letra;
    while(remover_Pilha(pi, &letra)){ 
        printf("%c", letra);
    }
    printf("\n");

    destruir_pilha(pi);
    return 0;
}