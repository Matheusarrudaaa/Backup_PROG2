
/***************************************************************************
 *   ex8.c                                    Version 20220331.103443      *
 *                                                                         *
 *   brief: Comparacoes e trocas realizadas por 2 funcoes de ordenacao     *
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
 * $gcc ex8.c -o ex8.x -Wall -Wextra -g -O0 -DDEBUG=1
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
/* #include "ex8.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "20220331.103443" /* Version Number (string) */
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
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void bubble_sort(int copy[], int x);
void insertion_sort(int *a, int y);
void Tabela(void);

/* ---------------------------------------------------------------------- */
/* This function does ...
 * 
 * It receives as input ... 
 *
 * It returns ...
 */
int Comp_Troc[12];

int main(void)
{
    /* code */
    help();
    copyr();
  
    srand(time(NULL));//permite criar numeros aleatorio(nao pseudo-aleatorios)
//variaveis originais e copias
int num_C[500], num_D[500], num_A[500];
int count, cpy_C[500], cpy_D[500], cpy_A[500];
  
  
  //adicionando valores em um vetor do melhor caso (ordem crescente)
  for (int i = 0; i < 500; i++) {
    num_C[i] = i;
 }
  //adicionando valores em um vetor do pior caso (ordem decrescente)
for (int i = 0; i < 500; i++) {
    
    num_D[499 - i] = i;
 }
  //adicionando valores em um vetor do caso medio (valores aleatorios)
for (int i = 0; i < 500; i++){
  num_A[i] = rand() % 500;
}
  //copia dos vetores originais
  for(count = 0; count <500; count++){
    cpy_C[count] = num_C[count];
    cpy_D[count] = num_D[count];
    cpy_A[count] = num_A[count];
  }
//chamado da bubble sort
bubble_sort(num_C, 0);
bubble_sort(num_D, 2);
bubble_sort(num_A, 4);
//chamdado da insertiont sort
insertion_sort(cpy_C, 6);
insertion_sort(cpy_D, 8);
insertion_sort(cpy_A, 10);

Tabela();//chamado funcao de print

	
	
	/* ...and we are done */
    return EXIT_SUCCESS;
}

/* add more functions here */
void bubble_sort(int copy[], int x)
{  
   int i, aux, contador, comp = 0, troca = 0;   
 //funcao que navega sobre os elementos do vetor e compara o antecessor com o sucessor
 for (contador = 1; contador < 500; contador++) {
   for (i = 0; i < 500 - 1; i++) {
        comp++;
     if (copy[i] > copy[i + 1]) {//caso o valor anterior for maior, havera a troca de posicoes com o sucessor
       troca++;
       aux = copy[i];//sendo essa troca intermediada por uma variavel auxiliar
       copy[i] = copy[i + 1];
       copy[i + 1] = aux;
     }
   }
  
 }
  Comp_Troc[x] = comp;//adicionando o numero de comparacoes no vetor global
  Comp_Troc[x + 1] = troca;//adicionando o numero de trocas no vetor global
}
void insertion_sort(int *a, int y)
{
 int i, j, aux, compIS = 0, trocaIS = 0;
//funcao que navega sobre os elementos do vetor e compara o sucessor com o antecessor, de modo que o exista a troca de posicoes
//caso o posterior seja menor que o anterior
  for(i = 1; i < 500; i++)
 {
  aux = a[i];
  compIS++;
  for(j = i; j > 0 && aux < a[j -1]; j--)
  {
    a[j] = a[j - 1];//acessa o elemento anterior a j
    trocaIS++;
  }
  a[j] = aux;
 } 
  Comp_Troc[y] = compIS;//adicionando o numero de comparacoes no vetor global
  Comp_Troc[y + 1] = trocaIS;//adicionando o numero de trocas no vetor global
}
void Tabela(void)//funcao de printagem da tabela com comparacoes e trocas
{
printf("\n--------------------------Tabela de comparacoes--------------------------------\n");
printf("*         Bubble Sort                      |              Insertion Sort      *\n");
printf("-------------------------------------------------------------------------------\n");
printf("*Caso A| Comparacoes: %d Trocas: %d     |  Comparacoes: %d Trocas: %d      *\n",Comp_Troc[0], Comp_Troc[1], Comp_Troc[6], Comp_Troc[7]);
printf("*Caso B| Comparacoes: %d Trocas: %d|  Comparacoes: %d Trocas: %d *\n",Comp_Troc[2], Comp_Troc[3], Comp_Troc[8], Comp_Troc[9]);
printf("*Caso C| Comparacoes: %d Trocas: %d |  Comparacoes: %d Trocas: %d  * \n",Comp_Troc[4], Comp_Troc[5], Comp_Troc[10], Comp_Troc[11]);
printf("-------------------------------------------------------------------------------\n\n");
printf("**Caso A: Vetor Crescente| Caso B: Vetor Decrescente| Caso C: Vetor Aleatorio**\n\n");
}
/* ---------------------------------------------------------------------- */
/* Prints help information 
 *  usually called by opt -h or --help
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex8", "Brief description");
    printf("\nUsage: %s\n\n", "ex8");
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
    printf("%s - Version %s\n", "ex8", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2022, "Matheus Henrique De Arruda", "mha1@poli.br");
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

