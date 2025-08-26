typedef struct ponto ponto;

//criar um novo ponto
ponto* pontoCria(float x, float y);

//acessar os valores de x e y
int ponto_acessar(ponto* p, float x, float y);

//atribui os valores
int ponto_atribuir(ponto* p, float x, float y);

// calcular a distacia dos pontos
float ponto_distancial(ponto* p1, ponto* p2);

// libera o ponto
void ponto_liberar(ponto* p);