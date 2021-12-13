#include "shell.h"

/**
 * main - Initation funtion
 * @argc: number of the arguments
 * @argv: arguments
 * @env: enviroments
 * Return: success full 1 or fail -1
 **/
int main(int argc, char **argv, char **env)
{
	var_t vars = {0, 0, 0, NULL, NULL, NULL};
	size_t size = 0;
	int varget = 0;

	(void)argc;
	vars.nameShell = argv[0];

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 3);
	signal(SIGINT, sighandler);
	while (varget != EOF)
	{
		varget = getline(&vars.comand, &size, stdin);
		if (varget == 1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "$ ", 3);
			continue;
		}
		if (varget == -1)
			break;
		vars.tk_i++;
		if (tokens(&vars, env) == 0)
		{
			execute(&vars, env);
		}
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 3);
		free(vars.comand);
		free(vars.tokens);
		vars.comand = NULL;
		size = 0;
	}

	free(vars.comand);
	return (0);
}

/**
 * tokens - Initation funtion
 *
 * @vars: point
 * @env: point
 *
 * Return: success full
 */
int tokens(var_t *vars, char **env)
{
	char delimitador[] = ",;\n\t ";
	int i = 0;

	vars->tokens = malloc(sizeof(char *) * 1024);
	if (vars->tokens == NULL)
		exit(0);
	vars->tokens[i] = strtok(vars->comand, delimitador);
	while (vars->tokens[i]  != NULL)
	{
	i++;
	vars->tokens[i] = strtok(NULL, delimitador);
	vars->contk = i;
	}

	if (vars->tokens[0] == NULL)
		return (1);
	return (isCommand(vars, env));
}

/**
 * sighandler - Initation funtion varible
 *
 * @signum: int argument
 *
 */
void sighandler(int signum)
{
	(void)signum;
	write(1, "\n$ ", 3);
}