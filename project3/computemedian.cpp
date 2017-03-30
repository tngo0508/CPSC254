/*
 * Author: 		Thomas Ngo
 * Email:		tngo0508@csu.fullerton.edu
 * Course:		CPSC254
 * Project #:		3
 * Due date: 		March 20, 2017
 * File name: 		computemedian.cpp	
 * Purpose:		compute the median from data
 * Compilation: 	g++ -c -m64 -Wall -std=c++11 -o computemedian.o computemedian.cpp 
*/

#include <iostream>

using namespace std;

extern "C" double computeMed(int* numOfElem, double* a)
{
	double median;
	int size = *numOfElem;

	if (size  % 2 == 0)
		median = (a[size/2 -1] + a[size/2]) / 2;
	else
		median = a[size/2];
	return median;
}
