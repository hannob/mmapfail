#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
  int fd;
  void *m;
  char s[5];

  fd = open("test.txt", O_RDONLY);
  m = mmap(0, 3, PROT_READ, MAP_SHARED, fd, 0);
  if (m == 0) {
    printf("Error!\n");
    return 1;
  }

  memcpy(s, m, 4);
  s[4] = '\0';
  printf("%s\n", s);
}
