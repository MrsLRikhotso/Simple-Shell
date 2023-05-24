#include "shell.h"


/**
 * get_environ - returns string array copy of environ
 * @info: Structure contain arguments used to maintain
 *          constant prototype function
 * return: 0
 */

char **get_environ(info_x *info)

{

        if (!info->environ || info->env_changed)

        {

                info->environ = list_to_strings(info->env);

                info->env_changed = 0;

        }


        return (info->environ);

}


/**
 * _unsetenv - remove environment variable
 * @info: Structure contain arguments used to maintain
 *        constant prototype function 
 *  return: 1 on delete, 0 for opposite
 * @var: string environ var property
 */

int _unsetenv(info_x *info, char *var)

{

        list_t *node = info->env;

        size_t h = 0;

        char *p;


        if (!node || !var)

                return (0);


        while (node)

        {

                p = starts_with(node->str, var);

                if (p && *p == '=')

                {

                        info->env_changed = delete_node_at_index(&(info->env), h);

                        h = 0;

                        node = info->env;

                        continue;

                }

                node = node->next;

                h++;

        }

        return (info->env_changed);

}


/**
 * _setenv - give new environment variable,
 *             or change already an existing one
 * @info: Structure containing arguments used to maintain
 *        constant prototype function
 * @var: string environ var property
 * @value: string environ var value
 *  return: 0
 */

int _setenv(info_x *info, char *var, char *value)

{

        char *buf = NULL;

        list_t *node;

        char *t;


        if (!var || !value)

                return (0);


        buf = malloc(_strlen(var) + _strlen(value) + 2);

        if (!buf)

                return (1);

        _strcpy(buf, var);

        _strcat(buf, "=");

        _strcat(buf, value);

        node = info->env;

        while (node)

        {

                t = starts_with(node->str, var);

                if (t && *t == '=')

                {

                        free(node->str);

                        node->str = buf;

                        info->env_changed = 1;

                        return (0);

                }

                node = node->next;

        }

        add_node_end(&(info->env), buf, 0);

        free(buf);

        info->env_changed = 1;

        return (0);

}
