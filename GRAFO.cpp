#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

#define Vertice int

typedef struct no { 
    Vertice w; 
    struct no *prox; 
} No;


typedef struct noGrafo {
    Vertice v;  
    No *adj; 
    struct noGrafo *prox;
} ListaAdj;



No *criaNo (Vertice v1, No *p) { 
No *x;
       x = (No *) malloc (sizeof(No));
       x->w = v1; 
       x->prox = p;     
       return x;                         
    }


ListaAdj *criaGrafoNo (Vertice v1, No *p, ListaAdj *g) { 
ListaAdj *x;
       x = (ListaAdj *) malloc (sizeof(ListaAdj));
       x->v = v1; 
       x->adj = p;    
       x->prox = g; 
       return x;                         
    }


void inserirAdj(ListaAdj *g){
No *l;  
int quant,i; 
Vertice v;
   while (g != NULL) {
         l=NULL;
         printf("Informe o numero de ligacoes partindo da cidade %d:",g->v);
         scanf("%d",&quant);
         for(i=0;i<quant;i++){    
             printf("   ------ > Codigo da cidade de chegada: ");
             scanf("%d",&v);
             l=criaNo(v,l);
         } 
         g->adj=l;
         g=g->prox;     
   } 
}

void percorrerListaAdj(ListaAdj *g){
   while (g!=NULL) {
         printf("\n\n      Codigo cidade: %d",g->v);
         while (g->adj != NULL){    
            printf("\n  De cidade %d para %d ",g->v,g->adj->w); 
            g->adj = g->adj->prox;
         } 
         g=g->prox;     
   }     
}


int main(){

   int quant,i; 
   Vertice v;

   ListaAdj *g=NULL;

   printf("Inserir a quantidade de cidades (vertices): ");
   scanf("%d",&quant);

   
   for(i=0;i<quant;i++){              
     printf("Informar o codigo da cidade: ");
     scanf("%d",&v);
     g=criaGrafoNo(v,NULL,g);
   }
   
   inserirAdj(g);
   percorrerListaAdj(g);  

  
    
    
    system("pause>>null");   
}
