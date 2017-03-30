/*
 * Author: 	Thomas Ngo
 * Email:	tngo0508@csu.fullerton.edu
 * Course:	CPSC254
 * Project #:	3
 * Due Date:	March 20, 2017
 * File name:	main.c
 * Purpose:	compile other functions and run the program
 * Compilation:	gcc -c -m64 -Wall -std=c99 -o main.o main.c
 * Link: g++ -m64 -o project3.out *.o
*/

#include <stdio.h>
#include <stdlib.h>

long getData(int*, double*);
double sum(double*, int);
double mean(double, int*);
void displayArray(int*, double*);
void sort(int* ,double*);
double computeMed(int*, double*);
double harmonic(int*, double*);

int main()
{
	double* a;
	int* numOfElem = malloc(1 * sizeof(int));
	*numOfElem = 0;
	const int size = 100;
	a = malloc(size * sizeof(double));
	getData(numOfElem, a);

	double* b = malloc(size * sizeof(double));
	for (int i =0; i < *numOfElem; ++i)
	{
		b[i] = a[i];
	}
	printf("\nThank you. The data you entered are\n");
	displayArray(numOfElem, a);

	printf("The following statistics were computed\n");
	double total = 0.0;
	int tempI = *numOfElem;
	total = sum(a, tempI);
	printf("Sum:%33.5f\n", total);

	double meanVar = 0.0;	
	meanVar = mean(total, numOfElem);	
	printf("Arithmetic mean:%21.5f\n",meanVar);

	sort(numOfElem, a);
	double median = 0.0;
	median = computeMed(numOfElem, a);
	printf("Median:%30.5f\n", median);

	double harmonicMean = 0.0;
	harmonicMean = harmonic(numOfElem, a);
	printf("Harmonic mean:%23.5f\n", harmonicMean);
	printf("The sorted data set is:\n");
	displayArray(numOfElem, a);

	printf("The original data set is\n");
	displayArray(numOfElem, b);
	
	printf("Thank you for using this program. Enjoy your statistics.\n");

	free(b);
	free(a);
	free(numOfElem);
	return 0;
}

