#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>
#include "measurement.h"

void emit_measurement(struct measurement *m) {
  fprintf(stdout, "chirp.%s.namelookup_time:%f|ms\n", m->name, m->namelookup_time * 1000);
  fprintf(stdout, "chirp.%s.connect_time:%f|ms\n", m->name, m->connect_time * 1000);
  fprintf(stdout, "chirp.%s.starttransfer_time:%f|ms\n", m->name, m->starttransfer_time * 1000);
  fprintf(stdout, "chirp.%s.total_time:%f|ms\n", m->name, m->total_time * 1000);
  fprintf(stdout, "chirp.%s.http_status.%lu:1|c\n", m->name, m->http_status);
  fprintf(stdout, "chirp.%s.exit_status.%d:1|c\n", m->name, m->exit_status);
}

/* dummy function that allows us to discard all libcurl output */
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
  return size*nmemb;  
}

struct measurement * take_measurement(char *name, char *url)
{
  CURL *curl;
  CURLcode exit_code;
  struct measurement * m;
  char * tmp_primary_ip;
  char * tmp_local_ip;

  curl = curl_easy_init();

  if(curl) {
    m = (struct measurement *) malloc(sizeof(struct measurement));
    m->url = NULL;
    m->t = 0;
    m->exit_status = 0;
    m->http_status = 0;
    m->namelookup_time = 0.0;
    m->connect_time = 0.0;
    m->total_time = 0.0;
    m->starttransfer_time = 0.0;

    m->name = strdup(name);
    m->url = strdup(url);

    m->t = (unsigned)time(NULL);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.26.0");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    exit_code = curl_easy_perform(curl);
    m->exit_status = exit_code;

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &m->http_status);
    curl_easy_getinfo(curl, CURLINFO_NAMELOOKUP_TIME, &m->namelookup_time);
    curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &m->connect_time);
    curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &m->total_time);
    curl_easy_getinfo(curl, CURLINFO_STARTTRANSFER_TIME, &m->starttransfer_time);
    curl_easy_getinfo(curl, CURLINFO_LOCAL_PORT, &m->local_port);

    curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, &tmp_primary_ip);
    m->primary_ip = strdup(tmp_primary_ip);

    curl_easy_getinfo(curl, CURLINFO_LOCAL_IP, &tmp_local_ip);
    m->local_ip = strdup(tmp_local_ip);

    curl_easy_cleanup(curl);
    return m;
  }
  return NULL;
}

void free_measurement(struct measurement ** m) {
  free((*m)->url);
  free((*m)->name);
  free((*m)->primary_ip);
  free((*m)->local_ip);

  free(*m);
}
