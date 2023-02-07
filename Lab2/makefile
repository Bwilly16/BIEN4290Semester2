SHELL = /bin/bash
CC = g++
CFLAGS = -fPIC -Wall -std=c++ll -g
LDFLAGS = 
LIBS = -lm 
LIBDIR = $(HOME)/BIEN4290/lib
INCDIR = $(HOME)/BIEN4290/includes
EXENAME = “vectorTEST”

all: wilichowskib_vector_ops.o	//first checks these
	$(CC) $(CFLAGS) $? -o $(EXENAME)

wilichowskib_vector_ops.o: wilichowskib_vector_ops.c
	$(CC) $(CFLAGS) -c $< $(LIBS)

Clean: wilichowskib_vector_ops.o
	rm $? $(EXENAME)
