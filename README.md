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
http://www.canary.io 10.0.1.39 23.235.44.133 532.970 548.021 623.744 626.119 0 200
http://www.canary.io 10.0.1.39 23.235.44.133 5.358 33.546 53.215 55.737 0 200
^C
```

## Details

`chirp` emits the following fields that you may or may not find useful:

* `url` - url being measured
* `ip`- ip `chirp` connected to
* `dns` - time taken (in milliseconds) to resolve the `url`
* `conn` - time taken (in milliseconds) to connect to the `url`
* `first` - time taken (in milliseconds) to receive the first byte
* `total` - total time taken (in milliseconds)
* `curl` - `libcurl` return status code
* `http` - http status code
