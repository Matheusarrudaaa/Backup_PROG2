/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *    Copyright (C) 2022 by Matheus Henrique De Arruda                      *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Matheus Henrique De Arruda <mha1@poli.br>                         *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 99232-9583                                                  *
 * ************************************************************************ *
 *
 */
#include <stdio.h>
#include <stdlib.h>
//struct lista
typedef struct st_lista
{
    int c; 
    struct st_lista *prox; 
} lista;
//declaracao das funcoes
lista *buscar(lista *cabeca, int x);
void inserir(lista **cabeca, int x);
void remover(lista **cabeca, lista *r);
lista *anterior(lista *cabeca, lista *r);
void imprimir(lista *cabeca);

int main(void)
{   //variaveis do tipo struct lista
    lista *l1 = NULL, *b = NULL, *a = NULL;

	//impressao de cada struct da lista
    imprimir(l1);
    inserir(&l1, 1);
    imprimir(l1);
    inserir(&l1, 2);
    imprimir(l1);
    inserir(&l1, 3);
    imprimir(l1);
    printf("-------------------\n");
	//buscar o valor 2 nas struct
    b = buscar(l1, 2);

    if(b != NULL)
    {
        printf("b->c: %d\n", b->c);
        printf("-------------------\n");
    }
    //achar o valor anterior a 2
	a = anterior(l1, b);

    if(a != NULL)
    {
        printf("a->c: %d\n", a->c);
        printf("-------------------\n");
    }
    //buscar o int c = 2 na lista e remove-lo
	b = buscar(l1, 2);
    remover(&l1, b);
    imprimir(l1);
}

lista *buscar(lista *cabeca, int x)
{	
    lista *pl = cabeca;
	//navegar na lista ate achar o valor determinado, com criterio de parada NULL
    while(pl != NULL)
    {	//se o valor do ponteiro de strct lista for igual ao valor procurado,s era retornado o ponteiro pl
        if(pl->c == x)
            return pl;
        pl = pl->prox;
    }

    return NULL;
}

void inserir(lista **cabeca, int x)
{	//essa funcao vai adicionar/inserir um valor x a lista
    lista *pl = *cabeca;
    lista *plant = NULL;
    //navegacao entre structs da lista
	while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
    }
    //alocacao de memoria
	pl = malloc(sizeof(lista));
    //adicao do valor x para (*pl).c
	pl->c = x;
    pl->prox = NULL;
    if(plant != NULL)
        plant->prox = pl;
    else
        *cabeca = pl;
}

void remover(lista **cabeca, lista *r)
{	//essa funcao ira remover um elemento especificado(*r)
    lista *pl = *cabeca;
    lista *plant = NULL;
    if(r == NULL)
        return;
    //navegacao pelas listas ate o criterio de parada
	while(pl != NULL && pl != r) 
    {
        plant = pl;
        pl = pl->prox;
    }
    //havera um mudancas entre o pl e plant afim de excluir a struct final onde pl aponta(free(pl))
	if(pl == NULL) 
        return;
    if(plant != NULL) 
        plant->prox = pl->prox;
    else 
        *cabeca = pl->prox;
    free(pl);
    return;
}
lista *anterior(lista *cabeca, lista *r)
{	//essa funcao vai retornar um ponteiro do tipo lista referente ao valor anterior ao *r
    lista *pl = cabeca, *plant = NULL;
    if(r == NULL)
        return NULL;
    while(pl != NULL && pl != r)
    {
        plant = pl;
        pl = pl->prox;
    }
    return plant;
}
void imprimir(lista *cabeca)
{	//sera printado cada elemento dessa lista
    lista *pl = cabeca;
    while(pl != NULL)
    {
        printf("%d->", pl->c);
        pl = pl->prox;
    }
    printf("NULL\n");
}
