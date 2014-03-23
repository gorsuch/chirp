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
    if (m->exit_status == 0) {
      fprintf(stdout, "m 1 %s %d %d %d %f %f %f %f\n", 
          m->check_id,
          m->t,
          m->exit_status,
          m->http_status,
          m->total_time,
          m->namelookup_time,
          m->connect_time,
          m->starttransfer_time);
    } else {
      fprintf(stdout, "m 1 %s %d %d\n",
        m->check_id,
        m->t,
        m->exit_status);
    }
    free_measurement(&m);
  }
}
