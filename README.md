## TCP Select in C with objects.

An example of a simple TCP server monitoring multiple ports in a object oriented way.

Using Cmake.

## Dependencies

1. Unix, due to the use of fork. use wsl if on windows
2. gcc or clang

## How to build.

### With Cmake

`mkdir build`

`cd build`

`cmake ..`

`make`

### Without Cmake

`gcc -Wall main.c tcp_connection.c server.c -o server`

## How to run

`./server`

## Test with netcat

`echo "hello from client" || nc localhost 5000`

`echo "hello from client" || nc localhost 5001`
