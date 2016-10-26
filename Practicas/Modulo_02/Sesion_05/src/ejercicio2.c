#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int contador[35] = {0};

static void sig_USR_hdlr(int sigNum) {
  contador[sigNum] += 1;
  printf("\nLa señal %s se ha recibido %s veces\n", sigNum, contador[sigNum]);
}

int main(int argc, char const *argv[]) {
  struct sigaction sig_USR_nact;
  if (setvbuf(stdout, NULL, _IONBF, 0)) {
    perror("\nError en setvbuf");
  }

  sig_USR_nact.sa_handler = sig_USR_hdlr;
  sigemptyset(&sig_USR_nact.sa_mask);
  sig_USR_nact.sa_flags = 0;

  printf("\nNo puedo capturar la senial 9");
  printf("\nNo puedo capturar la senial 19");
  printf("\nEsperando el envio de señales...");

  if (sigaction(SIGHUP, &sig_USR_nact, NULL) < 0) {
    perror(
        "\nError al intentar establecer el manejador de la senial para SIGHUP");
    exit(-1);
  }

  if (sigaction(SIGINT, &sig_USR_nact, NULL) < 0) {
    perror(
        "\nError al intentar establecer el manejador de la senial para SIGINT");
    exit(-1);
  }

  if (sigaction(SIGQUIT, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGQUIT");
    exit(-1);
  }

  if (sigaction(SIGILL, &sig_USR_nact, NULL) < 0) {
    perror(
        "\nError al intentar establecer el manejador de la senial para SIGILL");
    exit(-1);
  }

  if (sigaction(SIGTRAP, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGTRAP");
    exit(-1);
  }

  if (sigaction(SIGABRT, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGABRT");
    exit(-1);
  }

  if (sigaction(SIGBUS, &sig_USR_nact, NULL) < 0) {
    perror(
        "\nError al intentar establecer el manejador de la senial para SIGBUS");
    exit(-1);
  }

  if (sigaction(SIGFPE, &sig_USR_nact, NULL) < 0) {
    perror(
        "\nError al intentar establecer el manejador de la senial para SIGFPE");
    exit(-1);
  }

  if (sigaction(SIGUSR1, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGUSR1");
    exit(-1);
  }

  if (sigaction(SIGUSR2, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGUSR2");
    exit(-1);
  }

  if (sigaction(SIGSEGV, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGSEGV");
    exit(-1);
  }

  if (sigaction(SIGPIPE, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGPIPE");
    exit(-1);
  }

  if (sigaction(SIGALRM, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGALRM");
    exit(-1);
  }

  if (sigaction(SIGTERM, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGTERM");
    exit(-1);
  }

  if (sigaction(SIGSTKFLT, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGSTKFLT");
    exit(-1);
  }

  if (sigaction(SIGCHLD, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGCHLD");
    exit(-1);
  }

  if (sigaction(SIGCONT, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGCONT");
    exit(-1);
  }

  if (sigaction(SIGTSTP, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGTSTP");
    exit(-1);
  }

  if (sigaction(SIGTTIN, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGTTIN");
    exit(-1);
  }

  if (sigaction(SIGTTOU, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGTTOU");
    exit(-1);
  }

  if (sigaction(SIGURG, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGURG");
    exit(-1);
  }
  if (sigaction(SIGXCPU, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGXCPU");
    exit(-1);
  }

  if (sigaction(SIGXFSZ, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGXFSZ");
    exit(-1);
  }

  if (sigaction(SIGVTALRM, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGVTALRM");
    exit(-1);
  }

  if (sigaction(SIGPROF, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGPROF");
    exit(-1);
  }

  if (sigaction(SIGWINCH, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGWINCH");
    exit(-1);
  }

  if (sigaction(SIGPOLL, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGPOLL");
    exit(-1);
  }

  if (sigaction(SIGPWR, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGPWR");
    exit(-1);
  }

  if (sigaction(SIGSYS, &sig_USR_nact, NULL) < 0) {
    perror("\nError al intentar establecer el manejador de la senial para "
           "SIGSYS");
    exit(-1);
  }

  for (;;) {
  }
  return 0;
}
