#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <hiredis/hiredis.h>
#include "measure.h"

void stdout_report(struct measurement *m) {
  json_t *json = json_object();
  char * js;

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

  js = json_dumps(json, 0);
  fprintf(stdout, "%s\n", js);

  free(js);
  json_decref(json);
}

void redis_report(redisContext *c, struct measurement *m) {
  redisReply *reply;
  reply = redisCommand(c,"PING");
  freeReplyObject(reply);
}

int cycle(redisContext *c) {
  struct measurement * m;

  m = measure("1", "http://github.com");
  if (m == NULL) {
    fprintf(stderr, "There was an error executing the measurement.\n");
  } else {
    stdout_report(m);
    redis_report(c, m);
    free_measurement(&m);
  }

  return 0;
}

int main(int argc, char * argv[]) {
  redisContext *c;

  c = redisConnect("localhost", 6379);
  if (c == NULL | c->err) {
    if (c) {
      printf("Redis Connection error: %s\n", c->errstr);
      redisFree(c);
    } else {
      printf("Redis Connection error: can't allocate redis context\n");
    }
    exit(1);
  }

  while (1) {
    cycle(c);
    sleep(1);
  }

  redisFree(c);
}
