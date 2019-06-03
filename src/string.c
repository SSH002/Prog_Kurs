#include <stdio.h>
#include "string.h"

short str_length(const char *Stroka)
{
	short i = 0;

	while (Stroka[i] != '\0') {
		i++;
	}

	if (i != 0) {
		return i + 1;	// "+ 1" для '\0'
	} else {
		return -1;
	}
}

short str_copy(char *Stroka1, const char *Stroka2)
{
	sprintf(Stroka1, "%s", Stroka2);

	return 0;
}

short str_equal(const char *Stroka1, const char *Stroka2)
{
	short k, l;

	k = str_length(Stroka1);
	l = str_length(Stroka2);

	if ((k != l) || (k == -1) || (l == -1)) {
		return -1;
	} else {
		l = 0;
		for (short i = 0; i < k; i++) {
			if (Stroka1[i] != Stroka2[i]) {
				break;
			}
			l++;
		}

		if (l == k) {
			return 0;
		} else {
			return -1;
		}
	}
}
