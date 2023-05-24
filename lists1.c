#include "shell.h"

/**
 * list_len - length linked list
 * @h: pointer at first node
 * return: size list
 */

size_t list_len(const list_t *h)

{

        size_t e = 0;


        while (h)

        {

                h = h->next;

                e++;

        }

        return (e);

}


/**
 * list_to_strings - return array of strings of list->str
 * @head: pointer first node
 * return: strings array
 */

char **list_to_strings(list_t *head)

{

        list_t *node = head;

        size_t e = list_len(head), g;

        char **struu;

        char *str;


        if (!head || !e)

                return (NULL);

        struu = malloc(sizeof(char *) * (e + 1));

        if (!struu)

                return (NULL);

        for (e = 0; node; node = node->next, e++)

        {

                str = malloc(_strlen(node->str) + 1);

                if (!str)

                {

                        for (g = 0; g < e; g++)

                                free(struu[g]);

                        free(struu);

                        return (NULL);

                }


                str = _strcpy(str, node->str);

                struu[e] = str;

        }

        struu[e] = NULL;

        return (struu);

}



/**
 * print_list - prints all elements list_t linked
 * @h: pointer first node
 * return: size list
 */

size_t print_list(const list_t *h)

{

        size_t e = 0;


        while (h)

        {

                _puts(convert_number(h->num, 10, 0));

                _putchar(':');

                _putchar(' ');

                _puts(h->str ? h->str : "(nil)");

                _puts("\n");

                h = h->next;

                e++;

        }

        return (e);

}


/**
 * node_starts_with - returns node with string starting with prefix
 * @node: pointer listhead
 * @prefix: the string should  match
 * @c: next character after prefix  match
 * Return: match node otherwise null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)

{

        char *h = NULL;


        while (node)

        {

                h = starts_with(node->str, prefix);

                if (h && ((c == -1) || (*h == c)))

                        return (node);

                node = node->next;

        }

        return (NULL);

}


/**
 * get_node_index - gets index of node
 * @head: pointer listhead
 * @node: pointer to node
 * Return: index node otherwise -1
 */

ssize_t get_node_index(list_t *head, list_t *node)

{

        size_t e = 0;


        while (head)

        {

                if (head == node)

                        return (e);

                head = head->next;

                e++;

        }

        return (-1);

}


