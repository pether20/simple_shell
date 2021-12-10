#include "shell.h"

int exitFun(var_t *vars, char **env)
{
	int status;

	(void)env;

	status = atoi(vars->tokens[1]);
	if (vars->tokens[1] != NULL)
	{	printf("%d: exit: Illegal number: %s\n", vars->tk_i, vars->tokens[1]);
		return (1);
	}
	free(vars->comand);
	free(vars->tokens);
	exit(status);
}

int cdFun(var_t *vars, char **env)
{
	char *road = NULL;
	(void)env;

	road = malloc(sizeof(char) * 1024);
	if (vars->tokens == NULL)
		exit(0);

	getcwd(road, 1024);
	strcat(road, "/");
	strcat(road, vars->tokens[1]);
	chdir(road);
	free(road);

	return (1);
}

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
