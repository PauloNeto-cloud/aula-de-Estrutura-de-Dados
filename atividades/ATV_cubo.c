#include <stdio.h>
#include <stdlib.h>
#include "ATV_cubo.h"

cubo* Cubo_Criar(float a){
    cubo *c = (cubo*)malloc(sizeof(cubo));
    if(c != NULL){
        c->aresta = a;
    }
    return c;         
}

float Cubo_Area(cubo* c){
    return 6 * c->aresta * c->aresta; 
}

float Cubo_Volume(cubo* c){
    return c->aresta *  c->aresta * c->aresta;
}

void Cubo_Atribuir(cubo* c, float a){
    c->aresta = a;
}

float Cubo_Acessar(cubo* c){
    return c->aresta;
}

    void Cubo_Destruir(cubo* c){
        free(c);
    }
