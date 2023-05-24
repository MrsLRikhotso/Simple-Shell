#include "shell.h"


/**
 * clear_info - put info_x struct
 * @info: address struct
 */

void clear_info(info_x *info)

{

        info->arg = NULL;

        info->argv = NULL;

        info->path = NULL;

        info->argc = 0;

}


/**
 * set_info - put info_x struct
 * @info: address struct
 * @av: vector argument
 */

void set_info(info_x *info, char **av)

{

        int e = 0;


        info->fname = av[0];

        if (info->arg)

        {

                info->argv = strtow(info->arg, " \t");

                if (!info->argv)

                {

                        info->argv = malloc(sizeof(char *) * 2);

                        if (info->argv)

                        {

                                info->argv[0] = _strdup(info->arg);

                                info->argv[1] = NULL;

                        }

                }

                for (e = 0; info->argv && info->argv[e]; e++)

                        ;

                info->argc = e;


                replace_alias(info);

                replace_vars(info);

        }

}


/**
 * free_info - frees info_x struct fields
 * @info: address struct
 * @all: true for freeing all fields
 */

void free_info(info_x *info, int all)

{

        ffree(info->argv);

        info->argv = NULL;

        info->path = NULL;

        if (all)

        {

                if (!info->cmd_buf)

                        free(info->arg);

                if (info->env)

                        free_list(&(info->env));

                if (info->history)

                        free_list(&(info->history));

                if (info->alias)

                        free_list(&(info->alias));

                ffree(info->environ);

                        info->environ = NULL;

                bfree((void **)info->cmd_buf);

                if (info->readfd > 2)

                        close(info->readfd);

                _putchar(BUF_FLUSH);

        }

}


