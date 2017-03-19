#!/bin/sh

mkdir -p bin

gcc -c -Wall -Wextra -Wpedantic -O2 -o bin/TCPSocket.o TCPSocket.c

ar rcs bin/libtcpsocket.a TCPSocket.o

gcc -Wall -Wextra -Wpedantic -O2 -DDEBUG TCPSocket.c CarChargerAppl.c -o bin/car_charging_server
