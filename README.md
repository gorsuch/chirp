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
$ chirp http://github.com
url=http://github.com ip="192.30.252.128" dns=5.111ms conn=55.179ms first=108.259ms total=108.283ms curl=0 http=301
url=http://github.com ip="192.30.252.128" dns=5.379ms conn=55.110ms first=104.089ms total=104.116ms curl=0 http=301
url=http://github.com ip="192.30.252.128" dns=4.833ms conn=54.578ms first=107.519ms total=107.543ms curl=0 http=301
url=http://github.com ip="192.30.252.128" dns=5.416ms conn=56.470ms first=109.157ms total=109.181ms curl=0 http=301
url=http://github.com ip="192.30.252.128" dns=5.441ms conn=54.098ms first=105.689ms total=105.712ms curl=0 http=301
url=http://github.com ip="192.30.252.128" dns=5.448ms conn=54.911ms first=103.107ms total=103.132ms curl=0 http=301
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
