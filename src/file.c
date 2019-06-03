#include <stdio.h>
#include "file.h"
#include "string.h"

short read_file (const char *filename, stroka *str, const short word)
{
	FILE* r = fopen(filename, "r");
	short i = 0, j = 0;
	char c;

	if (r != NULL) {
		while(fscanf(r, "%c", &c) != EOF) {
			switch(c) {
				case ' ':
				case '.':
				case ',':
				case '!':
				case '?':
				case ':':
				case ';':
				case '\n':
					if (j != 0) {
						str[i].slovo[j] = '\0';
						i++;
						j = 0;
					}
				break;
				default:
					str[i].slovo[j] = c;
					j++;
				break;
			}
		}
		fclose(r);
		return 0;
	} else {
		fclose(r);
		return -1;
	}
}

void write_file(const char *filename, const short k, const stroka *str, const short size)
{
	FILE* w = fopen(filename, "w+");
	short i;

	fprintf(w, "Общее количество символов во входном файле: %d\n", k);
	for (i = 0; i < size; i++) {
		fprintf(w, "\n%s = %d", str[i].slovo, str[i].frequency);	
	}
}
