#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int esPrimo(int n) {
  int raiz = sqrt(n);
  int es_primo = 1;

  for (int i = 2; i <= raiz && es_primo; i++) {
    if (n % i == 0) {
      es_primo = 0;
    }
  }

  return es_primo;
}

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("Modo de uso: %s <inicio> <fin>\n\n", argv[0]);
    exit(-1);
  }

  int inicio = atoi(argv[1]);
  int fin = atoi(argv[2]);

  for (int i = inicio; i < fin; i++) {
    if (esPrimo(i)) {
      printf("El numero %d es primo.\n", i);
    }
  }

  return 0;
}
