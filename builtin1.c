#include "shell.h"

/**
 * _myhistory - display history list 1 command per line
 *              with line numbers start with  0
 * @info: Structure contain arguments used to maintain
 *        constant prototype function
 *  return: 0
 */

int _myhistory(info_x *info)

{

	print_list(info->history);

	return (0);

}


/**
 * unset_alias - set alias to string
 * @info: the parameter struct
 * @str: string alias
 * return: 0 on success otherwise 1 on error
 */

int unset_alias(info_x *info, char *str)

{

	char *x, o;

	int ret;


	x = _strchr(str, '=');

	if (!x)

		return (1);

	o = *x;

	*x = 0;

	ret = delete_node_at_index(&(info->alias),

			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));

	*x = o;

	return (ret);

}


/**
 * set_alias - sets alias as string
 * @info: struct parameter
 * @str: string alias
 * return: 0 success 1 error
 */

int set_alias(info_x *info, char *str)

{

	char *u;


	u = _strchr(str, '=');

	if (!u)

		return (1);

	if (!*++u)

		return (unset_alias(info, str));


	unset_alias(info, str);

	return (add_node_end(&(info->alias), str, 0) == NULL);

}


/**
 * print_alias - print alias string
 * @node: alias node
 * return: 0 success 1 error
 */

int print_alias(list_t *node)

{

	char *u = NULL, *a = NULL;


	if (node)

	{

		u = _strchr(node->str, '=');

		for (a = node->str; a <= u; a++)

			_putchar(*a);

		_putchar('\'');

		_puts(u + 1);

		_puts("'\n");

		return (0);

	}

	return (1);

}


/**
 * _myalias - imitates alias builtin 
 * @info: Structure contain arguments used to maintain
 *          constant prototype function 
 *  return: 0
 */

int _myalias(info_x *info)

{

	int g = 0;

	char *u = NULL;

	list_t *node = NULL;
	
	if (info->argc == 1)

	{

		node = info->alias;

		while (node)

		{

			print_alias(node);

			node = node->next;

		}

		return (0);

	}

	for (g = 1; info->argv[g]; g++)

	{

		u = _strchr(info->argv[g], '=');

		if (u)

			set_alias(info, info->argv[g]);

		else

			print_alias(node_starts_with(info->alias, info->argv[g], '='));

	}


	return (0);

}

