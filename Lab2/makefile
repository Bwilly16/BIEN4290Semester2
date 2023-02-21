SHELL = /bin/bash
CC = g++
CFLAGS = -fPIC -Wall -g #-std=c++ll 
LDFLAGS = 
LIBS = -lm 
LIBDIR = $(HOME)/BIEN4290Semester2/Lab2/lib #dont have these yet, maybe at all??
INCDIR = $(HOME)/BIEN4290Semester2/Lab2/includes #^^
EXENAME = kmeanTEST

all: wilichowskib_k_means.o #wilichowskib_vector_ops.o wilichowskib_pre_processing.o 	#//first checks these
	$(CC) $(CFLAGS) $? -o $(EXENAME)

# wilichowskib_vector_ops.o: wilichowskib_vector_ops.cpp
# 	$(CC) $(CFLAGS) -c $< $(LIBS)

# wilichowskib_pre_processing.o: wilichowskib_pre_processing.cpp
# 	$(CC) $(CFLAGS) -c $< $(LIBS)

wilichowskib_k_means.o: wilichowskib_k_means.cpp
	$(CC) $(CFLAGS) -c $< $(LIBS)

Clean: wilichowskib_k_means.o #wilichowskib_vector_ops.o wilichowskib_pre_processing.o 
	rm $? $(EXENAME)
