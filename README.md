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
$ ./curly 123 http://github.com
m 1 123 1395583688 0 301 0.035355 0.022038 0.028698 0.035329
```


The response fields map to the following keys:

* `m` - this is a meeasurement
* protocol / response version
* check id
* epoch timestamp
* curl exit code
* http response code
* total time
* name lookup time
* time to connect
* time to first byte
