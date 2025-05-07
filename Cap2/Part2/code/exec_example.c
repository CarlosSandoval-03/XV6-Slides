#include <stdio.h>
#include <unistd.h>

int main() {
  char *argv[3];
  argv[0] = "echo";
  argv[1] = "hello";
  argv[2] = 0;

  execv("/bin/echo", argv);
  printf("Error de ejecucion\n");
  return 0;
}
