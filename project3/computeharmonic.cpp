/*
 * Author: 		Thomas Ngo
 * Email:		tngo0508@csu.fullerton.edu
 * Course:		CPSC254
 * Project #:		3
 * Due date: 		March 20, 2017
 * File name: 		computeharmonic.cpp	
 * Purpose:		compute the harmonic mean from data
 * Compilation: 	g++ -c -m64 -Wall -std=c++11 -o computeharmonic.o computeharmonic.cpp 
*/

#include <iostream>

using namespace std;

extern "C" double harmonic(int* numOfElem, double* a)
{
	double sum = 0.0;
	for (int i = 0; i < *numOfElem; ++i)
	{
		sum += 1/a[i];
	}

	return *numOfElem/sum;
}
