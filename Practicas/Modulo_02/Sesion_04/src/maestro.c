#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define ARCHIVO_FIFO "comunicacion";

int main(int argc, char *argv[]) {
  int inicio, fin, mitad, numBytes;
  int fd1[2];
  int fd2[2];
  char buffer[80];
  char params[2];

  if (argc != 3) {
    printf("Modo de uso: %s <inicio> <fin>\n\n", argv[0]);
    exit(1);
  }

  inicio = atoi(argv[1]);
  fin = atoi(argv[2]);
  mitad = inicio + ((fin - inicio) / 2);

  pid_t PID;
  pipe(fd1);
  pipe(fd2);

  if ((PID = fork()) < 0) {
    perror("Error al hacer fork");
    exit(1);
  }
  if (PID == 0) {
    close(fd1[0]);
    params[0] = inicio;
    params[1] = mitad;

    printf("paso 1\n");
    dup2(fd1[1], STDOUT_FILENO);
    execlp("esclavo", "esclavo", params, NULL);
  } else {
    if ((PID = fork()) < 0) {
      perror("Error al hacer fork");
      exit(1);
    }

    if (PID == 0) {
      close(fd2[0]);
      params[0] = mitad + 1;
      params[1] = fin;
      printf("paso 2\n");
      dup2(fd2[1], STDOUT_FILENO);
      execlp("esclavo", "esclavo", params, NULL);
      exit(0);
    } else {
      close(fd1[1]);
      numBytes = read(fd1[0], buffer, sizeof(buffer));
      dup2(fd1[0], STDIN_FILENO);

      printf("paso 3\n");

      while ((numBytes = read(fd1[0], &buffer, 4)) > 0) {
        printf("Valor: %d", 1);
      }
    }
  }

  exit(0);
}
