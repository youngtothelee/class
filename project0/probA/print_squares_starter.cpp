#include <stdio.h>
#include <stdlib.h>

int readNum(double* r_number) {
	static FILE* file = NULL;						// remember opened file

	if (file == NULL) {
		file = fopen("numbers.txt", "r");			// open file for reading
		if (file == NULL) {							// check if actually opened
			printf("unable to open file\n");
			abort();
		}
	}

	int counter = fscanf(file, "%lf", r_number);	// read one number

	return (counter != EOF);						// say if at end of file or not
}

void printSquare(double dbl) {
 int i = dbl;
 printf("%d squared is %d\n", i, i*i);
}

int main(void) {
	double number;
	while (readNum(&number)) {
		printSquare(number);
	}
}	
