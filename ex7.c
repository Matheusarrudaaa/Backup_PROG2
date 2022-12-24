#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct lista
typedef struct st_lista
{
char Snomes[20]; //o item armazenado
struct st_lista *prox; //ponteiro para próximo
}lista;
//declaracao das funcoes
void inserir(lista **cabeca, char nomes[]);
void imprimir(lista *cabeca);

int main(void)
{
//variaveis
lista *l1 = NULL;
char nome[10][35],aux[25];
int n = 9,i,j, comp = 0, trocas = 0;
  

printf("Digite 10 nomes: \n");
  for(i=0;i<=n;i++)
  {
       
       fgets(nome[i], sizeof nome, stdin);//input do usuario
  }
     
//algoritmo Bubble Sort
for(i=1;i<=n;i++)

    for(j=0;j<=n-i;j++){
		comp++;//numero de comparacoes
	  if(strcmp(nome[j],nome[j+1])>0)
	  { 
        trocas++;//numero de trocas
        strcpy(aux,nome[j]);//movimentacao de strings ate achar a ordem correta
	    strcpy(nome[j],nome[j+1]);
	    strcpy(nome[j+1],aux);
	  }
}
   printf("\n------------String em ordem alfabetica------------\n\n");
	      for(i=0;i<=n;i++){
		 inserir(&l1, nome[i]);//chamado da funcao inserir
            }
imprimir(l1);//chamado da funcao imprimir
printf("Ocorreram %d comparacoes e %d trocas!\n", comp, trocas);
}
void inserir(lista **cabeca, char nomes[])
{
lista *pl=*cabeca;
lista *plant=NULL;
while(pl!=NULL)//ciclo while para nevegar entre os elementos da lista, ate ser achado NULL
{
plant=pl;
pl=pl->prox;
}
pl=malloc(sizeof(lista));//aloca memoria

strcpy(pl->Snomes,nomes);//copia a string recebida pelo usuario


pl->prox=NULL;
if(plant!=NULL)
plant->prox=pl;
else
*cabeca=pl;

}
//funcao para imprimir a lista
void imprimir(lista *cabeca)
{
lista *pl=cabeca;
while(pl!=NULL)
{
//criacao da variavel copia, que possibilita a lista ficar na mesma linha na hora do printf
char copia[20];
strcpy(copia, pl->Snomes);
copia[strlen(copia) - 1] = '\0';//iguala o ultimo indice da string copia a \0
printf("%s->",copia);
pl=pl->prox;//movimentacao pelos elementos da lista
}
printf("NULL\n\n");
free(pl);//desalocacao de memoria
}
