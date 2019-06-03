#ifndef STRING_H
#define STRING_H
#define SIZE 33

typedef struct {
char slovo[SIZE];
short frequency;
} stroka;

short str_length (const char *Stroka);

short str_copy (char *Stroka1, const char *Stroka2);

short str_equal (const char *Stroka1, const char *Stroka2);

#endif
