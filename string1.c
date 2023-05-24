#include "shell.h"

/**
 * _strcpy - copy string
 * @dest: destination
 * @src: source
 * return: pointer destination
 */

char *_strcpy(char *dest, char *src)

{

        int e = 0;


        if (dest == src || src == 0)

                return (dest);

        while (src[e])

        {

                dest[e] = src[e];

                e++;

        }

        dest[e] = 0;

        return (dest);

}


/**
 * _strdup - duplicate string
 * @str: string duplicate
 * Return: pointer duplicate string
 */

char *_strdup(const char *str)

{

        int length = 0;

        char *reet;


        if (str == NULL)

                return (NULL);

        while (*str++)

                length++;

        reet = malloc(sizeof(char) * (length + 1));

        if (!reet)

                return (NULL);

        for (length++; length--;)

                reet[length] = *--str;

        return (reet);

}


/**
 * _puts - prints input string
 * @str: string printed
 * return: 0
 */

void _puts(char *str)

{

        int e = 0;


        if (!str)

                return;

        while (str[e] != '\0')

        {

                _putchar(str[e]);

                e++;

        }

}


/**
 * _putchar - writes character c for stdout
 * @c: character print
 * return: success 1, error -1 
 */

int _putchar(char c)

{

        static int e;

        static char buf[WRITE_BUF_SIZE];


        if (c == BUF_FLUSH || e >= WRITE_BUF_SIZE)

        {

                write(1, buf, e);

                e = 0;

        }

        if (c != BUF_FLUSH)

                buf[e++] = c;

        return (1);

}
