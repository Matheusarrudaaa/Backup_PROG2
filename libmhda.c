/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
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

#include "libmhda.h"

float norm_var(float Numero, float Xmax, float Xmin)
{
    float result = 1;
    //recebendo dados do usuario
    printf("Digite um Numero: ");
    scanf("%f", &Numero);
    printf("Digite um valor Minimo: ");
    scanf("%f", &Xmin);
    printf("Digite um valor Maximo: ");
    scanf("%f", &Xmax);
    //verificacao da condicao de "existencia" para nivel de calculo
    if(Numero < Xmax && Numero >= Xmin)
        result = (Numero - Xmin) / (Xmax - Xmin);
    else
        printf("A normalizacao do numero escolhido nao esta no intervalo [0,1[\n");//condicao nao foi satisfeita

    return result;
}

int num_aleat(int contador, int max, int min)
{
    srand(time(NULL));
    int vetor[30];
    int aux, i, j;
    //input do usuario
    printf("Digite a quantidade de numeros aleatorios que se deseja: ");
    scanf("%i", &contador);
    //recebendo maximos e minimos
    printf("Digite o intervalo para achar os numeros aleatorios: \n");
    printf("De: ");
    scanf("%i", &min);
    printf("Ate: ");
    scanf("%i", &max);
    //ciclo for para criacao de variaveis aleatoria
    for(i = 0; i < contador; i++)
        vetor[i] = min + rand() % (max + 1);
    while(1)
    {
        aux = 0;
        for(i = 0; i < contador; i++)
            for(j = 0; j < i; j++)//ciclo apra verificar se os elementos sao diferentes
                if(vetor[i] == vetor[j])
                {
                    aux++;//variavel para verificacaod e diferenca
                    vetor[i] = min + (rand() % (max + 1));//caso o numero ja exista no vetor ele sera substituido ate o numero ser diferente
                }

        if(aux == 0)//condicao de parada para o ciclo infinito
            break;
    }

    for(i = 0; i < contador; i++) //print do vetor sem repeticao
        printf("%d\n", vetor[i]);


    return contador;
}

void pr_fix(char nome1[20], char nome2[20])
{
    //variavel
    char nomeAux[20];
    strcpy(nomeAux, nome1);//copia da string nome1 para nomeAux

    nomeAux[strlen(nome2)] = '\0';//caractere nulo

    if(strcmp(nomeAux, nome2) == 0)//comparacao de strings para verificar se eh prefixo ou nao
        printf("E' prefixo\n");
    else
        printf("Nao e' prefixo\n");//condicao nao satisfeita
}

void sufixo(char nomeo[20], char nomec[20])
{

    char nome3[20] = " ";//string vazia
    char nome4[20] = " ";//string vazia

    int j = 0;
    for(int i = strlen(nomeo) - 1; i >= 0; i--)//inverter uma string
    {
        nome3[j] = nomeo[i];
        j++;
    }

    nome3[strlen(nomec)] = '\0';//caractere de fim de string

    int z = 0;
    for(int x = strlen(nome3) - 1; x >= 0; x--)
    {
        nome4[z] = nome3[x];
        z++;
    }
    //comparacao dos finais das strings, uma sendo a copia e a outra a original parametro da funcao
    if(strcmp(nomec, nome4) == 0)
        printf("E' Sufixo\n");
    else
        printf("Nao e' sufixo\n");//condicao nao satisfeita
}

void subpalavra(char nome1[20], char nome2[20])
{
    // local das variaveis
    int aux = 0;
    int x = strlen(nome1);
    int y = strlen(nome2);
    //ciclo for para verificacao de subpalavra
    for(int m = 0; m <= x - 1; m++)
    {
        if(nome1[m] == nome2[aux])//analise de um caractere especifico das strings
        {
            aux += 1;//caso a condicao for aceita a varaivel aux eh somada 1 unidade
            if(nome1[m + 1] != nome2[aux])//condicaod e parada
                break;
        }
    }

    if(y == aux)//print para o usuario
        printf("E' sub-palavra\n");
    else//print casoa  condicao nao seja satisfeita, isto eh, nao eh subpalavra
        printf("Nao e' sub-palavra\n");

}
void concatenacao(char nome1[20], char nome2[20])
{
    //junta 2 strings em 1 so
    strcat(nome1, nome2);
    printf("Concatenacao: %s\n", nome1);//print para o usuario
}

