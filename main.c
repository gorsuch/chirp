#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check.h"
#include "measurement.h"

int cycle(struct check * c) {
  struct measurement * m;

  m = take_measurement(c->id, c->url);
  if (m == NULL) {
    fprintf(stderr, "There was an error executing the measurement.\n");
  } else {
    emit_measurement(m);
    free_measurement(&m);
  }

  return 0;
}

int main(void) {
  char * line = NULL;
  size_t size;
  struct check * c;

  setbuf(stdout, NULL);

  while(getline(&line, &size, stdin) != -1) { 
    c = stocheck(line);
    if (c == NULL) {
      fprintf(stderr, "error=true message=\"failure processing input\"\n");
    } else {
      cycle(c);
      free_check(&c);
    }
    free(line);
    line = NULL;
  }
}
