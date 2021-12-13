#include "shell.h"

/**
 * exitFun - function token command
 *
 * @vars: point
 * @env: point
 *
 * Return: variable status
 *
 */
int exitFun(var_t *vars, char **env)
{
	int status = 0;

	(void)env;

	if (vars->tokens[1] != NULL)
	{
		status = atoi(vars->tokens[1]);
	}
	free(vars->comand);
	free(vars->tokens);
	exit(status);
}

/**
 * cdFun - repository function assigned
 * @vars: point
 * @env: point
 *
 * Return: 1
 */
int cdFun(var_t *vars, char **env)
{
	char *road = NULL;
	char *ron = NULL;
	char *vodka = NULL;
	(void)env;

	road = malloc(sizeof(char) * 1024);
	if (vars->tokens == NULL)
		exit(0);

	getcwd(road, 1024);
	ron = str_cat(road, "/");
	vodka = str_cat(ron, vars->tokens[1]);
	chdir(vodka);
	free(road);
	free(ron);
	free(vodka);

	return (1);
}

/**
 * enviro - environment variable function
 * @vars: point
 * @env: point
 *
 * Return: 1
 */
int enviro(var_t *vars, char **env)
{
	int i = 0;
	(void)vars;

	printf("\n");
	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
	return (1);
}

/**
 * help - function match with options help
 * @vars: point
 * @env: point
 *
 * Return: 1
 */
int help(var_t *vars, char **env)
{
	char *ptr = "exit";
	char *ptr2 = "help";
	char *ptr3 = "help_help";
	int val = 0;

	(void)env;
	if (vars->tokens[1] != NULL)
	{
		if (strcmp(vars->tokens[1], "exit") == 0)
		{
			val = print_help(ptr);
			if (val == 0)
				return (0);
			if (val == 1)
				return (1);
		}
		if (strcmp(vars->tokens[1], "help") == 0)
		{
			val = print_help(ptr3);
			if (val == 0)
				return (0);
			if (val == 1)
				return (1);
		}
		else
		{
			printf("-bash: help: no help topics match `%s'.  T", vars->tokens[1]);
			printf("ry `help help' or `man -k asd' or `info asd'.\n");
			return (0);
		}
	}
	val = print_help(ptr2);
	if (val == 0)
		return (0);

	return (1);
}

/**
 * print_help - function write options help
 * @ptr: point
 *
 * Return: 1
 */
char print_help(char *ptr)
{
	char *buffer = NULL;
	int fd = 0, rd = 0, wr = 0;
	int MAX_BUF = 1024;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (0);

	fd = open(ptr, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		rd = read(fd, buffer, MAX_BUF);
		if (rd == 0)
			break;
		if (rd == -1)
			return (0);
		wr = write(1, buffer, rd);
		if (wr == -1)
			return (0);
	}
	free(buffer);
	return (1);
}
