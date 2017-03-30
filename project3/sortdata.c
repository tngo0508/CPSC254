/*
 * Author: 		Thomas Ngo
 * Email:		tngo0508@csu.fullerton.edu
 * Course:		CPSC254
 * Project #:		3
 * Due date: 		March 20, 2017
 * File name: 		sortdata.c	
 * Purpose:		sort the elements in the array in ascending order	
 * Compilation: 	gcc -c -m64 -Wall -std=c99 -o sortdata.o sortdata.c 
*/

#include <stdio.h>

void sort(int* numOfElem, double* a)
{
	int i, j;
	double temp = 0.0;
	for (i = 0; i < *numOfElem-1; ++i)
	{
		for (j = 0; j < *numOfElem-i-1; ++j)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
