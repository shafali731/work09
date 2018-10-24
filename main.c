#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> //for open
#include <unistd.h> //for close

int main() {
  //OPEN
  //if file not in directory, foo.txt created
  int fd = open("foo.txt", O_RDONLY | O_CREAT);  
  printf("fd = %d\n", fd); 
  if (fd < 0) 
    printf("File already exists. File not created or opened.\n");           

  //CLOSE 
  // Using close system call 
  if (close(fd) < 0) {
    printf("File already exists. File not closed.\n"); 
    exit(1); 
  }  
  printf("closed the fd\n");

  //READ
} 
