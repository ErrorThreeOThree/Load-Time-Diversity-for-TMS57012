This project evaluates the entropy of the MIS reodering algorithm. It outputs CSV data to the console with the relative probability for the position of the first MIS for each Byte in memory. The user program is currently set to the bubble_sort example. One can scale up the program by providing an MIS scale factor.

To compile this project, use the following command:
`gcc main.c rand.c -Wall -o entropy`

The ods files contain the pipped output for 50000 iterations.

Usage:
`./entropy #ITERATIONS MIS_SCALE_FACTOR >> measurement.csv`
