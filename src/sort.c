#include <stdio.h>
#include "string.h"
#include "count.h"
#include "sort.h"

short maximum(stroka *str, short size)
{
	short i, max = 32000;

	for (i = 0; i < size; i++) {
		if (str[i].frequency < max) {
			max = str[i].frequency;
		}
	}

	return max;
}

void sort(stroka *str, const short size)
{
	short i, j, m = size, max, temp;
	char tmp[SIZE];

	for (i = m - 1; i > 0; i--) {
		max = maximum(str, m);
		for (j = 0; j < m; j++) {
			if (str[j].frequency == max) {
				temp = str[i].frequency;
				str[i].frequency = str[j].frequency;
				str[j].frequency = temp;

				str_copy(tmp, str[i].slovo);
				str_copy(str[i].slovo, str[j].slovo);
				str_copy(str[j].slovo, tmp);

				m--;
				break;
			}
		}
	}
}
