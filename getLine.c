#include "shell.h"

/**
 * input_buf - The buffers chain commands
 * @info: struct parameter
 * @buf:  buffer address
 * @len: len var address
 * return: read bytes
 */

ssize_t input_buf(info_x *info, char **buf, size_t *len)

{

        ssize_t g = 0;

        size_t len_p = 0;


        if (!*len) /* nothing left in the buffer then fill it */

        {

                /*bfree((void **)info->cmd_buf);*/

                free(*buf);

                *buf = NULL;

                signal(SIGINT, sigintHandler);

#if USE_GETLINE

                g = getline(buf, &len_p, stdin);

#else

                g = _getline(info, buf, &len_p);

#endif

                if (g > 0)

                {

                        if ((*buf)[g - 1] == '\n')

                        {

                                (*buf)[g - 1] = '\0'; /* should remove trailing newline */

                               g--;

                        }

                        info->linecount_flag = 1;

                        remove_comments(*buf);

                        build_history_list(info, *buf, info->histcount++);

                        /* (_strchr(*buf, ';')) is this a command chain? */

                        {

                                *len = g;

                                info->cmd_buf = buf;

                        }

                }

        }

        return (g);

}


/**
 * get_input - line minus the newline
 * @info:  struct parameter
 * return: read bytes
 */

ssize_t get_input(info_x *info)

{

        static char *buf; /* the ';' command chain buffer */

        static size_t i, g, lenn;

        ssize_t r = 0;

        char **buf_p = &(info->arg), *p;


        _putchar(BUF_FLUSH);

        r = input_buf(info, &buf, &lenn);

        if (r == -1) /* EOF */

                return (-1);

        if (lenn) /* commands left in the chain buffer */

        {

                g = i; /* init new iterator with current buf position */

                p = buf + i; /* should get pointer for return */


                check_chain(info, buf, &g, i, lenn);

                while (g < lenn) /* put semicolon or end */

                {

                        if (is_chain(info, buf, &g))

                                break;

                        g++;

                }


                i = g + 1; /* ++ past nulled ';'' */

                if (i >= lenn) /* reach end of buffer? */

                {

                        i = lenn = 0; /* should  reset position and length */

                        info->cmd_buf_type = CMD_NORM;

                }


                *buf_p = p; /* should pass back pointer to current command position */

                return (_strlen(p)); /*should  return length of current command */

        }


        *buf_p = buf; /* if not a chain, pass back buffer from _getline() */

        return (r); /* then return length of buffer from _getline() */

}


/**
 * read_buf - reads buffer
 * @info: struct parameter
 * @buf: it is buffer
 * @i: it is size
 * return: r if success
 */

ssize_t read_buf(info_x *info, char *buf, size_t *i)

{

        ssize_t f = 0;


        if (*i)

                return (0);

        f= read(info->readfd, buf, READ_BUF_SIZE);

        if (f >= 0)

                *i = f;

        return (f);

}


/**
 * _getline - gets next line of input from STDIN
 * @info: struct parameter
 * @ptr: the address of pointer to buffer preallocated or NULL
 * @length: the size of preallocated ptr buffer if not NULL
 * return: s
 */

int _getline(info_x *info, char **ptr, size_t *length)

{

        static char buf[READ_BUF_SIZE];

        static size_t j, len;

        size_t k;

        ssize_t r = 0, s = 0;

        char *p = NULL, *new_p = NULL, *c;


        p = *ptr;

        if (p && length)

                s = *length;

        if (j == len)

                j = len = 0;


        r = read_buf(info, buf, &len);

        if (r == -1 || (r == 0 && len == 0))

                return (-1);


        c = _strchr(buf + j, '\n');

        k = c ? 1 + (unsigned int)(c - buf) : len;

        new_p = _realloc(p, s, s ? s + k : k + 1);

        if (!new_p) /* MALLOC FAILURE! */

                return (p ? free(p), -1 : -1);


        if (s)

                _strncat(new_p, buf + j, k - j);

        else

                _strncpy(new_p, buf + j, k - j + 1);


        s += k - j;

        j = k;

        p = new_p;


        if (length)

                *length = s;

        *ptr = p;

        return (s);

}


/**
 * sigintHandler - Should blocks ctrl-C
 * @sig_num: signal number
 * return: 0
 */

void sigintHandler(__attribute__((unused))int sig_num)

{

        _puts("\n");

        _puts("$ ");

        _putchar(BUF_FLUSH);

}
