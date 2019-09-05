//Arquivo Grafo.h

typedef struct grafo Grafo;

//Cria 
Grafo *cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);

//libera
void libera_Grafo(Grafo *gr);

// Insere aresta
int insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso);

// Remover arestas

int removeAresta(Grafo *gr, int orig, int dest, int eh_digrafo);

void buscaGrafo(Grafo *gr, int ini, int *visitado);


void banner();

void limpa_tela();
