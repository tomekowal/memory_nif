#include <stdio.h>
#include <unistd.h>

int get_memory(int pid) {
  int vsize;
  char dummy[256];
  char pid_string[16];
  sprintf(pid_string, "%d", pid);
  FILE *input;
  input = NULL;

  chdir("/proc");
  if(chdir(pid_string) == 0) { input = fopen("stat", "r"); }
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
