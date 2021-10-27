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
  FILE *file = fopen("file.txt","w");
  fwrite(chicken,sizeof(int),length,file);
  fclose(file);

  printf("Pulling From File\n");
  file = fopen("file.txt","r");
  unsigned int cow[10];
  fread(cow,sizeof(int),length,file);
  fclose(file);

  printf("Vertification\n");
  printa(cow,length);
}

int generate(unsigned int *u, size_t size) {
  FILE *file = fopen("/dev/urandom", "r");
  fread(u,sizeof(int),size,file);
  fclose(file);
}

void printa(unsigned int *u, int len) {
  int counter;
  for (counter = 0; counter < len; counter++) {
    printf("#%d = %u\n", counter, u[counter]);
  }
}
