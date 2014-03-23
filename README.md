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
$ ./curly 1 http://github.com
{"check_id": "1", "url": "http://github.com", "connect_time": 0.029722999999999999, "exit_status": 0, "starttransfer_time": 0.029722999999999999, "t": 1395595829, "http_status": 301, "total_time": 0.036128, "namelookup_time": 0.022237}
```
