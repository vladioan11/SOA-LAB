#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
void eroare(char *mesaj){
	if(errno)
		perror(mesaj);
	else
		fprintf(stderr, "%s\n", mesaj);
	exit(1);
}

int main(void){
	int file_des; int i; char * nume_fis, *p_buf;
	int a=(int)('a'-'A');

	printf("Tastati numele unui fisier text: ");
	nume_fis=(char *) malloc(100);
	scanf("%s", nume_fis);
	file_des=open(nume_fis, O_RDONLY);
	if(file_des==-1)
		eroare("Eroare deschidere fisiser!");
	i=lseek(file_des, 0, SEEK_END);
	if(i==-1)
		eroare("Eroare lseek -1");
	if(lseek(file_des, 0, SEEK_SET)==-1)
		eroare("Eroare lseek -2");

	p_buf=(char*)malloc(i);

	
	if(read(file_des, p_buf, i)!=i)
		eroare("Eroare de citire fisier");
		for(int j=0; j<i;j++){
			if(p_buf[j]>='a' && p_buf[j]<='z'){
				p_buf[j]-=a;
	
			}}
	if(write(1, p_buf, i)!=i)
		eroare("Eroare de scriere fisier");
	
	return 0;
}
