// Sobel.c - uses the sobel operator to find edges
//
// ECE 671 Final project
// Modified for memory constraints on Arduino

#include "Sobel.h"

// Variables for x and y gradients
float Gx;
float Gy;

// Variable for magnitude of gradient
char edge;

void calculateGradients() {
	// loop variables
	int i, j;
	

		
	// Apply the Sobel operator to the image
	for (i = 1; i<IM_HEIGHT-1; i++) {
		for (j = 1; j<IM_WIDTH-1; j++) {
			Gx = (float)(origImg[i-1][j-1] + 2*origImg[i][j-1] + origImg[i+1][j-1]
				- origImg[i-1][j+1] - 2*origImg[i][j+1] + origImg[i+1][j+1]) / 8.0;
				
			Gy = (float)(origImg[i-1][j-1] + 2* origImg[i-1][j] + origImg[i-1][j-1]
				- origImg[i+1][j+1] - 2*origImg[i+1][j] + origImg[i+1][j+1]) / 8.0;
				
			edge = (int) sqrt(Gx*Gx + Gy*Gy);
		}
	}
}	

#ifdef DEBUG
// A function to write the output results to a file
void writeResults(FILE *file) {
	// looping variables
	int i, j;
	for (i = 1; i < IM_HEIGHT - 1; i++) {
		for (j = 1; j < IM_WIDTH - 1; j++) {
			fprintf(file, "%d,", (int)(edges[i][j]));
		}
		fprintf(file, "\n");
	}
}
#endif