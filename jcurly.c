#include <stdio.h>
#include "measure.h"

int main(int argc, char * argv[]) {
  char measurement[255];
  int res;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s [check_id] [url]\n", argv[0]);
    return 1;
  }

  res = measure(argv[1], argv[2], measurement);
  if (res == 0) {
    fprintf(stdout, "%s\n", measurement);
  } else {
    fprintf(stderr, "error: %d\n", res);
  }
}
