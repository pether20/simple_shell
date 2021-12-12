#include "shell.h"

/**
 * str_cat - Function verified comand
 * @s1: struct of variables
 * @s2: enviroment
 * Return: pointer
 */
char *str_cat(char *s1, char *s2)
{
	char *string;
	int a;
	int b;
	int i = 0;
	int m = 0;

	a = len_str(s1);
	b = len_str(s2);
	string = malloc(sizeof(char) * (a + b + 1));
	if (string == NULL)
	return (NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
	i++;
	}
	while (s2[m] != '\0')
	{
		string[i] = s2[m];
		i++;
		m++;
	}
	string[i] = '\0';
	return (string);
}

/**
 * str_dup - Function verified comand
 * @str: string
 * Return: pointer
 */
char *str_dup(char *str)
{
	char *result = malloc(sizeof(char) * (len_str(str) + 1));
	int i;

	if (result == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}

	result[i] = '\0';

	return (result);
}

/**
 * len_str - Function verified comand
 * @str: string
 * Return: pointer
 */
size_t len_str(char *str)
{
	size_t len = 0;

	if (str == NULL || *str == '\0')
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
