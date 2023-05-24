#include "shell.h"


/**
 **_strncpy - copies string
 *@dest: destination string copied 
 *@src: source string
 *@n: amount of characters copied
 *Return: concatenated string
 */

char *_strncpy(char *dest, char *src, int n)

{

        int e, m;

        char *s = dest;


        e = 0;

        while (src[e] != '\0' && e < n - 1)

        {

                dest[e] = src[e];

                e++;

        }

        if (e < n)

        {

                m = e;

                while (m < n)

                {

                        dest[m] = '\0';

                        m++;

                }

        }

        return (s);

}


/**
 **_strncat - connects 2 strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes used to max
 *Return: connnected string
 */

char *_strncat(char *dest, char *src, int n)

{

        int e, m;

        char *s = dest;


        e = 0;

        m = 0;

        while (dest[e] != '\0')

                e++;

        while (src[m] != '\0' && m < n)

        {

                dest[e] = src[m];

                e++;

                m++;

        }

        if (m < n)

                dest[e] = '\0';

        return (s);

}


/**
 **_strchr - locates character within string
 *@s: string passed
 *@c: character to look for
 *return: (s) pointer at memory area s
 */

char *_strchr(char *s, char c)

{

        do {

                if (*s == c)

                        return (s);

        } while (*s++ != '\0');


        return (NULL);

}
