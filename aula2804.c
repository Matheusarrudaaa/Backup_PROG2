#include <stdio.h>
#include <stdlib.h>

typedef struct ans
{
	int i;
	struct ans *dir;
	struct ans *esq;
}nodo_t;

void inorder(nodo_t *n);
void preorder(nodo_t *n);
void posorder(nodo_t *n);

int main()
{	
	nodo_t *raiz = NULL;

	preorder(raiz);	
	inorder(raiz);
	posorder(raiz);
	
	return 0;
}

void preorder(nodo_t *n)
{
if(n == NULL){
	return;	
}
	
printf("%d\n", n->i);
preorder(n->esq);
preorder(n->dir);
return;
}
void inorder(nodo_t *n)
{
if(n == NULL){
    return;
}

inorder(n->esq);
printf("%d\n", n->i);
inorder(n->dir);
return;
}
void posorder(nodo_t *n)
{
if(n == NULL){
    return;
}

posorder(n->esq);
posorder(n->dir);
printf("%d\n", n->i);
return;
}
