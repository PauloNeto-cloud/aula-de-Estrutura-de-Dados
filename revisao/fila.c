#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int qtd, inicio, fim;
    char dados[100];
}fila;

fila* criar(){
    fila* fi;
    fi = (fila* ) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi -> qtd = 0;
        fi -> inicio = 0;
        fi -> fim = 0;
    }
    return fi;
}

void destruir(fila* fi){
    free(fi);
}


int implementar_fila(fila* fi, char valor){
    if(fi == NULL){
        return 0;
    }
    if(fi->qtd == 100){
        return 0;
    }
    fi->dados[fi->fim] = valor;
    fi->fim = (fi->fim + 1) % 100;
    fi->qtd++;
    return 1;
}

int remover_fila(fila* fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->qtd == 0){
        return 0;
    }
    fi->inicio = (fi->inicio + 1) % 100;
    fi->qtd--;
    return 1;   
}