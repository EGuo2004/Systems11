#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main();
int generate(unsigned int *u, size_t size);
void printa(unsigned int *u, int len);

int main() {
  int length = 10;
  unsigned int chicken[length];

  printf("Generate\n");
  generate(chicken,length);
  printa(chicken,length);

  printf("Pushing In File\n");
  int file;
  file = open("file.txt",O_WRONLY,0644);
  write(file,chicken,sizeof(int) * length);;

  printf("Pulling From File\n");
  file = open("file.txt",O_RDONLY);
  unsigned int cow[10];
  read(file,cow,sizeof(int) * length);

  printf("Vertification\n");
  printa(cow,length);
}

int generate(unsigned int *u, size_t size) {
  int file;
  file = open("/dev/urandom",O_RDONLY);
  read(file,u,size);
}

void printa(unsigned int *u, int len) {
  int counter;
  for (counter = 0; counter < len; counter++) {
    printf("#%d = %u\n", counter, u[counter]);
  }
}
