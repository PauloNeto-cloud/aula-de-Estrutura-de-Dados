//Dada uma fila de números, reorganize para que os pares fiquem na frente e os ímpares atrás, preservando ordem relativa.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct fila {
    int inicio, fim, qtd;
    int dados[MAX]; 
} fila;

fila* criar_fila(){
    fila* fi = (fila*) malloc(sizeof(fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->fim = 0;
        fi->qtd = 0;
    }
    return fi;
}

void destruir_fila(fila* fi){
    free(fi);
}

int fila_vazia(fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == 0);
}

int fila_cheia(fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == MAX);
}

int inserir_fila(fila* fi, int valor){
    if(fi == NULL || fila_cheia(fi)){
        return 0;
    }
    fi->dados[fi->fim] = valor;
    fi->fim = (fi->fim + 1) % MAX;
    fi->qtd++;
    return 1;
}

int remover_fila(fila* fi, int* valor){
    if(fi == NULL || fila_vazia(fi)){
        return 0;
    }
    *valor = fi->dados[fi->inicio];
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    return 1;
}

int main(){
    fila* fi = criar_fila();
    int n, numero;

    printf("Quantos numeros deseja inserir na fila? ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Digite o numero %d: ", i+1);
        scanf("%d", &numero);
        inserir_fila(fi, numero);
    }

    fila* pares = criar_fila();
    fila* impares = criar_fila();
    int num;

    while(!fila_vazia(fi)){
        remover_fila(fi, &num);
        if(num % 2 == 0){
            inserir_fila(pares, num);
        } else {
            inserir_fila(impares, num);
        }
    }

    printf("Fila reorganizada (pares na frente, impares atras): ");
    while(!fila_vazia(pares)){
        remover_fila(pares, &num);
        printf("%d ", num);
    }
    while(!fila_vazia(impares)){
        remover_fila(impares, &num);
        printf("%d ", num);
    }
    printf("\n");

    destruir_fila(fi);
    destruir_fila(pares);
    destruir_fila(impares);
    return 0;
}