#ifndef MEASURE_H
#define MEASURE_H

struct measurement {
  unsigned int t;
  char * check_id;
  int exit_status;
};

struct measurement * measure(char *check_id, char *url);
void free_measurement(struct measurement ** m);
#endif
