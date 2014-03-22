#include <stdio.h>
#include <curl/curl.h>

/* dummy function that allows us to discard all libcurl output */
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
  return size*nmemb;  
}

int measure(char *check_id, char *url, char *measurement)
{
  CURL *curl;
  CURLcode exit_code;
  long *http_code;
  double total_time = 0;
  double connect_time = 0;
  double namelookup_time = 0;
  double starttransfer_time = 0;
  int protocol = 1;

  curl = curl_easy_init();

  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.26.0");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    exit_code = curl_easy_perform(curl);

    if(exit_code == CURLE_OK) {
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
      curl_easy_getinfo(curl, CURLINFO_NAMELOOKUP_TIME, &namelookup_time);
      curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &connect_time);
      curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &total_time);
      curl_easy_getinfo(curl, CURLINFO_STARTTRANSFER_TIME, &starttransfer_time);

      sprintf(measurement, "m %d %s %d %d %f %f %f %f", protocol, check_id, exit_code, http_code, total_time, namelookup_time, connect_time, starttransfer_time);
    } else {
      sprintf(measurement, "m %d %d", protocol, check_id, exit_code);
    }

    curl_easy_cleanup(curl);
  }
  return 0;
}
