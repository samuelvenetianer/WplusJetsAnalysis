CC=g++

CFLAGS=-c -g -Wall `root-config --cflags`

LDFLAGS=`root-config --glibs`

all: validation

validation: validation.cc
		$(CC) $(CFLAGS) -o validation.o validation.cc
		$(CC) $(LDFLAGS) -o validation validation.o