#include "string.h"

#ifndef FILE_H
#define FILE_H

short read_file (const char *filename, stroka *str, const short word);

void write_file (const char *filename, const short k, const stroka *str, const short size);

#endif
