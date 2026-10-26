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

write(1 , p_buf , l_read) ;

close(fd) ;

}
