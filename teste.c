#include <string.h>
#include <stdio.h>

int main(){
char l[60] = "danone";
l[0] = '(';
printf("%s\n", l);
printf("%c\n", l[strlen(l)]);
printf("%c\n", l[strlen(l) - 1]);

	return 0;
}
