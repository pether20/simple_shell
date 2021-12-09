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
	char *prompt = "$ ", delimitador[] = ",.;\n\t ";
	var_t vars = {0, 0, 0, NULL, NULL, NULL};
	size_t size = 0;
	int i = 0;

	(void)argc;
	vars.nameShell = argv[0];

	vars.tokens = malloc(sizeof(char *) * 1024);

	if (vars.tokens == NULL)
		exit(0);

	/*printf("%s",prompt);*/
	if (isatty(STDIN_FILENO))
		write(1, "$ ", 3);

	while (getline(&vars.comand, &size, stdin) != -1)
	{
		i = 0;
		vars.tokens[i] = strtok(vars.comand, delimitador);
		while (vars.tokens[i]  != NULL)
		{
			vars.tk_i = i;
			i++;

			vars.tokens[i] = strtok(NULL, delimitador);
			vars.contk = i;
		}

		execute(&vars, env);
		printf("%s", prompt);
		free(vars.comand);
		vars.comand = NULL;
		size = 0;

	}
	free(vars.comand);
	free(vars.tokens);
	return (1);
}