/*
 envioSignal.c
 Trabajo con llamadas al sistema del Subsistema de Procesos conforme a POSIX
 2.10
 Utilizacion de la llamada kill para enviar una senial:
 0: SIGTERM
 1: SIGUSR1
 2: SIGUSR2
  a un proceso cuyo identificador de proceso es PID.
 SINTAXIS: envioSignal [012] <PID>
*/

#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  long int pid;
  int signal;

  if (argc < 3) {
    printf("\nSintaxis de ejecuci�n: envioSignal [012] <PID>\n\n");
    exit(-1);
  }

  pid = strtol(argv[2], NULL, 10);

  if (pid == LONG_MIN || pid == LONG_MAX) {
    if (pid == LONG_MIN) {
      printf("\nError por desbordamiento inferior LONG_MIN %d", pid);
    } else {
      printf("\nError por desbordamiento superior LONG_MAX %d", pid);
      perror("\nError en strtol");
      exit(-1);
    }
  }

  signal = atoi(argv[1]);

  switch (signal) {
  case 0: // SIGTERM
    kill(pid, SIGTERM);
    break;
  case 1: // SIGUSR1
    kill(pid, SIGUSR1);
    break;
  case 2: // SIGUSR2
    kill(pid, SIGUSR2);
    break;
  default: // not in [012]
    printf("\n No puedo enviar ese tipo de senial");
  }
}
