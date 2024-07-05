// Sobel.c - uses the sobel operator to find edges
//
// ECE 671 Final project

#include "Sobel.h"

// Variables for x and 8 gradients
float Gx[IM_HEIGHT][IM_WIDTH];
float Gy[IM_HEIGHT][IM_WIDTH];

// Variable for magnitude of gradient
char edges[IM_HEIGHT][IM_WIDTH];

void calculateGradients() {
	// loop variables
	int i, j;
	
	// zero out the edges
	for (i = 0; i<IM_HEIGHT; i++) {
		Gx[i][0] = 0;
		Gx[i][IM_WIDTH-1] = 0;
		Gy[i][0] = 0;
		Gy[i][IM_WIDTH-1] = 0;
	}
	for (j = 0; j<IM_WIDTH; j++) {
		Gx[0][j] = 0;
		Gx[IM_HEIGHT-1][j] = 0;
		Gy[0][j] = 0;
		Gy[IM_HEIGHT-1][j] = 0;
	}
	
	// Apply the Sobel operator to the image
	for (i = 1; i<IM_HEIGHT-1; i++) {
		for (j = 1; j<IM_WIDTH-1; j++) {
			Gx[i][j] = (float)(origImg[i-1][j-1] + 2*origImg[i][j-1] + origImg[i+1][j-1]
				- origImg[i-1][j+1] - 2*origImg[i][j+1] + origImg[i+1][j+1]) / 8.0;
				
			Gy[i][j] = (float)(origImg[i-1][j-1] + 2* origImg[i-1][j] + origImg[i-1][j-1]
				- origImg[i+1][j+1] - 2*origImg[i+1][j] + origImg[i+1][j+1]) / 8.0;

			// And calculate the magnitude of the gradient
			edges[i][j] = (int)sqrt(Gx[i][j] * Gx[i][j] + Gy[i][j] * Gy[i][j]);
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