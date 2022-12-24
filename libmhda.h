/* *********************************************************************** *
 *    LIB PESSOAL, VERSION                                                 *
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
 *  Webpage: http://beco.poli.br/                                           *
 *  Phone: (81) 99232-9583                                                  *
 * ************************************************************************ *
 * 
 */

#ifndef libmhda_biblioteca_h
#define libmhda_biblioteca_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct st_lista
{
    int c; //o item armazenado
    struct st_lista *prox; //ponteiro para próximo
} lista;

//struct para a funcao norm_var
struct Normalizacao
{
    float Numero;
    float Xmax;
    float Xmin;
} norm;
struct randomicos
{
    int contador;
    int max;
    int min;
} aleat;

typedef struct st_arvore
{
    char pergunta[100];
    struct st_arvore *nao;   
    struct st_arvore *sim;
}t_arvore;

typedef struct no{
    float valor;
    struct no *prox;
}No;

//declaracao da funcao
float norm_var(float Numero, float Xmax, float Xmin);
int num_aleat(int contador, int max, int min);
void pr_fix(char nome1[20], char nome2[20]);
void sufixo(char nomeo[20], char nomec[20]);
void subpalavra(char nome1[20], char nome2[20]);
void concatenacao(char nome1[20], char nome2[20]);
void inserir_rand(lista **cabeca, int x);
void inserir(lista **cabeca, int x);
void imprimir(lista *cabeca);
void invert(char nome[], char aux[], int n);
void mult_matriz(void);
void esparsas(void);
void inserir_arvore(t_arvore **raiz);
No* push(No *topo, float num);
No* pop(No **topo);
float calculo(float a, float b, char x);
float resolver_expressao(char x[], No *topo);

#endif
