/*
 * Author: 		Thomas Ngo
 * Email:		tngo0508@csu.fullerton.edu
 * Course:		CPSC254
 * Project #:		3
 * Due date: 		March 20, 2017
 * File name: 		getdata.c
 * Purpose:		get the inputs from user
 * Compilation: 	gcc -c -m64 -Wall -std=c99 -o getdata.o getdata.c
*/

#include <stdio.h>
#include <stdlib.h>

long getData(int* numOfElem, double* a)
{
	printf("Welcome to Data Analysis by Thomas Ngo\n");
	printf("This program will compute certain statistical values.\n");
	printf("Please enter floating point data.\n");
	printf("After the last number has been entered press Ctrl + D.\n");
	double n = 0.0;
	int i = 0;
	int code = 0;

	code = scanf("%lf", &n);
	while (code != EOF)
	{
		a[i] = n;
		(*numOfElem)++;
		i++;
		code = scanf("%lf", &n);
	}

	return 0;
}
