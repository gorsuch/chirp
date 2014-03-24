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
{"local_port": 48293, "check_id": "1", "url": "http://github.com", "connect_time": 0.027161999999999999, "exit_status": 0, "starttransfer_time": 0.027161999999999999, "t": 1395628942, "http_status": 301, "local_ip": "107.170.123.131", "primary_ip": "192.30.252.131", "total_time": 0.033564999999999956, "namelookup_time": 0.020768999999999999}
{"local_port": 48294, "check_id": "1", "url": "http://github.com", "connect_time": 0.028008999999999999, "exit_status": 0, "starttransfer_time": 0.028008999999999999, "t": 1395628943, "http_status": 301, "local_ip": "107.170.123.131", "primary_ip": "192.30.252.131", "total_time": 0.034387000000000001, "namelookup_time": 0.021642999999999999}
{"local_port": 48295, "check_id": "1", "url": "http://github.com", "connect_time": 0.028565, "exit_status": 0, "starttransfer_time": 0.028565, "t": 1395628944, "http_status": 301, "local_ip": "107.170.123.131", "primary_ip": "192.30.252.131", "total_time": 0.034819999999999997, "namelookup_time": 0.022290999999999998}
```
