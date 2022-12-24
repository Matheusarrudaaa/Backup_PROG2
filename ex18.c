/***************************************************************************
 *   ex18.c                                   Version 20220511.200437      *
 *                                                                         *
 *  Printagem de arvores binarias                                          *
 *   Copyright (C) 2022         by Matheus Henrique De Arruda              *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Matheus Henrique De Arruda                                            *
 *   Email: mha1@poli.br                                                   *
 *   Webpage: http://beco.poli.br/mha1@poli.br                             *
 *   Phone: (81) 99232-9583                                                *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex18.c -o ex18.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h>  /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex18.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "20220511.200437" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */

/* ---------------------------------------------------------------------- */
typedef struct st_arvore
{
    int num;
    struct st_arvore *nao;
    struct st_arvore *sim;
} t_arvore;
/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void inserir_arv(t_arvore **raiz);
void preorder(t_arvore *n);
void inorder(t_arvore *n);
void posorder(t_arvore *n);
/* ---------------------------------------------------------------------- */

int main(void)
{
    /* code */
    help();
    copyr();
    srand(time(NULL));//criar numeros aleatorios de acordo com o tempo decorrido
    t_arvore *raiz = NULL;

    for(int j = 0; j < 25; j++)//gerar arvore aleatoria de tamanho 25
        inserir_arv(&raiz);


    printf("\nPrintagem preorder: ");
    preorder(raiz);//chamadado da funcao preorder
    printf("NULL");
    printf("\n\nPrintagem inorder: ");
    inorder(raiz);//chamadado da funcao inorder
    printf("NULL");
    printf("\n\nPrintagem posorder: ");
    posorder(raiz);//chamadado da funcao posorder
    printf("NULL\n\n");

    return EXIT_SUCCESS;
}
/* add more functions here */
/* ---------------------------------------------------------------------- */
void inserir_arv(t_arvore **raiz)//funcao para inserir elementos em uma arvore
{
    t_arvore *cpy = *raiz;//ponteiro "cabeca"

    if((*raiz) == NULL)//condicional para quandoa arvore esta vazia
    {
        t_arvore *ramo = (t_arvore *)malloc(sizeof(t_arvore));//alocacao de memoria

        ramo->num = rand() % 101;
        (*raiz) = ramo;//raiz aponta para a struct alocada
        ramo->sim = NULL;
        ramo->nao = NULL;
    }
    else//caso exista pelomenos um elemento: ...
    {

        int aux = rand() % 101;//numero aleatorio de 0 a 100

        while(1)//ciclo infinito
        {
			//verificar se o numero gerado eh maior que o numero na posicao do ponteiro copia da raiz(cpy)
            if(aux >= cpy->num && cpy->sim == NULL)
            {
                t_arvore *ramo1 = (t_arvore *)malloc(sizeof(t_arvore));//alocacao de memoria
                ramo1->num = aux;//adicao de aux na struct alocada
                cpy->sim = ramo1;
                ramo1->sim = NULL;//os ponteiros mais extremos da arvore tem que apontar para NULL
                ramo1->nao = NULL;
                break;
            }
            if(aux < cpy->num && cpy->nao == NULL)
            {
                t_arvore *ramo2 = (t_arvore *)malloc(sizeof(t_arvore));//alocacao de memoria
                ramo2->num = aux;//adicao de aux na struct alocada
                cpy->nao = ramo2;
                ramo2->sim = NULL;//os ponteiros mais extremos da arvore tem que apontar para NULL
                ramo2->nao = NULL;
                break;
            }
            //condicionais para navegar pela arvore ate achar o ponteiro NULL (fim da arvore)
            if(cpy->sim != NULL && aux >= cpy->num)
                cpy = cpy->sim;

            if(cpy->nao != NULL && aux < cpy->num)
                cpy = cpy->nao;
        }

    }

    return;
}
/* ---------------------------------------------------------------------- */
void preorder(t_arvore *n)
{
    if(n == NULL)
        return;

    printf("%d-> ", n->num);//printagem
    preorder(n->nao);//recursividade ate o fim do ponteiro nao (esquerda)
    preorder(n->sim);//recursividade ate o fim do ponteiro sim (direita)
    return;
}
/* ---------------------------------------------------------------------- */
void inorder(t_arvore *n)
{
    if(n == NULL)
        return;

    inorder(n->nao);//recursividade ate o fim do ponteiro nao (esquerda)
    printf("%d-> ", n->num);//printagem
    inorder(n->sim);//recursividade ate o fim do ponteiro sim (direita)
    return;
}
/* ---------------------------------------------------------------------- */
void posorder(t_arvore *n)//funcao de printagem de arvore binaria em que a printagem vem apos a recursividade
{
    if(n == NULL)
        return;

    posorder(n->nao);//recursividade ate o fim do ponteiro nao (esquerda)
    posorder(n->sim);//recursividade ate o fim do ponteiro sim (direita)
    printf("%d-> ", n->num);//printagem
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints help information
 *  usually called by opt -h or --help
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "Printagem de arvores binarias", "ex18.c");
    printf("\nUsage: %s\n\n", "ex18");
    printf("This program does...\n");
    /* add more stuff here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Matheus Henrique De Arruda", "mha1@poli.br");
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information
 *  usually called by opt -V
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex18", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2022, "Matheus Henrique De Arruda", "mha1@poli.br");
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

