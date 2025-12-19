#!/bin/bash

set -x

nasm -felf64 -gdwarf lightweight_threads_bcd.asm -o lightweight_threads_bcd.o
ld lightweight_threads_bcd.o -o lightweight_threads_bcd
./lightweight_threads_bcd


