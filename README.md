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
$ ./curly http://github.com
m 1 0 301 0.035085 0.022147 0.028620 0.035060
```


The response fields map to the following keys:

* `m` - this is a meeasurement
* protocol / response version
* curl exit code
* http response code
* total time
* name lookup time
* time to connect
* time to first byte
