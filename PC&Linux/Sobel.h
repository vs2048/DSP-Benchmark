// Header file for Edge detection
//
// ECE 671 Final project

#ifndef SOBEL_H
#define SOBEL_H

#include <math.h>
#include <stdio.h>
#include "image.h"

//#define DEBUG

// Variables for x and 8 gradients
extern float Gx[IM_HEIGHT][IM_WIDTH];
extern float Gy[IM_HEIGHT][IM_WIDTH];

// Variable for magnitude of gradient
extern char edges[IM_HEIGHT][IM_WIDTH];

// Function to calculate the gradients
void calculateGradients();

#ifdef DEBUG
// A function to write the output results to a file
// Only active in DEBUG configuration
void writeResults(FILE *file);
#endif

#endif