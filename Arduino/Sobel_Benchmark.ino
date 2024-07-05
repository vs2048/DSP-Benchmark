// Sobel_Benchmark.ino
// Main file for Sobel operator benchmark

#include "Sobel.h"
#include <stdio.h>
#include "LiquidCrystal.h"

LiquidCrystal lcd(9, 10, 7, 8, 12, 13);

#define START_PIN 3
#define NUMTESTS 100

unsigned long start;
unsigned long stop;
int time;
char line[16];

void setup() {
	// Initialize IO
	pinMode(START_PIN, INPUT_PULLUP);
	lcd.begin(16, 2);
	
	// Display message
	lcd.clear();
	lcd.write("Sobel Benchmark");
	lcd.setCursor(0,1);
	lcd.write("ECE671 VSamokhin");
}

void loop() {
	char i;
	// If the button is pressed run the benchmark
	if(digitalRead(START_PIN) == 0) {
		// Clear the LCD and write status
		lcd.clear();
		lcd.write("Running...");
		
		// start timing
		start = millis();
		
		// Run the tests
		for(i=0; i<NUMTESTS; i++) {
			calculateGradients();
		}
		// Stop timing
		stop = millis();
		lcd.write("done!");
		
		// Calcualte the time
		time = (float) (stop - start);
		
		// Print the results
		lcd.clear();
		sprintf(line, "Time: %dms", time);
		lcd.write(line);
		
	}

}
