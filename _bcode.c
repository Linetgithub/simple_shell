#include "shell.h"

/**
 * interactive - returns true if at all the shell
 * is in interactive mode
 * @info: this is a struct adress
 *
 * Return: returns 0, 1 if in interactive mode
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks whether the character is a delimeter
 * @c: the char to check
 * @delim: this is the delimeter string
 * Return: 0 for false ,1 for true
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @i: character to input
 * Return: if i is alphabet it returns 1,if not 0
 */

int _isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _bcode - a string converted to an integer
 * @c: string to be converted
 * Return: convert the number , if no number in the string return 0
 */

int _bcode(char *c)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; c[i] != '\0' && flag != 2; i++)
	{
		if (c[i] == '-')
			sign *= -1;
		if (c[i] <= '0' && c[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (c[i] - '0');
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
