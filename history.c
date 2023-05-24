#include "shell.h"

/**
 * get_history_file - history file
 * @info: struct parameter
 * Return: place string that contain history file
 */


char *get_history_file(info_x *info)

{

        char *buff, *dire;


        dire = _getenv(info, "HOME=");

        if (!dire)

                return (NULL);

        buff = malloc(sizeof(char) * (_strlen(dire) + _strlen(HIST_FILE) + 2));

        if (!buff)

                return (NULL);

        buff[0] = 0;

        _strcpy(buff, dire);

        _strcat(buff, "/");

        _strcat(buff, HIST_FILE);

        return (buff);

}


/**
 * write_history - create file or refer existing file
 * @info: struct parameter
 * Return: 1 success, otherwise -1
 */

int write_history(info_x *info)

{

        ssize_t id;

        char *filename = get_history_file(info);

        list_t *node = NULL;


        if (!filename)

                return (-1);


        id = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);

        free(filename);

        if (id == -1)

                return (-1);

        for (node = info->history; node; node = node->next)

        {

                _putsfd(node->str, id);

                _putfd('\n', id);

        }

        _putfd(BUF_FLUSH, id);

        close(id);

        return (1);

}


/**
 * read_history - reads history from file
 * @info: the parameter struct
 * Return: histcount on success, 0 otherwise
 */

int read_history(info_x *info)

{

        int e, last = 0, linecount = 0;

        ssize_t id, rdlen, fsize = 0;

        struct stat st;

        char *buf = NULL, *filename = get_history_file(info);


        if (!filename)

                return (0);


        id = open(filename, O_RDONLY);

        free(filename);

        if (id == -1)

                return (0);

        if (!fstat(id, &st))

                fsize = st.st_size;

        if (fsize < 2)

                return (0);

        buf = malloc(sizeof(char) * (fsize + 1));

        if (!buf)

                return (0);

        rdlen = read(id, buf, fsize);

        buf[fsize] = 0;

        if (rdlen <= 0)

                return (free(buf), 0);

        close(id);

        for (e = 0; e < fsize; e++)

                if (buf[e] == '\n')

                {

                        buf[e] = 0;

                        build_history_list(info, buf + last, linecount++);

                        last = e + 1;

                }

        if (last != e)

                build_history_list(info, buf + last, linecount++);

        free(buf);

        info->histcount = linecount;

        while (info->histcount-- >= HIST_MAX)

                delete_node_at_index(&(info->history), 0);

        renumber_history(info);

        return (info->histcount);

}


/**
 * build_history_list - entry history linked list
 * @info: Structure contain arguments used to maintain
 * @buf: the buffer
 * @linecount: history line count hist count
 * return: 0
 */

int build_history_list(info_x *info, char *buf, int linecount)

{

        list_t *node = NULL;


        if (info->history)

                node = info->history;

        add_node_end(&node, buf, linecount);


        if (!info->history)

                info->history = node;

        return (0);

}


/**
 * renumber_history - numbers again history linked list after changes
 * @info: Structure contain arguments used to maintain
 * return: new hist count
 */

int renumber_history(info_x *info)

{

        list_t *node = info->history;

        int e = 0;


        while (node)

        {

                node->num = e++;

                node = node->next;

        }

        return (info->histcount = e);

}
