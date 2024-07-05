// Header file for Edge detection
//
// ECE 671 Final project

#ifndef SOBEL_H
#define SOBEL_H

#include <math.h>
#include <stdio.h>
#include "image.h"

//#define DEBUG


// Function to calculate the gradients
void calculateGradients();

#ifdef DEBUG
// A function to write the output results to a file
// Only active in DEBUG configuration
void writeResults(FILE *file);
#endif

#endif
