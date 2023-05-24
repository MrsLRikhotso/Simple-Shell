#include "shell.h"

/**
 * _strlen - returns length of string
 * @s: string length check
 * Return: int length string
 */

int _strlen(char *s)

{

        int e = 0;


        if (!s)

                return (0);


        while (*s++)

                e++;

        return (e);

}


/**
 * _strcmp - lexicogarphic comparison with 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: negative for s1 greater than s2 positive if s1 less than s2 0 if s1 equals to s2
 */

int _strcmp(char *s1, char *s2)

{

        while (*s1 && *s2)

        {

                if (*s1 != *s2)

                        return (*s1 - *s2);

                s1++;

                s2++;

        }

        if (*s1 == *s2)

                return (0);

        else

                return (*s1 < *s2 ? -1 : 1);

}


/**
 * starts_with - checks when needle starts with haystack
 * @haystack: string search
 * @needle: substring to find
 * Return: the address of next char haystack otherwise NULL
 */

char *starts_with(const char *haystack, const char *needle)

{

        while (*needle)

                if (*needle++ != *haystack++)

                        return (NULL);

        return ((char *)haystack);

}


/**
 * _strcat - connects 2 strings
 * @dest: destination buff
 * @src: source buff
 * return: pointer at destination buff
 */

char *_strcat(char *dest, char *src)

{

        char *reet = dest;


        while (*dest)

                dest++;

        while (*src)

                *dest++ = *src++;

        *dest = *src;

        return (reet);

}
