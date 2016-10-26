#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct stat atributos;

  struct dirent *fichero;
  DIR *dir;

  int chmod_result, permisos_antiguos, permisos_nuevos;

  dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Error: No se puede abrir el directorio: %s\n", argv[1]);
    exit(2);
  }

  while ((fichero = readdir(dir)) != NULL) {
    chdir(argv[1]);
    if (stat(fichero->d_name, &atributos) < 0) {
      printf("Error al intentar acceder a los atributos de %s\n",
             fichero->d_name);

    } else {
      if (!S_ISDIR(atributos.st_mode)) {
        permisos_nuevos = strtol(argv[2], 0, 8) & 0777;
        permisos_antiguos = atributos.st_mode & 0777;
        chmod_result = chmod(fichero->d_name, permisos_nuevos);
        if (chmod_result < 0) {
          printf("%s : \t%d \t%o\n", fichero->d_name, chmod_result,
                 permisos_antiguos);
          exit(-1);
        } else {
          printf("%s : \t%o \t%o\n", fichero->d_name, permisos_antiguos,
                 permisos_nuevos);
        }
      }
    }
  }

  closedir(dir);

  return 0;
}
