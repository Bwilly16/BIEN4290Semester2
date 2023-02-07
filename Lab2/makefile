SHELL = /bin/bash
CC = g++
CFLAGS = -fPIC -Wall -g #-std=c++ll 
LDFLAGS = 
LIBS = -lm 
LIBDIR = $(HOME)/BIEN4290Semester2/Lab2/lib
INCDIR = $(HOME)/BIEN4290Semester2/Lab2/includes
EXENAME = vectorTEST

all: wilichowskib_vector_ops.o	#//first checks these
	$(CC) $(CFLAGS) $? -o $(EXENAME)

wilichowskib_vector_ops.o: wilichowskib_vector_ops.cpp
	$(CC) $(CFLAGS) -c $< $(LIBS)

Clean: wilichowskib_vector_ops.o
	rm $? $(EXENAME)
