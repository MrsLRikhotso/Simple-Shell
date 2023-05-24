#include "shell.h"

/**
 * _myenv - print current environment
 * @info: Structure containi arguments used to maintain
 *          constant prototype function
 * return:  0
 */

int _myenv(info_x *info)

{

	print_list_str(info->env);

	return (0);

}


/**
 * _getenv - get value of environ variable
 * @info: Structure contain arguments used to maintain
 * @name: environ var name
 * return: environ  value
 */

char *_getenv(info_x *info, const char *name)

{

	list_t *node = info->env;

	char *u;


	while (node)

	{

		u = starts_with(node->str, name);

		if (u && *u)

			return (u);

		node = node->next;

	}

	return (NULL);

}


/**
 * _mysetenv - Initialisenew environ variable
 *             or change existing 1
 * @info: Structure contain  arguments used to maintain
 *        constant prototype function
 *  return: 0
 */

int _mysetenv(info_x *info)

{

	if (info->argc != 3)

	{

		_eputs("Incorrect number of arguements\n");

		return (1);

	}

	if (_setenv(info, info->argv[1], info->argv[2]))

		return (0);
	
	return (1);

}


/**

 * _myunsetenv - remove environ variable
 * @info: Structure contain arguments used to maintain
 *        constant prototype function
 * return: 0
 */

int _myunsetenv(info_x *info)

{

	int q;


	if (info->argc == 1)

	{

		_eputs("Too few arguements.\n");

		return (1);

	}
	
	for (q = 1; q <= info->argc; q++)

		_unsetenv(info, info->argv[q]);


	return (0);

}


/**

 * populate_env_list - populates environment linked list
 * @info: Structure containing used to maintain
 *          constant prototype function
 * return: 0
 */

int populate_env_list(info_x *info)

{

	list_t *node = NULL;

	size_t k;

	
	for (k = 0; environ[k]; k++)

		add_node_end(&node, environ[k], 0);

	info->env = node;

	return (0);

}


