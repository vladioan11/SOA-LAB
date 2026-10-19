#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main(void){
	char *s="Examen final";
	char * t; int i; int n=strlen(s);
	t=(char *)malloc(n * sizeof(char));
if(!t){
	printf("Eroare alocare zona de memorie\n");
	exit(1);
}
for(i=0;i<n;i++){
	t[i]=s[i];
}
t[i]='\0';
printf("%s %s\n", s, t);
return 0;
}
