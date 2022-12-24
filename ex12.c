#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleat(int matriz[20][20], int linha, int coluna, int contador, int min, int max);

int main()
{

    int linha, coluna, i, somaprod = 0, contador;
    int M1L, M1C, M2L, M2C;
    int matriz1[20][20];
    int matriz2[20][20];
    int matriz3[20][20];

    printf("Digite o numero de linhas da m1: \n");
    scanf("%d", &M1L);
    printf("Digite o numero de colunas da m1: \n");
    scanf("%d", &M1C);

    printf("Digite o numero de linhas da m2: \n");
    scanf("%d", &M2L);
    printf("Digite o numero de colunas da m2: \n");
    scanf("%d", &M2C);

    contador = M1L * M1C;
    aleat(matriz1, M1L, M1C, contador, 1, 50);

    contador = M2L * M2C;
    aleat(matriz2, M2L, M2C, contador, 25, 75);



    if(M1C == M2L)
    {

        for(linha = 0; linha < M1L; linha++)
        {
            for(coluna = 0; coluna < M2C; coluna++)
            {
                somaprod = 0;
                for(i = 0; i <= M1L; i++)
                {
                    if(i == M1C)
                        break;
                    somaprod += matriz1[linha][i] * matriz2[i][coluna];

                }
                matriz3[linha][coluna] = somaprod;
            }
        }
        //imprime mat1
        printf("\nMatriz 1: \n\n");
        for(int lin = 0; lin < M1L; lin++)
        {
            for(int col = 0; col < M1C; col++)
                printf("%d ", matriz1[lin][col]);
            printf("\n");
        }
//imprime mat2
        printf("\nMatriz 2: \n\n");
        for(int lin = 0; lin < M2L; lin++)
        {
            for(int col = 0; col < M2C; col++)
                printf("%d ", matriz2[lin][col]);
            printf("\n");
        }

        //imprime mat3
        printf("\nMatriz resultante: \n\n");
        for(int lin = 0; lin < M1L; lin++)
        {
            for(int col = 0; col < M2C; col++)
                printf("%d ", matriz3[lin][col]);
            printf("\n");
        }

    }
    else
        printf("Nao eh possivel multiplicar as matrizes\n");

    return 0;
}

void aleat(int matriz[20][20], int linha, int coluna, int contador, int min, int max)
{

    srand(time(NULL));
    int vetor[30] = {0};
    int aux, i, j;


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

    i = 0;
    for(int m = 0; m < linha; m++)
        for(int w = 0; w < coluna; w++)
        {
            matriz[m][w] = vetor[i];
            i++;
        }

}
