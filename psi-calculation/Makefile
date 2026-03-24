CC=g++

CFLAGS=-c -g -Wall `root-config --cflags`

LDFLAGS=`root-config --glibs`

all: psi_truth

psi_truth: psi_truth.cc
		$(CC) $(CFLAGS) -o psi_truth.o psi_truth.cc
		$(CC) $(LDFLAGS) -o psi_truth psi_truth.o
