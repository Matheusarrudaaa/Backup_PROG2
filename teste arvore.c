#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_arvore{
    char pergunta[100];
    struct st_arvore *nao;
    struct st_arvore *sim;
}t_arvore;

void inserir(t_arvore **raiz);

int main(){

t_arvore *raiz = NULL;

inserir(&raiz);
inserir(&raiz);
inserir(&raiz);
inserir(&raiz);
inserir(&raiz);

return 0;
}

void inserir(t_arvore **raiz)
{
char quest;
char caract[100];
t_arvore *cpy = *raiz;

if((*raiz) == NULL){
  t_arvore *ramo = (t_arvore*)malloc(sizeof(t_arvore));
    printf("pense em um animal que vou adivinhar...\n");
    printf("Nao sei! Qual animal vc pensou? \n");
    fgets(ramo->pergunta, 100, stdin);
    ramo->pergunta[strlen(ramo->pergunta) - 1] = '\0';
    printf("Obrigado, Aprendi mais um!!\n\n");

   (*raiz) = ramo;
    ramo->sim = NULL;
    ramo->nao = NULL;
}

else{

while(1){


printf("pense em um animal/caracteristica que vou adivinhar...\n");
printf("Seu animal e' um(a) /ou uma caracteristica e' que(e'): %s?\n", cpy->pergunta);
scanf("%c", &quest);


if(quest == 'y'){
    if(cpy->sim == NULL && cpy->nao == NULL){
                printf("acertei!\n\n");
                break;
    }
    cpy = cpy->sim;

}
if(quest == 'n'){
    if(cpy->sim == NULL && cpy->nao == NULL){

                t_arvore *ramo1 = (t_arvore*)malloc(sizeof(t_arvore));
                t_arvore *ramo2 = (t_arvore*)malloc(sizeof(t_arvore));

                printf("Nao sei!Qual animal vc pensou? \n");
                scanf("%s", ramo1->pergunta);//lobo
                printf("Oque diferencia um %s de um %s?\n", ramo1->pergunta, cpy->pergunta);
                scanf("%s", caract);  //selvagem
                printf("para ser %s tem que responder 's' ou 'n'?\n", ramo1->pergunta);


                strcpy(ramo2->pergunta, cpy->pergunta);
                strcpy(cpy->pergunta, caract);

                while(1){
                    scanf("%c", &quest);

                    if(quest == 'y'){
                        cpy->sim = ramo1;
                        cpy->nao = ramo2;
                        break;
                    }
                    if(quest == 'n'){
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
}
