#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[]) {
  int nprocs = 20;
  int i;
  pid_t childpid;

  // Jerarquia de procesos tipo 1
  // Cada hijo genera un su hijo

  printf("Jerarquia de procesos Tipo 1:\n");

  for (int i = 1; i < nprocs; i++) {
    if ((childpid = fork() == -1)) {
      fprintf(stderr, "Could not create child %d: %s\n", i, strerror(errno));
      exit(EXIT_FAILURE);
    }

    sleep(3);

    printf("childpid = %d, parentpid = %d \n", getpid(), getppid());

    if (childpid) {
      break;
    }
  }

  // Jerarquia de procesos tipo 2
  // Solo el padre inicial puede generar hijos

  printf("Jerarquia de procesos Tipo 2:\n");

  for (int i = 1; i < nprocs; i++) {
    if ((childpid = fork()) == -1) {
      fprintf(stderr, "Could not create child %d: %s\n", i, strerror(errno));
      exit(EXIT_FAILURE);
    }

    sleep(3);

    printf("childpid = %d, parentpid = %d \n", getpid(), getppid());

    if (!childpid) {
      break;
    }
  }
}
