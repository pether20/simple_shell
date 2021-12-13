#include "shell.h"

/**
 * execute - funtion execute commands
 * @vars: strutc of variables
 * @env: enviroment
 * Return: execution success or exit
 */
int execute(var_t *vars, char **env)
{
	pid_t child = 0;
	int status = 0; /*wasSearchPath = 0;*/

	if (access(vars->tokens[0], X_OK) == -1)
		searchRoadPATH(vars, env);
	if (access(vars->tokens[0], X_OK) == 0)
	{
		child = fork();

		if (child > 0)
			wait(&status);
		else if (child == 0)
		{ execve(vars->tokens[0], vars->tokens, env);
			free(vars->comand);
			free(vars->tokens);
			kill(getpid(), SIGTERM);
			exit(98);
		}
		return (1);
	}
	vars->contk = 0;
	return (0);
}

/**
 * searchRoadPATH - function search road path
 * @vars: struct of varibles
 * @env: enviroment system
 * Return: success 1 or fail -1
 */
int searchRoadPATH(var_t *vars, char **env)
{
	char *ruta = NULL;
	char *path_tokens = NULL;
	int i = 0, tk = 0, val = 0;

	/*ruta[0] = '\0';*/
	for (i = 0; env[i]; i++)
	{

		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			ruta = str_dup(env[i]);
			path_tokens = strtok(ruta, "=");

			while (path_tokens != NULL)
			{
				path_tokens = strtok(NULL, ":");
				if (!path_tokens)
				{
					tk = vars->tk_i;
					printf("%s: %d: %s: not found\n", vars->nameShell, tk, vars->tokens[0]);
					free(ruta);
					return (0);
				}
				val = RoadConcatCommand(vars, path_tokens, env);
				if (val == 1)
				{
					free(ruta);
					return (1);
				}
				i++;
			}
			return (0);
		}

	}
	return (0);
}

/**
 * RoadConcatCommand - Function return road concatenated comand
 * @vars: struct of variables
 * @path_tokens: road initial of path
 * @env: enviroment
 * Return: Road concatenated for execution
 */
int RoadConcatCommand(var_t *vars, char *path_tokens, char **env)
{
	char *newRoad = NULL;
	char *ron = NULL;
	char *vodka = NULL;
	char buffer[1024];
	int i = 0;

	(void)env;
	/*newRoad[0] = '\0';*/

	newRoad = str_dup(path_tokens);
	ron = str_cat(newRoad, "/");
	vodka = str_cat(ron, vars->tokens[0]);
	free(newRoad);
	free(ron);

	if ((access(vodka, X_OK)) == 0)
	{
		while (vodka[i] != '\0')
		{
			buffer[i] = vodka[i];
			i++;
		}
		buffer[i] = '\0';
		vars->tokens[0] = &buffer[0];
		free(vodka);
		return (1);
	}
	free(vodka);
	return (0);
}

/**
 * isCommand - Function verified comand
 * @vars: struct of variables
 * @env: enviroment
 * Return: 1 success full or 127 fail
 */
int isCommand(var_t *vars, char **env)
{
	int i = 0;
	var_ec ec[] = {
		{"exit", exitFun},
		{"cd", cdFun},
		{"env", enviro},
		{"help", help},
		{NULL, NULL}
	};

	while (ec[i].p != NULL)
	{
		if (strcmp(vars->tokens[0], ec[i].cmd) == 0)
		{
			return (ec[i].p(vars, env));
		}
		i++;
	}
	return (0);
}