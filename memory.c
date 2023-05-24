#include "shell.h"

/**
 * bfree - frees pointer & NULLs the address
 * @ptr: address of pointer to free
 * return: 1 for free or 0 for otherwise.
 */

int bfree(void **ptr)

{

        if (ptr && *ptr)

        {

                free(*ptr);

                *ptr = NULL;

                return (1);

        }

        return (0);

}
