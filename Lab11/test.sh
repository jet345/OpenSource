#!/bin/sh

gcc -c array_list.c
gcc -c point.c
gcc -c main.c

gcc -o lab11 main.o array_list.o point.o point.h array_list.h -lm

rm -rf point.o array_list.o main.o
