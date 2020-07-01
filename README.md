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

`gcc -Wall main.c tcp_connection.c server.c InputParser.c -o server`

## How to run

`./server`

## config.txt

The `config.txt` file is parsed on start up. It defines a server by starting a line with **server**. It then reads in a **topic** to be used later with kafka, **port** and a **host**. currently only port is being used. You can define as many servers as you want, as long as the port is free this server will listen on each port defined in the config file. 


## Test with netcat

`echo "hello from client" || nc localhost 5002`

`echo "hello from client" || nc localhost 5001`
