#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  chdir("/a");
  chdir("b");
  open("c", O_RDONLY);

  open("/a/b/c", O_RDONLY);
}
