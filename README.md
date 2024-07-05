# DSP-Benchmark
This is my final project in my DSP class. I benchmarked running the Sobel Operator for edge detection on a series of processors including two Windows machines, Raspberry Pis, an Arduino Uno, and a Ti DSP embedded processor.
To reduce library dependencies there is a MATLAB script to read the image and write it in an C header file as a character array representing the brightness of each pixel. The Arduino had so little memory that the resulting image could not be stored.
The average time to process one frame for each architecture is in the table below.
| Architecture | Execution Time (ms) |
| ---------------- | -----------------------|
| Intel I5-6500 | 1.77 |
| Intel I5-6200u| 2.15 |
| Arm Cortex-A53 (Pi3) | 118 |
| Arm Cortex-A7 (Pi2) | 193 |
| TI C6713 DSP | 399 |
| ATMega 328 (Arduino Uno) | 20490 |
