/** Shopatron.com Code Contest
 * @author Ryan Sundberg (rsundber@calpoly.edu)
 * @version 9-30-2011
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void printSequence(int begin);

int main(int argc, char* argv[]) {
	int input;
	char *end;

	if(argc == 2) {
		errno = 0;
		input = strtol(argv[1], &end, 10);
		if(*end == '\0' && errno == 0) {
			if(input >= 1 && input <= 99) {
				printSequence(input);
				return EXIT_SUCCESS;
			}
			else {
				printf("Number is out of range (1-99).\n");
			}
		}
		else {
			printf("Input is not a valid number.\n");
		}
	}
	else {
		printf("Invalid command line.\n");
	}
	return EXIT_FAILURE;
}

/** Print the sequence starting at the input number
 * @pre 1 <= begin <= 99
 */
void printSequence(int begin) {
	// Pre-calculated table of word lengths */
	int wordLengths[] = {
		3, 3, 5, 4, 4, 3, 5, 5, 4, 3, // 1-10
		6, 6, 8, 8, 7, 7, 9, 8, 8, 6, // 11-20
		9, 9, 11, 10, 10, 9, 11, 11, 10, 6, // 21-30
		9, 9, 11, 10, 10, 9, 11, 11, 10, 6, // 31-40
		9, 9, 11, 10, 10, 9, 11, 11, 10, 5, // 41-50
		8, 8, 10, 9, 9, 8, 10, 10, 9, 5, // 51-60
		8, 8, 10, 9, 9, 8, 10, 10, 9, 7, // 61-70
		10, 10, 12, 11, 11, 10, 12, 12, 11, 6, // 71-80
		9, 9, 11, 10, 10, 9, 11, 11, 10, 6, // 81-90
		9, 9, 11, 10, 10, 9, 11, 11, 10}; // 91-99
	
	int res = begin, lastRes = 0;

	printf("%d", begin);

	while(!(lastRes == 4 && res == 4)) {
		lastRes = res;
		res = wordLengths[res-1];		
		printf(" -> %d", res);
	}

	printf("\n");
}


