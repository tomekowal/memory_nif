#include <stdio.h>
#include <unistd.h>

int get_memory(int pid) {
  int vsize;
  char dummy[256];
  char path_string[16];
  sprintf(path_string, "/proc/%d/stat", pid);
  FILE *input;
  input = NULL;

  input = fopen(path_string, "r");
  if(!input) {
    perror("open");
    return 0;
  }

  int i;
  for (i=0; i<22; i++) {
    fscanf(input, "%s ", dummy);
  }
  fscanf(input, "%d ", &vsize);

  return vsize;
}
