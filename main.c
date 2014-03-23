#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include "measure.h"

void report(struct measurement *m) {
  json_t *json = json_object();
  char * js;

  json_object_set_new(json, "check_id", json_string(m->check_id));
  json_object_set_new(json, "url", json_string(m->url));
  json_object_set_new(json, "t", json_integer(m->t));
  json_object_set_new(json, "exit_status", json_integer(m->exit_status));

  if (m->exit_status == 0) {
    json_object_set_new(json, "http_status", json_integer(m->http_status));
    json_object_set_new(json, "total_time", json_real(m->total_time));
    json_object_set_new(json, "namelookup_time", json_real(m->namelookup_time));
    json_object_set_new(json, "connect_time", json_real(m->connect_time));
    json_object_set_new(json, "starttransfer_time", json_real(m->connect_time));

    js = json_dumps(json, 0);
    fprintf(stdout, "%s\n", js);
  } else {
    js = json_dumps(json, 0);
    fprintf(stdout, "%s\n", js);
  }
  free(js);
  json_decref(json);
}

int main(int argc, char * argv[]) {
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
    report(m);
    free_measurement(&m);
  }
}
