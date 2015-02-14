#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "measurement.h"

int main(int argc, char * argv[]) {
  struct measurement * m = NULL;

  if (argc < 2) {
    fprintf(stderr, "usage: %s [url]\n", argv[0]);
    exit(1);
  }

  while (1) {
    m = take_measurement(argv[1]);
    emit_measurement(m);
    free_measurement(&m);
    sleep(1);
  }

  return 0;
}
