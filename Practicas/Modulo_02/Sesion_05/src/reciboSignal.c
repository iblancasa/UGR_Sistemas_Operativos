/*
 reciboSignal.c
 Trabajo con llamadas al sistema del Subsistema de Procesos conforme a POSIX
 2.10
 Utilizacion de la llamada sigaction para cambiar el comportamiento del proceso
 frente a la recepcion de una senial.
*/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

static void sig_USR_hdlr(int sigNum) {
  if (sigNum == SIGUSR1) {
    printf("\nRecibida la senial SIGUSR1\n\n");
  } else if (sigNum == SIGUSR2) {
    printf("\nRecibida la senial SIGUSR2\n\n");
  }
}

int main(int argc, char *argv[]) {
  struct sigaction sig_USR_nact;
  if (setvbuf(stdout, NULL, _IONBF, 0)) {
    perror("\nError en setvbuf");
  }

  // Inicializar la estructura sig_USR_na para especificar la nueva acci�n para
  // la senial.

  sig_USR_nact.sa_handler = sig_USR_hdlr;

  //'sigemptyset' inicia el conjunto de seniales dado al conjunto vac�o.

  sigemptyset(&sig_USR_nact.sa_mask);
  sig_USR_nact.sa_flags = 0;

  // Establecer mi manejador particular de senial para SIGUSR1
  if (sigaction(SIGUSR1, &sig_USR_nact, NULL) < 0) {
    perror(
        "\nError al intentar establecer el manejador de senial para SIGUSR1");
    exit(-1);
  }
  // Establecer mi manejador particular de senial para SIGUSR2
  if (sigaction(SIGUSR2, &sig_USR_nact, NULL) < 0) {
    perror(
        "\nError al intentar establecer el manejador de senial para SIGUSR2");
    exit(-1);
  }
  for (;;) {
  }
}
