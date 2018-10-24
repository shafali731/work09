#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> //for open
#include <unistd.h> //for close
#include <string.h>

int main() {
  //OPEN
  //if file not in directory, foo.txt created
  int fd = open("foo.txt", O_RDWR | O_CREAT);  
  printf("fd = %d\n", fd); 
  if (fd < 0) 
    printf("File already exists. File not created or opened.\n");           

  //CLOSE 
  //using close system call 
  if (close(fd) < 0) {
    printf("File already exists. File not closed.\n"); 
    exit(1); 
  }  
  printf("closed the fd\n");

  //WRITE
  int fd1 = open("foo.txt", O_RDWR);
  int sz = write(fd1, "hello friends\n", strlen("hello friends\n"));
  printf("hello friends was written\n");
  
  //READ
  char *c = (char *) calloc(100, sizeof(char));
  sz = read(fd1, c, 10);
  printf("called read(% d, c, 10).  returned that"
         " %d bytes  were read.\n", fd1, sz); 
  c[sz] = '\0'; 
  printf("Those bytes are as follows: %s\n", c); 
  close(fd1);
} 
