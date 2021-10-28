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
  FILE *file = open("file.txt",O_WRONLY,0644);
  write(chicken,file,sizeof(int) * size);
  fclose(file);

  printf("Pulling From File\n");
  file = open("file.txt",O_RDONLY);
  unsigned int cow[10];
  read(cow,file,sizeof(int) * size);
  fclose(file);

  printf("Vertification\n");
  printa(cow,length);
}

int generate(unsigned int *u, size_t size) {
  FILE *file = open("file.txt",O_RDONLY);
  read(u,file,sizeof(int) * size);
  fclose(file);
}

void printa(unsigned int *u, int len) {
  int counter;
  for (counter = 0; counter < len; counter++) {
    printf("#%d = %u\n", counter, u[counter]);
  }
}