void inserir_rand(lista **cabeca, int x)
{
    lista *pl = *cabeca;//criacao pl
    lista *plant = NULL;//criacao pl anterior
    while(pl != NULL)//navegacao entre os elementos da lista
    {
        plant = pl;
        if(pl->c == x)//caso meu parametro "x" seja igual ao valor de um elementos da lista
        {
            do
            {
                x = 1 + rand() % 75;//ele sera substituido por outro valor randomico, ate ambos serem diferentes
                if(pl->c != x)//quando forem diferentes o laco termina
                    break;
            }
            while(1);
        }
        pl = pl->prox;//pl avancara para o proximo elemento da lista
    }
    pl = malloc(sizeof(lista));//alocacao de memoria
    pl->c = x;//substituicao do valor "parametro" pelo valor da struct onde pl se encontra
    pl->prox = NULL;
    if(plant != NULL)
        plant->prox = pl;//movimentar o plant ate pl
    else
        *cabeca = pl;
}

void imprimir(lista *cabeca)
{

    lista *pl = cabeca;

    while(pl != NULL)//acessar cada elemento da struct
    {
        printf("%d->", pl->c);//printar o inteiro onde pl se encontra
        pl = pl->prox;//fazer pl apontar para o proximo
    }
    printf("NULL\n");
    free(pl);//edsalocar memoria
}
void invert(char nome[], char aux[], int n)
{
    //funcao recursiva de inversao de string
    if(n == -1)
        return;
    //cada vez que a recursiva "rodar" vai haver a adicao do caractere da string principal na auxiliar, de acordo com o "n" retornado
    int tamAux = strlen(aux);
    aux[tamAux] = nome[n];
    aux[tamAux + 1] = '\0';
    //chamado da funcao invert(recursao)
    invert(nome, aux, n - 1);
}
void mult_matriz(void)
{
    //local das variaveis
    int linha, coluna, i, aux = 0;
    int M1L, M1C, M2L, M2C;
    int matriz1[20][20];
    int matriz2[20][20];
    int matriz3[20][20];
    //dimensao da matriz 1
    printf("Digite o numero de linhas da m1: \n");
    scanf("%d", &M1L);
    printf("Digite o numero de colunas da m1: \n");
    scanf("%d", &M1C);
    //dimensao da matriz 2
    printf("Digite o numero de linhas da m2: \n");
    scanf("%d", &M2L);
    printf("Digite o numero de colunas da m2: \n");
    scanf("%d", &M2C);

    //para ser possivel calcular a multiplicacao de matrizes o numero de colunas da 1 tem q ser igual ao numero de linhas da 2
    if(M1C == M2L)
    {
        printf("\nDigite a matriz m1: \n");//recebendo a matriz 1
        for(int z = 0; z < M1L; z++)
            for(int w = 0; w < M1C; w++)
            {
                printf("linha[%d] e coluna[%d]: \n", z, w);
                scanf("%d", &matriz1[ z ][ w ]);
            }

        printf("\nDigite a matriz m2: \n");//recebendo a matriz 2
        for(int z = 0; z < M2L; z++)
            for(int w = 0; w < M2C; w++)
            {
                printf("linha[%d] e coluna[%d]: \n", z, w);
                scanf("%d", &matriz2[ z ][ w ]);
            }
        //operacao de multiplicacao e soma entre linhas e colunas das duas matrizes
        for(linha = 0; linha < M1L; linha++)
        {
            for(coluna = 0; coluna < M2C; coluna++)
            {
                aux = 0;
                for(i = 0; i <= M1L; i++)
                {
                    if(i == M1C)//condicao de parada caso a variavel i seja igual ao numero de colunas da matriz 1
                        break;
                    aux += matriz1[linha][i] * matriz2[i][coluna];//soma do produto entre linhas e colunas das matrizes

                }
                matriz3[linha][coluna] = aux;
                //a matriz resultante da mult entre matrizes tera dimensao igual a o numero de linhas da 1
                //e o numerod e colunas da 2 matriz
            }
        }
        //imprime a matriz resultante da multiplicacao
        printf("\nMatriz resultante da multiplicacao de m1 por m2: \n\n");
        for(int lin = 0; lin < M1L; lin++)
        {
            for(int col = 0; col < M2C; col++)
                printf("%d ", matriz3[lin][col]);
            printf("\n");
        }

    }
    else //caso o numero de colunas da 2 seja diferente do numero de linhas da 1...
        printf("Nao eh possivel multiplicar as matrizes\n");

}
void inserir(lista **cabeca, int x)
{
    lista *pl = *cabeca;
    lista *plant = NULL;
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(lista));
    pl->c = x;
    pl->prox = NULL;
    if(plant != NULL)
        plant->prox = pl;
    else
        *cabeca = pl;
}
void esparsas(void)
{
    //declaracao das variaveis
    srand(time(NULL));
    int esparsa1[5][5];
    int esparsa2[5][5];
    int matriz3[5][5];
    int a, i, j, linha, coluna, somaprod;
    lista *l1 = NULL;
    /*como nas matrizes esparsas a maioria dos elementos sao nulos, usei o rand para chegar em media a pelomenos 70% de valores
     * nulos, enquanto o resto vai ser preenchido com numeros de ate 20*/

    //completando esparsa1
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
        {
            int a =  rand() % 101;
            if(a <= 70)
                esparsa1[i][j] = 0;
            else
                esparsa1[i][j] = rand() % 21;
        }
    //completando esparsa2
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
        {
            a =  rand() % 101;
            if(a <= 70)
                esparsa2[i][j] = 0;
            else
                esparsa2[i][j] = rand() % 21;
        }
    //multiplicando esparsas 1 e 2
    for(linha = 0; linha < 5; linha++)
    {
        for(coluna = 0; coluna < 5; coluna++)
        {
            somaprod = 0;
            for(i = 0; i <= 5; i++)
            {
                if(i == 5)
                    break;
                somaprod += esparsa1[linha][i] * esparsa2[i][coluna];
            }
            matriz3[linha][coluna] = somaprod;
            if(somaprod != 0)
                inserir(&l1, somaprod);//adicao dos elementos nao nulos em uma lista
        }
    }
    //print da esparsa1
    printf("Esparsa1: \n");
    for(int lin = 0; lin < 5; lin++)
    {
        for(int col = 0; col < 5; col++)
            printf("%d ", esparsa1[lin][col]);
        printf("\n");
    }
    //print da esparsa2
    printf("\nEsparsa2: \n");
    for(int lin = 0; lin < 5; lin++)
    {
        for(int col = 0; col < 5; col++)
            printf("%d ", esparsa2[lin][col]);
        printf("\n");
    }
    //print do resultado
    printf("\nResultado: \n");
    for(int lin = 0; lin < 5; lin++)
    {
        for(int col = 0; col < 5; col++)
            printf("%d ", matriz3[lin][col]);
        printf("\n");
    }
    printf("\nElementos nao nulos resultantes da multiplicacao das esparsas:\n");
    imprimir(l1);//imprimir a lista formada por elementos nao nulos
}
void inserir_arvore(t_arvore **raiz)
{
    char quest;
    char caract[100];
    t_arvore *cpy = *raiz;

    if((*raiz) == NULL)
    {
        t_arvore *ramo = (t_arvore *)malloc(sizeof(t_arvore));
        printf("pense em um animal que vou adivinhar...\n");
        printf("Nao sei! Qual animal vc pensou? \n");
        fgets(ramo->pergunta, 100, stdin);
        ramo->pergunta[strlen(ramo->pergunta) - 1] = '\0';
        printf("Obrigado, Aprendi mais um!!\n\n");

        (*raiz) = ramo;
        ramo->sim = NULL;
        ramo->nao = NULL;
    }

    else
    {

        while(1)
        {

            printf("pense em um animal/caracteristica que vou adivinhar...\n");
            printf("Seu animal e' um(a) /ou uma caracteristica e' que(e'): %s?\n", cpy->pergunta);
            quest = 'y';
            scanf("%c", &quest);

            if(quest == 'y')
            {
                if(cpy->sim == NULL && cpy->nao == NULL)
                {
                    printf("acertei!\n\n");
                    break;
                }
                cpy = cpy->sim;

            }
            if(quest == 'n')
            {
                if(cpy->sim == NULL && cpy->nao == NULL)
                {

                    t_arvore *ramo1 = (t_arvore *)malloc(sizeof(t_arvore));
                    t_arvore *ramo2 = (t_arvore *)malloc(sizeof(t_arvore));

                    printf("Nao sei!Qual animal vc pensou? \n");
                    scanf("%s", ramo1->pergunta);
                    printf("Oque diferencia um %s de um %s?\n", ramo1->pergunta, cpy->pergunta);
                    scanf("%s", caract);
                    printf("para ser %s tem que responder 'y' ou 'n'?\n", ramo1->pergunta);


                    strcpy(ramo2->pergunta, cpy->pergunta);
                    strcpy(cpy->pergunta, caract);

                    while(1)
                    {
                        scanf("%c", &quest);

                        if(quest == 'y')
                        {
                            cpy->sim = ramo1;
                            cpy->nao = ramo2;
                            break;
                        }
                        if(quest == 'n')
                        {
                            cpy->nao = ramo1;
                            cpy->sim = ramo2;
                            break;
                        }

                    }
                    ramo1->sim = NULL;
                    ramo1->nao = NULL;
                    ramo2->sim = NULL;
                    ramo2->nao = NULL;
                    printf("Obrigado! Aprendi mais um!!!\n\n");
                    break;
                }
                cpy = cpy->nao;
            }


        }

    }

    return;
}
//funcao para empilhar um elemento um uma pilha
No *push(No *topo, float num)
{
    No *novo = malloc(sizeof(No));//alocacao de memoria

    novo->valor = num;//o numero digitado pelo usuario sendo substituido na struct
    novo->prox = topo;//o ponteiro prox da variavel novo sendo apontado para o ponteiro topo da pilha
    return novo;

}
//funcao para desempilhar um ponteiro da lista
No *pop(No **topo)
{

    No *remover = NULL;
    remover = *topo;//ponteiro aponta para o valor do ponteiro topo, uma vez que eh um ponteiro de ponteiro
    *topo = remover->prox;//topo apontando para o remover proximo que eh um ponteiro

    return remover;
}
//funcao para realizar as operacoes soma, subtracao, multiplicacao e divisao
float calculo(float a, float b, char x)
{
    if(x == '+')
        return a + b;
    if(x == '-')
        return a - b;
    if(x == '*')
        return a * b;
    if(x == '/')
        return a / b;
    return 0.0;
}
float resolver_expressao(char x[], No *topo)
{
    //variaveis
    char *pt;
    float num;
    No *n1, *n2;

    pt = strtok(x, " ");//funcao da string.h em que conteúdo da string é modificado e dividido em strings menores
    while(pt)
    {
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*') //verificar os operadores para nivel de calculo
        {
            n1 = pop(&topo);//ponteiro n1 que recebe o ponteiro remover da funcao pop de desempilhar
            n2 = pop(&topo);
            num = calculo(n2->valor, n1->valor, pt[0]);//os parametros enviados para a funcao calculo sao o numero 1 o numero 2 e a operacao
            topo = push(topo, num);//o num retornado pela funcao calculo eh adicionado ao topo da pilha
            //desalocacao de memoria
            free(n1);
            free(n2);
        }
        else
        {
            num = strtol(pt, NULL, 10);
            topo = push(topo, num);
        }
        pt = strtok(NULL, " ");//quebra dos "espacoes" entre os elementos da string
    }
    n1 = pop(&topo);
    num = n1->valor;
    free(n1);//desalocacao de memoria
    return num;
}

