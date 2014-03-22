curly
=====

A simple http measurement tool based on libcurl.  It aims to return `msgpack` compatable responses, allowing for easier parsing downstream.

Note that it doesn't actually do much of this right now.

## Building

```sh
$ make
```

## running

```sh
$ ./curly http://github.com
0 301 0.035085 0.022147 0.028620 0.035060
```
