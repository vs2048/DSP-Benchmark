// Final_EdgeDetect.cpp : Defines the entry point for the console application.
//
// The desktop program that will run and time an edge detection algorithm and append the 
// results to a text file.

#include <stdio.h>
#include <time.h>

#include "Sobel.h"

#define NUMTESTS 100

int RunPerf()
{
	double elapsedTime, freq;	//Ms and KHz
	int i;

	// Start timing
	clock_t start, end;
	printf("Starting... ");
	start = clock();

	// Run the edge detection code
	for (i = 0; i < NUMTESTS; i++) {
		calculateGradients();
	}

	// End timing and calculate time in MS and frequency
	end = clock();
	
	elapsedTime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
	freq = NUMTESTS / elapsedTime;

	printf("done!\n");
	printf("Count:\t%d\tElapsed(ms):\t%f\tSingle time(ms):\t%fms\tFrequecy(KHz):\t%f\n",
		NUMTESTS, elapsedTime, elapsedTime/NUMTESTS, freq);

	// If in debug mode write the output
#ifdef DEBUG
	FILE* debugFile = fopen("edges.csv", "w");
	writeResults(debugFile);
	fclose(debugFile);
#endif

	// Append latest results to PCPerf.txt
	FILE* out = fopen("PCPerf.txt", "a");
	fprintf(out, "Count:\t%d\tElapsed(ms):\t%f\tSingle time(ms):\t%f\tFrequecy(KHz):\t%f\n",
		NUMTESTS, elapsedTime, elapsedTime / NUMTESTS, freq);
	fclose(out);

    return 0;
}

int main() {
	return RunPerf();
}