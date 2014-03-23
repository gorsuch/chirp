#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "measure.h"
#include <jansson.h>

int main(int argc, char * argv[]) {
  int res;
  struct measurement * m;
  json_t *json = json_object();
  char * js;

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
      json_object_set_new(json, "check_id", json_string(m->check_id));
      json_object_set_new(json, "url", json_string(m->url));
      json_object_set_new(json, "t", json_integer(m->t));
      json_object_set_new(json, "exit_status", json_integer(m->exit_status));
      json_object_set_new(json, "http_status", json_integer(m->http_status));
      json_object_set_new(json, "total_time", json_real(m->total_time));
      json_object_set_new(json, "namelookup_time", json_real(m->namelookup_time));
      json_object_set_new(json, "connect_time", json_real(m->connect_time));
      json_object_set_new(json, "starttransfer_time", json_real(m->connect_time));

      js = json_dumps(json, 0);

      fprintf(stdout, "%s\n", js);
    } else {
      fprintf(stdout, "m 1 %s %d %d\n",
        m->check_id,
        m->t,
        m->exit_status);
    }
    free_measurement(&m);
    free(js);
    json_decref(json);
  }
}
