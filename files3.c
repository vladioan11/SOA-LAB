
/*Sa se scrie in limbajul  C  un program numit  files3.c 
 care afiseaza numarul de caractere din doua fisiere text, dar si diferentele dintre acestea 

(numarul de caractere diferite), iar la finalul executiei 
va afisa numarul de caractere si linii proprii.

Numele fisierelor vor fi transmise ca parametri in linia de comanda. 


Sa se rezolve problema folosindu-se obligatoriu 
primitivele pentru lucrul cu fisiere din biblioteca 
<fcntl.h> :  open , close , read , write , lseek . */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

#include <errno.h>

int NumNL(const char *filename){
	FILE *fp = fopen(filename, "r");
	if(fp == NULL){
		return -1;
	}
	int count =0;
	int c;
	while ((c=getc(fp))!= EOF){
		count+=(c=='\n');
	}
	fclose(fp);
	return count;
}

int main(int argc, char *argv[ ]) {
int fd1,i, l_read1, fd2, l_read2;
char *p_buf;
char *p_buf2;
int num1, num2;
if(argc<3){
	printf("Not enough files!!!\n");
	return 0;
}
fd1 = open(argv[1], O_RDONLY);
i = lseek(fd1, 0, SEEK_END);
lseek(fd1, 0, SEEK_SET);
p_buf=(char *)malloc(i);

l_read1=read(fd1, p_buf , i);
int nrl1=0, nrl2=0;
nrl1=NumNL(argv[1]);
num1=i;
fd2= open(argv[2], O_RDONLY);
i = lseek(fd2, 0, SEEK_END);
lseek(fd2, 0, SEEK_SET);
p_buf2=(char *)malloc(i);
l_read2=read(fd2, p_buf2,i);
num2=i;
nrl2=NumNL(argv[2]);
printf("Fisierul %s are %d caractere si %d linii.\n",argv[1], num1, nrl1);
printf("Fisierul %s are %d caractere si %d linii.\n",argv[2], num2, nrl2);

int diff_chars = 0;
int min_len;
if(num1<num2){
	min_len=num1;
	
}else{
	min_len=num2;
	}
for(int j = 0; j < min_len; j++){
    if(p_buf[j] != p_buf2[j]) {
        diff_chars++;
    }
}
diff_chars += (num1 > num2) ? (num1 - num2) : (num2 - num1);

int prop1_chars = 0, prop2_chars = 0;
for(int j = 0; j < num1; j++){
    int found = 0;
    for(int k = 0; k < num2; k++){
        if(p_buf[j] == p_buf2[k]) { found = 1; break; }
    }
    if(!found) prop1_chars++;
}
for(int j = 0; j < num2; j++){
    int found = 0;
    for(int k = 0; k < num1; k++){
        if(p_buf2[j] == p_buf[k]) { found = 1; break; }
    }
    if(!found) prop2_chars++;
}

printf("Numarul de caractere diferite: %d\n", diff_chars);
printf("Fisierul %s are %d caractere proprii si %d linii proprii.\n", argv[1], prop1_chars, nrl1);
printf("Fisierul %s are %d caractere proprii si %d linii proprii.\n", argv[2], prop2_chars, nrl2);

free(p_buf);
free(p_buf2);

	return 0;
}
