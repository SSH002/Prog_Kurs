#include <stdio.h>
#include "string.h"
#include "count.h"

short char_count (const char *filename)
{
        FILE* f = fopen(filename, "r");
       	short count = 0;
        char c;

        while (fscanf(f, "%c", &c) != EOF) {
               	count++;
        }

        fclose(f);
        return count;
}

short word_count (const char *filename)
{
       	FILE* f = fopen(filename, "r");
        short count = 0;
       	char c;

        while (fscanf(f, "%c", &c) != EOF) {
               	if ((c == ' ') || (c == '\n')) {
                       	count++;
                }
        }

        fclose(f);
        return count;
}

short match_count (stroka *str, stroka *str2, const short size)
{
	short i, j, k = 0, check, count = 0;
	char buf[SIZE];

	for (i = 0; i < size; i++) {
		check = str_copy(buf, str[i].slovo);
		if (check == 0) {
			for (j = 0; j < size; j++) {
				check = str_equal(buf, str[j].slovo);
				if (check == 0) {
					count++;
				}
			}
			if ((count > 1) && (string_count(str2, buf, k) == 0)) {
				str_copy(str2[k].slovo, str[i].slovo);
				str2[k].frequency = count;
				k++;
			}
			count = 0;
		}
	}

	return k;
}

short string_count(stroka *str2, char *buf, const short size)
{
	short j;

	for (j = 0; j < size; j++) {
		if ((str_equal(buf, str2[j].slovo)) == 0) {
			return -1;
		}
	}

	return 0;
}
