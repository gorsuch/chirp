#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "measurement.h"

int main(int argc, char * argv[]) {
  struct measurement * m = NULL;

  if (argc < 3) {
    fprintf(stderr, "usage: %s [name] [url]\n", argv[0]);
    exit(1);
  }

  while (1) {
    m = take_measurement(argv[1], argv[2]);
    emit_measurement(m);
    free_measurement(&m);
    sleep(1);
  }

  return 0;
}
