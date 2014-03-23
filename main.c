#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "measure.h"

int main(int argc, char * argv[]) {
  char measurement[255];
  int res;

  struct measurement * m;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s [check_id] [url]\n", argv[0]);
    return 1;
  }

  m = measure(argv[1], argv[2]);
  if (m == NULL) {
    fprintf(stderr, "There was an error executing the measurement.\n");
    return 1;
  } else {
    fprintf(stdout, "curl exit status: %d\n", m->exit_status);
  }
}
