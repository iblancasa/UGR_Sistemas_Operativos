#include <signal.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  sigset_t new_mask;
  sigemptyset(&new_mask); // Inicializamos la nueva mascara de señales
  sigfillset(&new_mask);  // Inicializamos la mascara con todas las señales
  sigdelset(&new_mask, SIGUSR1); // Borramos la señal SIGUSR1 del conjunto
  sigsuspend(&new_mask);         // Esperamos a la señal SIGUSR1
}
