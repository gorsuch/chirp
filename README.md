curly
=====

A simple http measurement tool based on libcurl.  It takes a single url as an argument and emits JSON on a single line containing allegedly useful metrics.

## Building

```sh
$ make
```

## Running

```sh
$ ./curly http://github.com
{"url": "http://github.com", "connect_time": 0.02845, "exit_status": 0, "starttransfer_time": 0.02845, "t": 1397069414, "local_ip": "107.170.123.131", "primary_ip": "192.30.252.129", "total_time": 0.034930999999999997, "http_status": 301, "namelookup_time": 0.021894, "local_port": 46590}

$ ./curly https://github.com
{"url": "https://github.com", "connect_time": 0.02708, "exit_status": 0, "starttransfer_time": 0.02708, "t": 1397069524, "local_ip": "107.170.123.131", "primary_ip": "192.30.252.129", "total_time": 0.066956000000000002, "http_status": 200, "namelookup_time": 0.020678999999999999, "local_port": 52764}
```
