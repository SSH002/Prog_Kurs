#include "string.h"

#ifndef COUNT_H
#define COUNT_H

short char_count (const char *filename);

short word_count (const char *filename);

short match_count (stroka *str, stroka *str2, const short word);

short string_count (stroka *str2, char *buffer, const short word);

#endif
