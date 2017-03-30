#!bin/bash
#Author: 	Thomas Ngo
#Email:		tngo0508@csu.fullerton.edu	
#Course: 	CPSC254
#Project #:	3
#Due date:	March 20, 2017
#File name:	project3.sh

echo script file for Project3 begin
rm *.o
rm *.out

echo compile getData.c
gcc -c -m64 -Wall -std=c99 -o getdata.o getdata.c

echo compile computemean.cpp
g++ -c -m64 -Wall -std=c++11 -o computemean.o computemean.cpp

echo compile computesum.asm
nasm -f elf64 -l computesum.list -o computesum.o computesum.asm

echo compile sortdata.c
gcc -c -m64 -Wall -std=c99 -o sortdata.o sortdata.c

echo compile display.c
gcc -c -m64 -Wall -std=c99 -o display.o display.c

echo compile computemedian.cpp
g++ -c -m64 -Wall -std=c++11 -o computemedian.o computemedian.cpp

echo compile computeharmonicmean.cpp
g++ -c -m64 -Wall -std=c++11 -o computeharmonic.o computeharmonic.cpp

echo compile main.c
gcc -c -m64 -Wall -std=c99 -o main.o main.c

echo now link the *.o files
g++ -m64 -o project3.out *.o

echo finished.
