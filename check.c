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

  id = json_object_get(root, "id");
  if(!json_is_string(id)) {
    json_decref(root);
    return NULL; 
  }

  url =json_object_get(root, "url");
  if(!json_is_string(url)) {
    json_decref(root);
    return NULL; 
  }

  c->id = (char *) malloc(strlen(json_string_value(id)));
  strcpy(c->id, json_string_value(id));

  c->url = (char *) malloc(strlen(json_string_value(url)));
  strcpy(c->url, json_string_value(url));

  json_decref(root);

  return c;  
}

void free_check(struct check ** c) {
  free((*c)->id);
  free((*c)->url);
  c = NULL;
}
