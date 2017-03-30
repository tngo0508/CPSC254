/*
 * Author: 		Thomas Ngo
 * Email:		tngo0508@csu.fullerton.edu
 * Course:		CPSC254
 * Project #:		3
 * Due date: 		March 20, 2017
 * File name: 		computemean.cpp	
 * Purpose:		compute the mean from data	
 * Compilation: 	g++ -c -m64 -Wall -std=c++11 -o computemean.o computemean.cpp
*/

#include <iostream>

extern "C" double mean(double sum, int* numOfElem)
{
	return (sum / *numOfElem);
}

