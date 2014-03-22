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
$ ./curly 42 http://github.com
m 1 42 0 301 0.035667 0.021982 0.029104 0.035637
```


The response fields map to the following keys:

* `m` - this is a meeasurement
* protocol / response version
* check id
* curl exit code
* http response code
* total time
* name lookup time
* time to connect
* time to first byte
