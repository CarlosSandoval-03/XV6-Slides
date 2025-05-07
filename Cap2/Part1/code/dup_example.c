#include <stdio.h>
#include <unistd.h>

int main() {
  int fd = dup(1);
  write(fd, "Hello", 6);
  write(fd, " World\n", 8);
  
  return 0;
}
