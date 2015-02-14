chirp
=====

A simple http measurement tool based on libcurl.  It takes a single url as an argument and emits measurement data via `logfmt` to `stdout`.

## Building

```sh
$ make install
```

## Running

```sh
$ ./chirp http://www.canary.io
app=chirp url=http://www.canary.io namelookup_time=0.528259 connect_time=0.570642 starttransfer_time=0.647230 total_time=0.664905 ip='23.235.40.133' http_status=200 curl_status=0
app=chirp url=http://www.canary.io namelookup_time=0.005383 connect_time=0.048099 starttransfer_time=0.091759 total_time=0.092648 ip='23.235.40.133' http_status=200 curl_status=0
app=chirp url=http://www.canary.io namelookup_time=0.005461 connect_time=0.048062 starttransfer_time=0.093217 total_time=0.096876 ip='23.235.40.133' http_status=200 curl_status=0
app=chirp url=http://www.canary.io namelookup_time=0.005376 connect_time=0.048695 starttransfer_time=0.097583 total_time=0.101150 ip='23.235.40.133' http_status=200 curl_status=0
app=chirp url=http://www.canary.io namelookup_time=0.005377 connect_time=0.048902 starttransfer_time=0.096214 total_time=0.100840 ip='23.235.40.133' http_status=200 curl_status=0
^C
```
