#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //for open
#include <unistd.h> //for close
#include <string.h>
int main(){
  char c[128];
  char *name = "foo.txt";
  int fd = open(name, O_WRONLY);
  printf("fd = %d\n", fd);
  if (fd < 0)
    printf("File already exists. File not created or opened.\n");

  char added[] = "hello friends";
  write(fd, added, 128);
  printf("hello friends was written\n");
  if (close(fd) < 0) {
    printf("File already exists. File not closed.\n");
    exit(1);
  }
  printf("closed the fd\n");

  int fd1 = open(name, O_RDWR);
  int sz= read(fd1, c, strlen("hello friends\n"));
  printf("bytes read: %d\n", sz);

  printf("Those bytes are as follows: %s\n", c);

  //printf("'%s'\n", c);
  printf("Closing '%s'\n", name);
  close(fd1);
  return 0;
}
