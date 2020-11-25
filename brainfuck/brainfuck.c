#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024
#define BUFFER_DEPTH 100


int cells[SIZE];
int *cell = &cells[0];

unsigned int stack[BUFFER_DEPTH];
unsigned int *curr, *call = &stack[0];


int exec(FILE *fp) {
	char c;
	while ((c = (char) fgetc(fp)) != EOF) {
		switch (c) {
			case '>':
				++cell;
				break;

			case '<':
				--cell;
				break;

			case '+':
				++(*cell);
				break;

			case '-':
				--(*cell);
				break;

			case '[':
				if (*cell)
                    *(++call) = ftell(fp);
				else {
                    curr = call;
                    while (curr >= call) {
                        c = fgetc(fp);
                        if (c == '[') ++curr;
                        else if (c == ']') --curr;

                        if (c == EOF || curr < stack) {
                            fprintf(stderr, "Error: unmatched brackets\n");
                            return -2;
                        }
                    }
                }
				break;

			case ']':
				if (*cell) fseek(fp, *call, SEEK_SET);
				else --call;
				break;

			case ',':
				scanf("%d", cell);
				break;

			case '.':
				printf("%d\n", *cell);
				break;

			default: break;
		}
	}
    return 0;
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Error: Too few arguments.\n");
		return -1;
	}
	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL) {
		fprintf(stderr, "Error: opening file \"%s\"\n", argv[1]);
		return -1;
	}
	int success = exec(fp);
	fclose(fp);
	return success;
}
