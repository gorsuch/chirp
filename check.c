#include <stdio.h>
#include <string.h>
#include <jansson.h>

#include "check.h"

struct check * stocheck(char * s) {
  json_t *root;
  json_error_t error;
  struct check * c;
  json_t *id, *url;

  root = json_loads(s, 0, &error);

  if(!root) {
    return NULL;
  }

  c = (struct check *) malloc(sizeof(struct check *));

  c->id = strdup(json_string_value(json_object_get(root, "id")));
  c->url = strdup(json_string_value(json_object_get(root, "url")));

  json_decref(root);

  return c;  
}

void free_check(struct check ** c) {
  free((*c)->id);
  free((*c)->url);
  c = NULL;
}
