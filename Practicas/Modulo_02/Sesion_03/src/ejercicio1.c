#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void comprobar_paridad(int value) {
  if (value % 2 == 0) {
    printf("Hola, soy el hijo y el numero es par. \n");
  } else {
    printf("Hola, soy el hijo y el numero es impar. \n");
  }
}

void comprobar_divisibilidad(int value) {
  if (value % 4 == 0) {
    printf("Hola, soy el padre y el numero es divisible entre 4. \n");
  } else {
    printf("Hola, soy el padre y el numero no es divisible entre 4. \n");
  }
}

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    perror("\nError: ./ejercicio1 <numero_comprobar>");
    exit(-1);
  } else {
    pid_t pid = fork();

    if (pid == 0) {
      comprobar_paridad(atoi(argv[1]));
    } else if (pid > 0) {
      comprobar_divisibilidad(atoi(argv[1]));
    }
  }

  return 0;
}
