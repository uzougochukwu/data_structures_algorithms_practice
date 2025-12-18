#!/bin/bash

set -x

nasm -felf64 -gdwarf fixprintf.asm -o fixprintf.o

ld fixprintf.o -o fixprintf

./fixprintf




