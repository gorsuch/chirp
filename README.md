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
url=http://www.canary.io ip=23.235.40.133 dns=4.946ms conn=46.775ms first=90.391ms total=91.542ms curl=0 http=200
url=http://www.canary.io ip=23.235.40.133 dns=5.460ms conn=48.167ms first=90.811ms total=92.922ms curl=0 http=200
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
