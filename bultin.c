#include "shell.h"

/**
 * _myexit - exits shell

 * @info: Structure contain arguments used to maintain
 * constant prototype function
 * return: exits with given exit status
 * (0) otherwise if info argv[0] != "exit"
 */

int _myexit(info_x *info)

{

	int exit;


	if (info->argv[1]) /* For an exit arguement */

	{
		
		exit = _erratoi(info->argv[1]);
		
		if (exit == -1)

		{

			info->status = 2;

			print_error(info, "Illegal number: ");

			_eputs(info->argv[1]);

			_eputchar('\n');

			return (1);

		}

		info->err_num = _erratoi(info->argv[1]);

		return (-2);

	}

	info->err_num = -1;

	return (-2);

}


/**

 * _mycd - current directory of the process changes
 * @info: Structure contain arguments used to maintain
 * constant prototype function
 * return:  0
 */

int _mycd(info_x *info)

{

	char *w, *dire, buffer[1024];

	int chdire_ret;
 

	w = getcwd(buffer, 1024);

	if (!w)

		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])

	{

		dire = _getenv(info, "HOME=");

		if (!dire)

			chdire_ret = /* TODO: what is this suppose be? */

				chdir((dire = _getenv(info, "PWD=")) ? dire : "/");

		else

			chdire_ret = chdir(dire);

	}

	else if (_strcmp(info->argv[1], "-") == 0)

	{

		if (!_getenv(info, "OLDPWD="))

		{

			_puts(w);

			_putchar('\n');

			return (1);

		}

		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');

		chdire_ret = /* TODO: what is suppose to be? */

			chdir((dire = _getenv(info, "OLDPWD=")) ? dire : "/");

	}

	else

		chdire_ret = chdir(info->argv[1]);

	if (chdire_ret == -1)
	
	{

		print_error(info, "can't cd to ");

		_eputs(info->argv[1]), _eputchar('\n');

	}

	else

	{

		_setenv(info, "OLDPWD", _getenv(info, "PWD="));

		_setenv(info, "PWD", getcwd(buffer, 1024));

	}

	return (0);

}


/**
 * _myhelp - changes current directory of process
 * @info: Structure contain arguments used to maintain
 * constant prototype function
 * return: 0
 */

int _myhelp(info_x *info)

{

	char **arg_arrays;


	arg_arrays = info->argv;

	_puts("help call works. Function not yet implemented \n");

	if (0)

		_puts(*arg_arrays); /* temp att_unused work around */

	return (0);

}


