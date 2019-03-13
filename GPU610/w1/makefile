# Makefile for w1
#
 GCC_VERSION = 7.2.0
 PREFIX = /usr/local/gcc/${GCC_VERSION}/bin/
 CC = ${PREFIX}gcc
 CPP = ${PREFIX}g++

w1: w1.o
	$(CPP) -pg -ow1 w1.o

w1.o: w1.cpp
	$(CPP) -c -O2 -g -pg -std=c++0x w1.cpp
clean:
	rm *.o
                          
