#ifndef MEASURE_H
#define MEASURE_H

struct measurement {
  unsigned int t;
  char * url;
  int curl_status;
  long http_status;
  double namelookup_time;
  double total_time;
  double connect_time;
  double starttransfer_time;
  char * primary_ip;
};

struct measurement * take_measurement(char *url);
void free_measurement(struct measurement ** m);
void emit_logfmt(struct measurement *m);
#endif
