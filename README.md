## TCP Select in C with objects.

An example of a simple TCP server monitoring multiple ports in a object oriented way.

Using Cmake.

## How to build.

`mkdir build`

`cmake ..`

`./server`

## Test with netcat

`echo "hello from client" || localhost 5000`

`echo "hello from client" || localhost 5001`