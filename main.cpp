#include <iostream>
#include "Grafo.h"
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
using namespace std;

int main() {
	
	//Declaracao de variaveis
	Grafo *gr;
	int opcao;
	int origem, destino, digrafo , qte_vertices, qte_grau, verifica_peso;
	float peso;
	banner();
	setlocale(LC_ALL,"Portuguese");
	
	//Menu
	do
	{
		cout<<"[1] -Criar um Grafo"<<endl;
		cout<<"[2] - Exibir Grafo"<<endl;
		cout<<"[3] - Adicionar Arestas"<<endl;
		cout<<"[4] - Remover Arestas"<<endl;
		cout<<"[5] - Traçar caminho mais curto"<<endl;
		cout<<"[6] - Remover todo o grafo"<<endl;
		cout<<"Opcao:";
		cin>>opcao;	
	
		switch(opcao)
		{
			case 1:
				//Caso para criar Grafo
				limpa_tela();
				cout<<"Informe quantidade de vertices:";
				cin>>qte_vertices;
				cout<<"Informe quantidade maxima de graus:";
				cin>>qte_grau;
				gr = cria_Grafo(qte_vertices,qte_grau,0);
				cout<<"Grafo criado com sucesso";
				system("pause>>NULL");
				break;
			
			case 2:
				limpa_tela();
				int vis[5];
				cout<<"[+] - Buscando todas as arestas"<<endl;
				buscaGrafo(gr, 0,vis);
				system("pause>>NULL");
				break;
			case 3:
					//Inserir arestas
					//insereAresta(gr, 0 , 1,0,0);
					//insereAresta(gr, 1 , 3,0,0);
				limpa_tela();
				cout<<"[+] - Adicionando  aresta"<<endl<<endl;
				cout<<" --> Insere a aresta de origem:";
				cin>>origem;
				cout<<"--> Insere a aresta de destino:";
				cin>>destino;
				cout<<"--> Informe o peso:";
				cin>>peso;
				insereAresta(gr, origem, destino, 0, peso);
				break;
			
			case 4:
				
				cout<<"[-] - Removendo a aresta"<<endl<<endl;
				cout<<" --> Insere a aresta de origem:";
				cin>>origem;
				cout<<"--> Insere a aresta de destino:";
				cin>>destino;
				removeAresta(gr, origem,destino,0);
				break;
			default:
				
				cout<<"Opcao invalida";
			
		}
		Sleep(1000);
		limpa_tela();	
	}
	
	while(opcao);

	
	libera_Grafo(gr);
		
	system("pause");
	return 0;
}
