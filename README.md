# CAFFEINE
A Computer Security Project.

## Manual of the parser

### To build (from parser directory):
make

### To run (from parser directory):
./parser.exe <path_to_caff_file>

- For example:

./parser.out samples/1.caff


### To clean up (from parser directory):
make clean

### Notes:

- The program parses the CAFF file that is given as argument.
- The program saves the images located in CIFFs as .bmp files.
- The executable is saved as 'parser.out' or 'parser.exe' depending on the running OS is Linux or Windows.
- We use security countermeasures in Makefile only if the running OS is Linux.
