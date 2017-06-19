// file: my_fscanf.c
#define _CRT_SECURE_NO_WARNINGS
#include "my_fscanf.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void my_fscanf(FILE *fp, const char *format, ...) {
	unsigned int num = 0;
	int index = 0;
	int c;
	int *parameter;
	char *op;
	char *str_tmp;
	char str[10];
	char dot_arr[10];
	double *dot;
	va_list list;
	va_start(list, format);
	while (*format != '\0') {
		if (*format == '%') {
			format++;
			switch (*format) {
			case 'd':
				while (isspace(c = getc(fp))) {} // skip leading white space
				while (isdigit(c)) {
					num = num * 10 + c - '0';
					c = getc(fp);
				}
				parameter = va_arg(list, int*);
				*parameter = num;
				format++;
				num = 0;
				break;

			case 'c':
				op = va_arg(list, char*);
				c = getc(fp);
				*op = c;
				format++;
				break;

			case 's':
				while (isspace(c = getc(fp))) {}
				while (isalpha(c)) {
					str[index] = c;
					c = getc(fp);
					index++;
				}
				str[index] = '\0';
				str_tmp = va_arg(list, char*);
				strcpy(str_tmp, str, 5);				
				format++;
				index = 0;
				break;

			case 'f':
				dot = va_arg(list, float*);
				while (!isdigit(c = getc(fp))) {};
				while (isdigit(c) || c == '.') {
					dot_arr[index] = c;
					c = getc(fp);
					index++;
				}
				dot_arr[index] = '\0';
				*dot = atof(dot_arr);
				format++;
				index = 0;
				break;

			default:
				break;

			}
		}

		else{
			format++;
		}
	}

	va_end(list);
}