#include <stdlib.h>

#include <stdio.h>

#include <fcntl.h>

#include <unistd.h>

#include <string.h>

#include <errno.h>

int eroare( char *mesaj ) {

if( errno )   perror(mesaj) ;

else    printf("%s\n" ,  mesaj) ;

exit(2) ;

}
int NumNL(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    int count = 0;
    int c;
    while ((c = getc(fp)) != EOF) {
        count += (c == '\n');
    }
    fclose(fp);
    return count;
}
int main (int argc, char *argv[ ]) {

int fd , i ,  l_read ; char *f  ; void *p_buf  ;

fd = open( argv[1] ,O_RDONLY )  ;

if ( fd == -1 )  eroare("eroare deschidere fisier") ;

i = lseek( fd, 0 ,SEEK_END ) ;

if ( i == -1)  eroare("eroare 1 pozitionare fisier") ;

if ( lseek( fd , 0 , SEEK_SET ) ==  -1)  eroare("eroare 2 pozitionare inceput fisier") ;

p_buf = (char *)malloc(i) ;

l_read = read( fd , p_buf , i ) ;

if( l_read == -1 || l_read < i )   eroare("eroare citire fisier") ;
int nr=0;
nr=NumNL(argv[1]);
write(1 , p_buf , l_read) ;
printf("Lungimea fisierului in octeti: %d\n Numarul de linii este: %d",i, nr );
close(fd) ;

}
