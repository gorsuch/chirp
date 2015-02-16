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
url=http://www.canary.io ip="23.235.44.133" dns=535.830ms conn=550.206ms first=612.423ms total=618.198ms curl=0 http=200
url=http://www.canary.io ip="23.235.44.133" dns=5.410ms conn=26.736ms first=47.187ms total=49.999ms curl=0 http=200
url=http://www.canary.io ip="23.235.44.133" dns=5.421ms conn=268.909ms first=297.329ms total=302.363ms curl=0 http=200
url=http://www.canary.io ip="23.235.44.133" dns=5.434ms conn=25.101ms first=50.888ms total=58.478ms curl=0 http=200
url=http://www.canary.io ip="23.235.44.133" dns=5.445ms conn=25.878ms first=44.991ms total=63.572ms curl=0 http=200
url=http://www.canary.io ip="23.235.44.133" dns=5.476ms conn=23.278ms first=43.627ms total=46.038ms curl=0 http=200
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
