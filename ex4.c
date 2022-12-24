#include "libmhda.h"

int main(){
    
	char nome1[20];
    char nome2[20];

    scanf("%[^\n]s", nome1);
    scanf("%s", nome2);
	
    if(strlen(nome1) >= strlen(nome2)){
	printf("\n");
	pr_fix(nome1, nome2);    
 	sufixo(nome1, nome2);		
    subpalavra(nome1, nome2);		
    concatenacao(nome1, nome2);
	}
	else{
	printf("\n");
	pr_fix(nome2, nome1);
	sufixo(nome2, nome1);
	subpalavra(nome2, nome1);
	concatenacao(nome2, nome1);
	}
	
	return 0;
}
