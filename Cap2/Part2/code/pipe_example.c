#include <stdio.h>
#include <unistd.h>

int main() {
  int p[2]; // Arreglo donde almacenaremos los descriptores
  char *argv[2];
  argv[0] = "wc";
  argv[1] = 0;

  pipe(p);
  if (fork() == 0) {
    // El descriptor 0 referenciara al descriptor de lectura de la tuberia
    close(0);
    dup(p[0]);
    
    // Cierra la tuberia
    close(p[0]);
    close(p[1]);
    
    execv("/bin/wc", argv);
  } else {
    close(p[0]); // Cierra el descriptor de lectura

    // Escribe sobre la tuberia y cierra el descriptor de escritura
    write(p[1], "Hello World\n", 12);
    close(p[1]);
  }
}
