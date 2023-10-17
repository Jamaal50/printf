#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

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
int run_print(const char *fmt, int *i,
va_list args, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_ch(va_list args, char buffer[],
	    int flags, int width, int precision, int size);
int print_str(va_list args, char buffer[],
	    int flags, int width, int precision, int size);
int print_per(va_list args, char buffer[],
	    int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list args, char buffer[],
	    int flags, int width, int precision, int size);
int print_bin(va_list args, char buffer[],
	    int flags, int width, int precision, int size);
int print_uns(va_list args, char buffer[],
	    int flags, int width, int precision, int size);
int print_oct(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_hx(va_list args, char buffer[],
	    int flags, int width, int precision, int size);
int print_HX(va_list args, char buffer[],
	    int flags, int width, int precision, int size);

int print_HeXa(va_list args, char map_to[], char buffer[], int flags,
	       char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_nP(va_list args, char buffer[],
	    int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pt(va_list args, char buffer[],
		  int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int use_flags(const char *format, int *i);
int use_width(const char *format, int *i, va_list args);
int use_precision(const char *format, int *i, va_list args);
int use_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_Rv(va_list args, char buffer[],
		  int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_R13(va_list args, char buffer[],
	    int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
		      int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	      int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width,
		 int precision, int size);

/****************** UTILS ******************/
int is_print(char);
int app_hex(char, char[], int);
int is_dig(char);

long int conv_num(long int num, int size);
long int conv_uns(unsigned long int num, int size);

#endif /* MAIN_H */
