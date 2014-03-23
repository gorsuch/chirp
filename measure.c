#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>
#include "measure.h"

/* dummy function that allows us to discard all libcurl output */
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
  return size*nmemb;  
}

struct measurement * measure(char *check_id, char *url)
{
  CURL *curl;
  CURLcode exit_code;
  struct measurement * m;

  curl = curl_easy_init();

  if(curl) {
    m = (struct measurement *) malloc(sizeof(struct measurement));
    m->url = NULL;
    m->check_id = NULL;
    m->t = 0;
    m->exit_status = 0;
    m->http_status = 0;
    m->namelookup_time = 0.0;
    m->connect_time = 0.0;
    m->total_time = 0.0;
    m->starttransfer_time = 0.0;

    m->url = (char *) malloc(strlen(url) + 1);
    strcpy(m->url, url);

    m->check_id = (char *) malloc(strlen(check_id) + 1);
    strcpy(m->check_id, check_id);

    m->t = (unsigned)time(NULL);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.26.0");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    exit_code = curl_easy_perform(curl);
    m->exit_status = exit_code;

    if (exit_code == 0) {
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &m->http_status);
      curl_easy_getinfo(curl, CURLINFO_NAMELOOKUP_TIME, &m->namelookup_time);
      curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &m->connect_time);
      curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &m->total_time);
      curl_easy_getinfo(curl, CURLINFO_STARTTRANSFER_TIME, &m->starttransfer_time);
    }

    curl_easy_cleanup(curl);
    return m;
  }
  return 0;
}

void free_measurement(struct measurement ** m) {
  free((*m)->check_id);
  free((*m)->url);

  free(*m);
}
