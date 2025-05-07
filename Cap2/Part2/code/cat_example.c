#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
  char *argv[2];
  argv[0] = "cat";
  argv[1] = 0;

  if (fork() == 0) {
    close(0); // Se libera el descriptor 0 (entrada estandar)
    
    // Se abre el archivo del cual leeremos el mensaje este tendra asignado
    // el descriptor mas bajo posible, en este caso 0.
    open("input.txt", O_RDONLY); 
    execv("/bin/cat", argv);
  }
}
