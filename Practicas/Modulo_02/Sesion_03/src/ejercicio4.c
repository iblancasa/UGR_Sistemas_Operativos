#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int i;
  const int NUM_HIJOS = 5;
  pid_t pid[NUM_HIJOS];

  for (int i = 0; i < NUM_HIJOS; i++) {
    if ((pid[i] = fork()) == 0) {
      printf("Soy el hijo PID %d \n", getpid());
      break;
    } else if (pid[i] < 0) {
      printf("Error in creating child process \n.");
      return -1;
    }
  }

  for (int i = 0; i < NUM_HIJOS; i++) {
    if (waitpid(pid[i], 0, 0) > 0) {
      printf("Acaba de finalizar mi hijo con PID %d \n", pid[i]);
      printf("Solo me quedan %d hijos vivos \n", NUM_HIJOS - (i + 1));
    }
  }

  return 0;
}
