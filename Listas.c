#include <stdio.h>
#include <stdlib.h>

typedef struct st_lista
{
int c; //o item armazenado
struct st_lista *prox; //ponteiro para próximo
}lista;

void imprimir(lista *cabeca);
lista *buscar(lista *cabeca, int x);
lista *anterior(lista *cabeca, lista *r);
void inserir(lista **cabeca, int x);
void remover(lista **cabeca, lista *r);



int main(void)
{
lista *l1 = NULL, *b = NULL, *a = NULL;


imprimir(l1);
inserir(&l1, 1);
imprimir(l1);
inserir(&l1, 2);
imprimir(l1);
inserir(&l1, 3);
imprimir(l1);
printf("-------------------\n");

b=buscar(l1, 2);

if(b!=NULL){
printf("b->c: %d\n", b->c);
printf("-------------------\n");
}
a=anterior(l1, b);

if(a!=NULL){
printf("a->c: %d\n", a->c);
printf("-------------------\n");
}
b=buscar(l1, 2);
remover(&l1, b);
imprimir(l1);
}

lista *buscar(lista *cabeca, int x)
{
lista *pl = cabeca;

while(pl != NULL)
{
    if(pl->c==x)
        return pl;
        pl=pl->prox;
    }
    
    return NULL;
}

void inserir(lista **cabeca, int x)
{
lista *pl=*cabeca;
lista *plant=NULL;
while(pl!=NULL)
{
plant=pl;
pl=pl->prox;
}
pl=malloc(sizeof(lista));
pl->c=x;
pl->prox=NULL;
if(plant!=NULL)
plant->prox=pl;
else
*cabeca=pl;
}

void remover(lista **cabeca, lista *r)
{
lista *pl=*cabeca;
lista *plant=NULL;
if(r==NULL)
return;
while(pl!=NULL && pl!=r) //ate achar r ou fim
{
plant=pl;
pl=pl->prox;
}
if(pl==NULL) //nao achou ou lista vazia
return;
if(plant!=NULL) //tem anterior
plant->prox=pl->prox;
else //eliminando cabeca
*cabeca=pl->prox;
free(pl);
return;
}
lista *anterior(lista *cabeca, lista *r)
{
lista *pl=cabeca, *plant=NULL;
if(r==NULL)
return NULL;
while(pl!=NULL && pl!=r)
{
plant=pl;
pl=pl->prox;
}
return plant;
}
void imprimir(lista *cabeca)
{

lista *pl = cabeca;

while(pl != NULL)
{
printf("%d->",pl->c);
pl=pl->prox;
}
printf("NULL\n");
}