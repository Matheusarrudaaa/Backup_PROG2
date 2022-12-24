#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *verificar_kl_le(char *le);
char *verificar_pp_le(char *le1, char *le2);

int main()
{
    char *s;
    char *s3;
	s = malloc(2 * sizeof(char));
    s3 = malloc(2 * sizeof(char));
	char s4[100] = "(a|b)";
    char s2[100] = "f.(c|d)";
	
	strcpy(s, s2);
    strcpy(s3, s4);

    printf("%s\n", verificar_pp_le(s4, s2));
   // free(verificar_pp_le(s4, s2));
    free(s);
    free(s3);
	return 0;
}

// apenas "*" quando inicial e final forem "(" e ")", respectivamente e tbm n tem outros parenteses no meio
//   ex1: a.b.(a|b) --> (a.b.(a|b))*
//   ex2: (a|b).(a|c) --> ((a|b).(a|c))*
//   ex3:       (a|b) --> (a|b)*  -->so adiciona o *
//   ex4:  a          --> a*/

char *verificar_kl_le(char *le)
{
    char aux[64];
    char *aux2 = malloc(2 * sizeof(char));
    strcpy(aux, le);
    int x = strlen(aux);

    /* Se so tiver 1 elemento no delta->le*/
    if(strlen(aux)  == 1)
    {
        strcat(aux, "*");
        strcpy(aux2, aux);
        return aux2;
    }
    /*Se tiver mais de um elemento no delta->le*/
    if(aux[0] == '(' && aux[strlen(aux) - 1] == ')')
    {
        for(int j = 1; j < x - 2; j++)
            if(aux[j] == '(' || aux[j] == ')')
            {
                sprintf(aux2, "(%s)*", aux);
                return aux2;
            }
        strcat(aux, "*");
        strcpy(aux2, aux);
        return aux2;
    }
    else
        sprintf(aux2, "(%s)*", aux);

    return aux2;
}
/*
 *
 * 1- se nao existir parenteses nem em le1 nem em le2 --> adiciona parentesis no inicio, pipe no meio e parentesis final
 * 2- se existir um parentesis inicial no le2 e nao no l1 --> parentesis inicial do le2 é retirado e eh adicionado o pipe no meio
 * 3- se existir parentesis inicial no le1 e não no le2 --> substitui-se o parentesis final de le1 pelo pipe e no final da string adiciona-se um ')'
 * 4- se existir tanto parentesis em l1 inicial e le2 final --> retira-se parentesis final de l1 e inicial de l2
 *
 */
char *verificar_pp_le(char *le1, char *le2)
{
    char l1[64];
    char l2[64];
    //char aux[64];
    strcpy(l1, le1);
    strcpy(l2, le2);
    char *aux3 = malloc(2 * sizeof(char));


    if(l1[0] == '(' && l2[0] != '(' )
    {
        printf("3\n");
		l1[strlen(l1) - 1] =	'|';
		l2[strlen(l2)] = ')';
        //le2[strlen(le2) + 1] = '\0';
        strcat(l1, l2);
        strcpy(aux3, l1);
        return aux3;
    }
	
	if(l1[0] == '(' &&  l1[strlen(l1) - 1] == ')' && l2[0] == '(' && l2[strlen(l2) - 1] == ')')
    {
        printf("2\n");
		l1[strlen(l1) - 1] =	'\0';
        l2[0] = '|';
        strcat(l1, l2);
        strcpy(aux3, l1);
        return aux3;

    }
    if(l1[0] != '('  && l2[0] == '(')
    {
        printf("4\n");
		l2[0] = '|';
        sprintf(aux3, "(%s%s", l1, l2);
        return aux3;
    }
   //Se nao existir nao parentesis inicial  em l1 e le2 ---> a + b -> (a|b)
    else	
	{
       printf("1\n");
		//le1[strlen(le1) - 1] = '\0'; 
	   //le2[0] = '|';
	  sprintf(aux3, "(%s|%s)", l1, l2);
	}    
return aux3;
}

