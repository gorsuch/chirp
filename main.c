#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include "measurement.h"

json_t * measurement_to_json(struct measurement *m) {
  json_t *json = json_object();

  json_object_set_new(json, "check_id", json_string(m->check_id));
  json_object_set_new(json, "url", json_string(m->url));
  json_object_set_new(json, "t", json_integer(m->t));
  json_object_set_new(json, "exit_status", json_integer(m->exit_status));
  json_object_set_new(json, "http_status", json_integer(m->http_status));
  json_object_set_new(json, "total_time", json_real(m->total_time));
  json_object_set_new(json, "namelookup_time", json_real(m->namelookup_time));
  json_object_set_new(json, "connect_time", json_real(m->connect_time));
  json_object_set_new(json, "starttransfer_time", json_real(m->connect_time));
  json_object_set_new(json, "primary_ip", json_string(m->primary_ip));
  json_object_set_new(json, "local_ip", json_string(m->local_ip));
  json_object_set_new(json, "local_port", json_integer(m->local_port));

  return json;
}

void record(struct measurement *m) {
  json_t *json;
  char * js;

  json = measurement_to_json(m); 
  js = json_dumps(json, 0);
  json_decref(json);

  fprintf(stdout, "%s\n", js);
  free(js);
}

int cycle(void) {
  struct measurement * m;

  m = measure("1", "http://github.com");
  if (m == NULL) {
    fprintf(stderr, "There was an error executing the measurement.\n");
  } else {
    record(m);
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
