#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "measurement.h"

int cycle(void) {
  struct measurement * m;

  m = take_measurement("1", "http://github.com");
  if (m == NULL) {
    fprintf(stderr, "There was an error executing the measurement.\n");
  } else {
    emit_measurement(m);
    free_measurement(&m);
  }

  return 0;
}

int main(int argc, char * argv[]) {
  while (1) {
    cycle();
    sleep(1);
  }
}
