#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
  // El segundo argumento es el modo (ver inode(7))
  mkdir("/dir", 0700); 
  
  int fd = open("/dir/file", O_CREAT|O_WRONLY);
  close(fd);
  
  mknod("/console", 1, 1);
}
