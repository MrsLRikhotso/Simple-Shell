#include "shell.h"

/**
 * _memset - fills memory in constant byte
 * @s: pointer to memory area
 * @b: byte fill with s
 * @n: amount of bytes filled
 * Return: s pointer to memory area
 */

char *_memset(char *s, char b, unsigned int n)

{

        unsigned int e;


        for (e = 0; e < n; e++)

                s[e] = b;

        return (s);

}


/**
 * ffree - frees strings
 * @pp: strings 
 */

void ffree(char **pp)

{

        char **t = pp;


        if (!pp)

                return;

        while (*pp)

                free(*pp++);

        free(t);

}


/**
 * _realloc - reallocates block memory
 * @ptr: pointer previous malloc block
 * @old_size: byte size for previous block
 * @new_size: byte size for new block
 * return: pointer to da old block name
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{

        char *b;


        if (!ptr)

                return (malloc(new_size));

        if (!new_size)

                return (free(ptr), NULL);

        if (new_size == old_size)

                return (ptr);


        b = malloc(new_size);

        if (!b)

                return (NULL);


        old_size = old_size < new_size ? old_size : new_size;

        while (old_size--)

                b[old_size] = ((char *)ptr)[old_size];

        free(ptr);

        return (b);

}



