#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define UNUSED(x) (void)(x)

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int printHandler(const char *fmt, int *i,
va_list file, char buffer[], int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *buff_ind);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list set, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list set, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list set, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list set, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list set, char buffer[],
	int flags, int width, int precision, int size);
int print_unt(va_list set, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list set, char buffer[],
	int flags, int width, int precision, int size);
int print_x(va_list set, char buffer[],
	int flags, int width, int precision, int size);
int print_xUpper(va_list set, char buffer[],
	int flags, int width, int precision, int size);

int print_xd(va_list set, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_legible(va_list set, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_ptr(va_list set, char buffer[],
int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int fetch_flags(const char *format, int *i);
int calcStrText(const char *format, int *i, va_list file);
int set_dec_precision(const char *format, int *i, va_list file);
int dataSize(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list set, char buffer[],
int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13str(va_list set, char buffer[],
int flags, int width, int precision, int size);

/* width handler */
int process_output(char c, char buffer[],
int flags, int width, int precision, int size);
int print_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int print_num(int ind, char bff[], int flags, int width, int precision,
int len, char padding_value, char extra_c);
int write_pointer(char buffer[], int ind, int len,
int width, int flags, char padding_value, char extra_c, int padding_value_start);
int write_pointer(char buffer[], int ind, int len,
int width, int flags,
char padding_value, char extra_c, int padding_value_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);
/****************** UTILS ******************/
int is_outputed(char);
int append_xd_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
