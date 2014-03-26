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
$ ./curly < ./example_input.txt
{"local_port": 52170, "check_id": "1", "url": "http://github.com", "connect_time": 0.027272000000000001, "exit_status": 0, "starttransfer_time": 0.027272000000000001, "t": 1395843894, "http_status": 301, "local_ip": "107.170.123.131", "primary_ip": "192.30.252.131", "total_time": 0.033854000000000002, "namelookup_time": 0.020676}
{"local_port": 43196, "check_id": "2", "url": "http://heroku.com", "connect_time": 0.030127999999999999, "exit_status": 0, "starttransfer_time": 0.030127999999999999, "t": 1395843894, "http_status": 301, "local_ip": "107.170.123.131", "primary_ip": "50.19.85.156", "total_time": 0.038586000000000002, "namelookup_time": 0.021548000000000001}
{"local_port": 37604, "check_id": "3", "url": "https://github.com", "connect_time": 0.028073000000000001, "exit_status": 0, "starttransfer_time": 0.028073000000000001, "t": 1395843894, "http_status": 200, "local_ip": "107.170.123.131", "primary_ip": "192.30.252.128", "total_time": 0.068491999999999997, "namelookup_time": 0.021565999999999998}
```
