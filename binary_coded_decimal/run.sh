#!/bin/bash
set -x
nasm -felf64 -gdwarf decimal-to-bcd-register.asm -o decimal-to-bcd-register.o

ld decimal-to-bcd-register.o -o decimal-to-bcd-register

./decimal-to-bcd-register
