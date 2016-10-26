#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int f_write, f_read, dim, i = 1;
  char buffer[80];
  char *output_file = "salida.txt";

  if (argc < 2) {
    f_read = STDIN_FILENO;
  } else {
    char *pathname = argv[1];
    f_read = open(pathname, O_RDONLY);
  }

  f_write = open(output_file, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);

  if (f_read < 0) {
    printf("\nError %d en el open", errno);
    perror("\nNo se ha podido abrir el archivo de lectura.");
    exit(-1);
  }

  if (f_write < 0) {
    printf("\nError %d en el write", errno);
    perror("\nNo se ha podido abrir el archivo de escritura.");
    exit(-1);
  }

  while ((dim = read(f_read, &buffer, 80)) > 0) {
    char buffer_ID[12];
    sprintf(buffer_ID, "##Bloque %i##", i);
    write(f_write, &buffer_ID, sizeof(buffer_ID));
    write(f_write, "\n", 1);

    write(f_write, &buffer, dim);
    write(f_write, "\n", 1);
    write(f_write, "\n", 1);

    i++;
  }

  if (lseek(f_write, 0, SEEK_SET) < 0) {
    perror("\nError en lseek");
    exit(-1);
  }

  char num_bloques[27];
  sprintf(num_bloques, "El numero de bloques es %i", i - 1);

  write(fd2, &num_bloques, sizeof(num_bloques));
  write(fd2, "\n", 1);

  close(f_write);
  close(f_read);
  return 0;
}
