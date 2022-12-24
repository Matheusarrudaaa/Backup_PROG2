#include "libmhda.h"

int main(void)
{
    lista *l1 = NULL;//criacao do "cabeca" na main
    srand(time(NULL));

    for(int i = 1; i <= 75; i++)//simular o saco de bolas, nao os numeros por cartela(que sao 24 numeros de 1 a 75)
        inserir_rand(&l1, 1 + rand() % 75);//funcao inserir passando como parametro um numero randomico

    printf("O resultado do bingo foi: \n\n");
	imprimir(l1);//funcao imprimir
	printf("\nBoa sorte!\n");
    return 0;
}
