#include "shell.h"

/**
 * is_cmd - determines file executable command
 * @info: info struct
 * @path: path to file
 * return: 1 for success, 0 failure
 */

int is_cmd(info_x *info, char *path)

{

        struct stat st;


        (void)info;

        if (!path || stat(path, &st))

                return (0);


        if (st.st_mode & S_IFREG)

        {

                return (1);

        }

        return (0);

}


/**
 * dup_chars - duplicating characters
 * @pathstr: PATHS string
 * @start: start with index
 * @stop: stop index
 * Return: pointer new buff
 */

char *dup_chars(char *pathstr, int start, int stop)

{

        static char buff[1024];

        int e = 0, c = 0;


        for (c = 0, e = start; e < stop; e++)

                if (pathstr[e] != ':')

                        buff[c++] = pathstr[e];

        buff[c] = 0;

        return (buff);

}


/**
 * find_path - find cmd in PATHS string
 * @info: info struct
 * @pathstr: PATHS string
 * @cmd: cmd to find
 * return: full paths cmd if found otherwise NULL
 */

char *find_path(info_x *info, char *pathstr, char *cmd)

{

        int e = 0, curr_pos = 0;

        char *paths;


        if (!pathstr)

                return (NULL);

        if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))

        {

                if (is_cmd(info, cmd))

                        return (cmd);

        }

        while (1)

        {

                if (!pathstr[e] || pathstr[e] == ':')

                {

                        paths = dup_chars(pathstr, curr_pos, e);

                        if (!*paths)

                                _strcat(paths, cmd);

                        else

                        {

                                _strcat(paths, "/");

                                _strcat(paths, cmd);

                        }

                        if (is_cmd(info, paths))

                                return (paths);

                        if (!pathstr[e])

                                break;

                        curr_pos = e;

                }

                e++;

        }

        return (NULL);

}
