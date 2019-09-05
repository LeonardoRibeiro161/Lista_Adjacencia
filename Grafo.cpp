#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "Grafo.h" //Inclui o prototipo

//Definindo o tipo de Grafo
using namespace std;
struct grafo
{
	int eh_ponderado;
	int nro_vertices;
	int grau_max; 
	int **arestas;
	float **pesos;
	int *grau;
};

//Funcao que cria meu grafo
Grafo *cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado)
{
	Grafo *gr=(Grafo *)malloc(sizeof(struct grafo));
	if(gr != NULL)
	{
		int i;
		gr->nro_vertices = nro_vertices;
		gr->grau_max = grau_max;
		gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
		gr->grau = (int *)calloc(nro_vertices, sizeof(int));
		gr->arestas = (int **)malloc(nro_vertices *sizeof(int*));
		for(i = 0; i < nro_vertices; i++)
		{
			gr->arestas[i] = (int *)malloc(grau_max*sizeof(int));
			if(gr->eh_ponderado)
			{
				gr->pesos = (float **)malloc(nro_vertices * sizeof(float*));
				for(i = 0; i <nro_vertices;i++)
				{
					gr->pesos[i] = (float *)malloc(grau_max * sizeof(float));
				}
			}
		}
	}
	return gr;
}

//Funcao para liberar meu grafo

void libera_Grafo(Grafo *gr)
{
	if(gr != NULL)
	{
		int i;
		for(i = 0; i < gr->nro_vertices;i++)
		{
			free(gr->arestas[i]);
		}
		free(gr->arestas);
		if(gr->eh_ponderado)
		{
			for( i = 0; i <gr->nro_vertices; i++)
			{
				free(gr->pesos[i]);
			}
			free(gr->pesos);
		}
		free(gr->grau);
		free(gr);
	}
	
}

//Função para inserir arestas

int insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso)
{
	//Verifica se vertice existe
	if(gr == NULL)
		return NULL;
	if(orig < 0 || orig >= gr->nro_vertices)
		return 0;
	if(dest < 0 || dest >= gr->nro_vertices)
		return 0;
	
	//Insere no final da linha
	
	gr->arestas[orig][gr->grau[orig]] = dest;
	
	if(gr->eh_ponderado)
		gr->pesos[orig][gr->grau[orig]] = peso;
	gr->grau[orig]++;
	
	//Insere outra aresta se NAO digrafo 
	if(eh_digrafo == 0)
		insereAresta(gr,dest, orig, 1,peso);//Força o relacionamento  para que o destino liga com a origem
	return 1;
}

//Função para remover uma aresta
int removeAresta(Grafo *gr, int orig, int dest, int eh_digrafo)
{
	//Verificando se vertice existe
	if(gr == NULL)
		cout<<"[!] - Grafo vazio"<<endl;
		return NULL;
	
	if(orig < 0 || orig >= gr->nro_vertices)
		cout<<"[!] - Erro na remocao, a origem e menor que 0"<<endl;
		return 0;
	
	if(dest < 0 || dest >= gr->nro_vertices)
			cout<<"[!] - Erro na remocao, o destino e maior que o total de vertices do grafo"<<endl;
		return 0;
	
	int i = 0;
	//Busca pela aresta
	while(i < gr->grau[orig] && gr->arestas[orig][i] != dest)
		i++;
	if(i == gr->grau[orig]) //elemento nao encontrado
		return 0;
	gr->grau[orig]--;
	gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
	if(gr->eh_ponderado)
		gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
	if(eh_digrafo == 0)
		removeAresta(gr, dest, orig,1);
	return 1;
}

//Funcao auxiliar
void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont)
{
	int i;
	visitado[ini] = cont;
	for(i = 0; i < gr->grau[ini];i++) //Marca o vertice como visitado, visita os vizinhos ainda nao visitados
	{
		if(!visitado[gr->arestas[ini][i]])
			buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont+1);
			cout<<"Vertice inicio: ("<<gr->grau[ini] << ") -- Vertice visitado("<<visitado[ini]<<") "<<endl;
	}
}
//Funcao que realiza busca por profundidade
//Principal: Interface com usuario
void buscaGrafo(Grafo *gr, int ini, int *visitado)
{
	int i, cont = 1;
	for(i = 0; i < gr->nro_vertices;i++) //Marca vertices como NAO visitados
	{
		visitado[i] = 0;
	}
	buscaProfundidade(gr , ini, visitado, cont);
}

void banner()
{
	cout<<"--------------------------------------------------------" <<endl;
	cout<<"Grafo - LISTA DE ADJACENCIA"<<endl;
	cout<<"Curso: Ciencia da Computacao"<<endl;
	cout<<"Disciplina: Algoritmos e Estrutura de Dados Avancado"<<endl;
	cout<<"--------------------------------------------------------" <<endl;
}


void limpa_tela()
{
	system("cls");
}
