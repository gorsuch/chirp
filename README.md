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
http://www.canary.io 10.0.1.39 23.235.44.133 32.620 47.580 115.001 121.845 449 13884 0 200
http://www.canary.io 10.0.1.39 23.235.44.133 5.369 28.344 43.201 45.259 448 13884 0 200
http://www.canary.io 10.0.1.39 23.235.44.133 5.438 20.571 36.840 39.781 448 13884 0 200
http://www.canary.io 10.0.1.39 23.235.44.133 5.415 22.419 38.027 41.061 448 13884 0 200
^C
```

## Details

`chirp` emits the following fields that you may or may not find useful:

* url being measured
* ip of the host running chirp
* ip `chirp` connected to
* time taken (in milliseconds) to resolve the `url`
* time taken (in milliseconds) to connect to the `url`
* time taken (in milliseconds) to receive the first byte
* total time taken (in milliseconds)
* header size
* body size
* `curl` - `libcurl` return status code
* `http` - http status code
