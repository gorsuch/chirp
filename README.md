curly
=====

A simple http measurement tool based on libcurl.  It aims to return `msgpack` compatable responses, allowing for easier parsing downstream.

Note that it doesn't actually do much of this right now.

## Building

```sh
$ make
```

## Running

```sh
$ ./curly
{"check_id": "1", "url": "http://github.com", "connect_time": 0.027369000000000001, "exit_status": 0, "starttransfer_time": 0.027369000000000001, "t": 1395606698, "http_status": 301, "total_time": 0.034025, "namelookup_time": 0.020922}
{"check_id": "1", "url": "http://github.com", "connect_time": 0.028160999999999999, "exit_status": 0, "starttransfer_time": 0.028160999999999999, "t": 1395606699, "http_status": 301, "total_time": 0.034594, "namelookup_time": 0.021714000000000001}
{"check_id": "1", "url": "http://github.com", "connect_time": 0.026891999999999999, "exit_status": 0, "starttransfer_time": 0.026891999999999999, "t": 1395606700, "http_status": 301, "total_time": 0.033193, "namelookup_time": 0.020537}
^C
```
