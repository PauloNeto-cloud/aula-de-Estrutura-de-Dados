#include <stdio.h>
#include "ATV_cubo.h"

int main(){
    float valor, novovalor;

    printf("Digite o valor da aresta do cubo (pode ser quebrado, ex: 2.75): ");
    scanf("%f", &valor);

    cubo *meucubo = Cubo_Criar(valor);

    printf("aresta do cubo: %.2f\n", Cubo_Acessar(meucubo));
    printf("area do cubo: %.2f\n", Cubo_Area(meucubo));
    printf("volume do cubo: %.2f\n", Cubo_Volume(meucubo));

    printf("\nDigite um novo valor para a aresta do cubo (pode ser quebrado, ex: 1.33): ");
    scanf("%f", &novovalor);
    printf("Novo valor lido: %.2f\n", novovalor);
    Cubo_Atribuir(meucubo, novovalor);
    printf("Valor armazenado no cubo: %.2f\n", Cubo_Acessar(meucubo));

    printf("nova aresta do cubo: %.2f\n", Cubo_Acessar(meucubo));
    printf("nova area do cubo: %.2f\n", Cubo_Area(meucubo));
    printf("novo volume do cubo: %.2f\n", Cubo_Volume(meucubo));

    Cubo_Destruir(meucubo);

    return 0;
}