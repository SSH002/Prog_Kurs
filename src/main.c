#include <stdio.h>
#include "string.h"
#include "count.h"
#include "file.h"
#include "sort.h"

int main(int argc, char *argv[])
{
	if (argc == 3) {
		short count, size, check, k;
		count = char_count(argv[1]);
		size = word_count(argv[1]);
		stroka str[size];
		stroka str2[size];
		check = read_file(argv[1], str, size);
		if (check == 0) {
			k = match_count(str, str2, size);
			sort(str2, k);
			write_file(argv[2], count, str2, k);
		} else {
			printf("\nАварийное завершение работы программы...");
			return 0;
		}
	} else {
		printf("\nНеверный синтаксис вызова программы!");
		printf("\nНапример: \"./calc <имя_входного_файла> <имя_выходного_файла>\"");
		return 0;
	}

	return 0;
}
