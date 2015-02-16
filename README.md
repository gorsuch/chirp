chirp
=====

A simple http measurement tool based on libcurl.  It takes a single url as an argument and emits timestamped, columnar measurement data to `stdout`.

## Goals

* ping, but for http
* be small
* be unsurprising
* be composable

## Building

```sh
$ make install
```

## Running

```sh
$ chirp http://www.canary.io
1424107725 http://www.canary.io 10.0.1.39 23.235.44.133 31.492 50.288 115.498 117.325 449 13884 0 200
1424107726 http://www.canary.io 10.0.1.39 23.235.44.133 5.419 22.581 39.062 42.888 448 13884 0 200
1424107727 http://www.canary.io 10.0.1.39 23.235.44.133 5.383 20.985 40.595 43.136 448 13884 0 200
1424107728 http://www.canary.io 10.0.1.39 23.235.44.133 5.410 19.897 38.481 39.913 448 13884 0 200
^C
```

## Details

`chirp` emits the following fields for consumption:

* timestamp
* url being measured
* ip of the host running `chirp`, returns `n/a` if unavailable
* ip `chirp` connected to, return `n/a` if unavailable
* time taken (in milliseconds) to resolve the `url`
* time taken (in milliseconds) to connect to the `url`
* time taken (in milliseconds) to receive the first byte
* total time taken (in milliseconds)
* header size
* body size
* `curl` - `libcurl` return status code
* `http` - http status code
