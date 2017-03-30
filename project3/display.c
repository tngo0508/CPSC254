/*
 * Author: 		Thomas Ngo
 * Email:		tngo0508@csu.fullerton.edu
 * Course:		CPSC254
 * Project #:		3
 * Due date: 		March 20, 2017
 * File name: 		display.c	
 * Purpose:		display the data in an array	
 * Compilation: 	gcc -c -m64 -Wall -std=c99 -o display.o display.c 
*/

#include <stdio.h>

void displayArray(int* numOfElem, double* a)
{
	int i;
	for (i = 0; i < (*numOfElem); i++)
	{
		printf("%20.5f\n",a[i]);
	}	
}
