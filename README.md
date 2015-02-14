chirp
=====

A simple http measurement tool based on libcurl.  It takes a single url as an argument and emits measurement data via `logfmt` to `stdout`.

## Building

```sh
$ make install
```

## Running

```sh
$ chirp http://www.canary.io
app=chirp url=http://www.canary.io namelookup_time=35.510000 connect_time=78.405000 starttransfer_time=125.397000 total_time=132.465000 ip='23.235.40.133' http_status=200 curl_status=0
app=chirp url=http://www.canary.io namelookup_time=5.382000 connect_time=48.357000 starttransfer_time=95.787000 total_time=96.846000 ip='23.235.40.133' http_status=200 curl_status=0
app=chirp url=http://www.canary.io namelookup_time=5.439000 connect_time=48.520000 starttransfer_time=94.670000 total_time=96.132000 ip='23.235.40.133' http_status=200 curl_status=0
app=chirp url=http://www.canary.io namelookup_time=5.455000 connect_time=48.943000 starttransfer_time=91.390000 total_time=95.463000 ip='23.235.40.133' http_status=200 curl_status=0
^C
```
