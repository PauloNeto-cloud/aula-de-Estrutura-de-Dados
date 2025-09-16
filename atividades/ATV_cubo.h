typedef struct cubo{
    float aresta;
} cubo;

// Cria um novo cubo com a aresta informada
cubo* Cubo_Criar(float a);

// Libera a memória de um cubo
void Cubo_Destruir(cubo* c);

// Retorna o valor da aresta de um cubo
float Cubo_Acessar(cubo* c);

// Atribui um novo valor de aresta ao cubo
void Cubo_Atribuir(cubo* c, float a);

// Calcula a área total do cubo
float Cubo_Area(cubo* c);

// Calcula o volume do cubo
float Cubo_Volume(cubo* c);