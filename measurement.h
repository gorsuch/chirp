#ifndef MEASURE_H
#define MEASURE_H

struct measurement {
  unsigned int t;
  char * url;
  int curl_status;
  long http_status;
  long header_size;
  double size_download;
  double namelookup_time;
  double total_time;
  double connect_time;
  double starttransfer_time;
  char * local_ip;
  char * primary_ip;
};

struct measurement * take_measurement(char *url);
void free_measurement(struct measurement ** m);
void emit(struct measurement *m);
#endif
