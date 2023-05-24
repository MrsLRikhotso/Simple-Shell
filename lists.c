#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address pointer to headnodes
 * @str: str field for nodes
 * @num: node index use from history
 * return: size list
 */

list_t *add_node(list_t **head, const char *str, int num)

{

        list_t *new_head;


        if (!head)

                return (NULL);

        new_head = malloc(sizeof(list_t));

        if (!new_head)

                return (NULL);

        _memset((void *)new_head, 0, sizeof(list_t));

        new_head->num = num;

        if (str)

        {

                new_head->str = _strdup(str);

                if (!new_head->str)

                {

                        free(new_head);

                        return (NULL);

                }

        }

        new_head->next = *head;

        *head = new_head;

        return (new_head);

}


/**
 * add_node_end - add node at end of the list
 * @head: address pointer to headnodes
 * @str: str field of nodes
 * @num: nodes index used from history
 * return: size list
 */

list_t *add_node_end(list_t **head, const char *str, int num)

{

        list_t *new_node, *nodes;


        if (!head)

                return (NULL);


        nodes = *head;

        new_node = malloc(sizeof(list_t));

        if (!new_node)

                return (NULL);

        _memset((void *)new_node, 0, sizeof(list_t));

        new_node->num = num;

        if (str)

        {

                new_node->str = _strdup(str);

                if (!new_node->str)

                {

                        free(new_node);

                        return (NULL);

                }

        }

        if (nodes)

        {

                while (nodes->next)

                        nodes = nodes->next;

                nodes->next = new_node;

        }

        else

                *head = new_node;

        return (new_node);

}


/**
 * print_list_str - prints str element of list_t linked list
 * @h: pointer first node
 * return: size list
 */

size_t print_list_str(const list_t *h)

{

        size_t e = 0;


        while (h)

        {

                _puts(h->str ? h->str : "(nil)");

                _puts("\n");

                h = h->next;

                e++;

        }

        return (e);

}


/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: delete index of node
 * Return: 1 success, 0 otherwise
 */

int delete_node_at_index(list_t **head, unsigned int index)

{

        list_t *node, *prev_node;

        unsigned int e = 0;


        if (!head || !*head)

                return (0);


        if (!index)

        {

                node = *head;

                *head = (*head)->next;

                free(node->str);

                free(node);

                return (1);

        }

        node = *head;

        while (node)

        {

                if (e == index)

                {

                        prev_node->next = node->next;

                        free(node->str);

                        free(node);

                        return (1);

                }

                e++;

                prev_node = node;

                node = node->next;

        }

        return (0);

}


/**
 * free_list - frees all nodes list
 * @head_ptr: the address that pointer to head node
 * Return: 0
 */

void free_list(list_t **head_ptr)

{

        list_t *nodes, *next_node, *head;


        if (!head_ptr || !*head_ptr)

                return;

        head = *head_ptr;

        nodes = head;

        while (nodes)

        {

                next_node = nodes->next;

                free(nodes->str);

                free(nodes);

                nodes = next_node;

        }

        *head_ptr = NULL;

}


