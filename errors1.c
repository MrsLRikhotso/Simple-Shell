#include "shell.h"

/**
 * _erratoi - convert string to integer
 * @s: string will be converted
 * return: 0 if there is no numbers in string convert number for diiferent outcome
 *       -1 of error
 */

int _erratoi(char *s)

{

        int j = 0;

        unsigned long int result = 0;


        if (*s == '+')

                s++;  /* TODO: why does this make main return 255? */

        for (j = 0;  s[j] != '\0'; j++)

        {

                if (s[j] >= '0' && s[j] <= '9')

                {

                        result *= 10;

                        result += (s[j] - '0');

                        if (result > INT_MAX)

                                return (-1);

                }

                else

                        return (-1);

        }

        return (result);

}


/**

 * print_error - print error message
 * @info: parameter and return info struct
 * @estr: The string contain specified error type
 * Return: 0 for no numbers in string converted number for different outcome
 *        -1 of error
 */

void print_error(info_x *info, char *estr)

{

        _eputs(info->fname);

        _eputs(": ");

        print_d(info->line_count, STDERR_FILENO);

        _eputs(": ");

        _eputs(info->argv[0]);

        _eputs(": ");

        _eputs(estr);

}


/**

 * print_d -  prints a decimal int number base 10
 * @input: give input
 * @fd: file descriptor to write
 * Return: number of characters to be printed
 */

int print_d(int input, int fd)

{

        int (*__putchar)(char) = _putchar;

        int j, count = 0;

        unsigned int _abs_, current;


        if (fd == STDERR_FILENO)

                __putchar = _eputchar;

        if (input < 0)

        {

                _abs_ = -input;

                __putchar('-');

                count++;

        }

        else

                _abs_ = input;

        current = _abs_;

        for (j = 1000000000; j > 1; j /= 10)

        {

                if (_abs_ / j)

                {

                        __putchar('0' + current / j);

                        count++;

                }

                current %= j;

        }

        __putchar('0' + current);

        count++;


        return (count);

}


/**

 * convert_number - converter func to a clone of itoa
 * @num: numbers
 * @base: the base
 * @flags: the argument flags
 * Return: string
 */

char *convert_number(long int num, int base, int flags)

{

	static char *array;
        
	static char buffer[50];

        char sign = 0;

        char *ptr;

        unsigned long m = num;


        if (!(flags & CONVERT_UNSIGNED) && num < 0)

        {

                m = -num;

                sign = '-';


        }

        array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";

        ptr = &buffer[49];

        *ptr = '\0';


        do        {

                *--ptr = array[m % base];

                m /= base;

        } while (m != 0);


        if (sign)

                *--ptr = sign;

        return (ptr);

}


/**

 * remove_comments - function replace first '#' with '\0'
 * @buf: address string to modify
 * Return: 0;
 */

void remove_comments(char *buf)

{

        int j;


        for (j = 0; buf[j] != '\0'; j++)

                if (buf[j] == '#' && (!j || buf[j - 1] == ' '))

                {

                        buf[j] = '\0';

                        break;

                }

}



