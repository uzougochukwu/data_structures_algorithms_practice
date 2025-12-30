#!/bin/bash

set -x

nasm -felf64 -gdwarf printf-for-threads.asm -o printf-for-threads.o
ld printf-for-threads.o -o printf-for-threads
./printf-for-threads
