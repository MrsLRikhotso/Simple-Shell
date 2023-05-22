#include "shell.h"

/**
 * interact - if true return shell is interactive mode
 * @infor: struct_address
 * Return: 1 interactive mode 0 if otherwise
 */

int interact(info_x *infor)

{

	return (isatty(STDIN_FILENO) && infor->readfd <= 2);

}


/**
 * is_delim - character will check if is a delimeter
 * @d: char to check
 * @delimo: a delimeter string
 * Return: 1 true 0 false
 */

int is_delim(char d, char *delimo)

{

	while (*delimo)

		if (*delimo++ == d)

			return (1);

	return (0);

}


/**
 * _isalpha - checks alphabet character
 * @o: character to input
 * Return: 1 if o is alphabet 0 otherwise
 */


int _isalpha(int o)

{

	if ((o >= 'a' && o <= 'z') || (o >= 'A' && o <= 'Z'))

		return (1);

	else

		return (0);

}


/**

 * _atoi - converts string to integer
 * @p: string will be converted
 * return: 0 for  no numbers in string and converted number otherwise
 */

int _atoi(char *p)

{

	int e, sign = 1, flag = 0, output;

	unsigned int result = 0;


	for (e = 0; p[e] != '\0' && flag != 2; e++)

	{

		if (p[e] == '-')

			sign *= -1;


		if (p[e] >= '0' && p[e] <= '9')

		{

			flag = 1;

			result *= 10;

			result += (p[e] - '0');

		}

		else if (flag == 1)

			flag = 2;

	}


	if (sign == -1)

		output = -result;

	else

		output = result;


	return (output);

}
