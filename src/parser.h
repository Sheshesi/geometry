#ifndef PARSER_H
#define PARSER_H
double side_length(double x, double y, double xx, double yy);
char* squeeze(char s[]);
int symbols_tr_check(char string[]);
int symbols_cr_check(char string[]);
int name_check(const char str[]);
int permissible_symb(char symb);
double* cord_get(char str[]);
int cord_check(char str[]);
char* data_check(char* str);
char** file_func(char** data);
#endif