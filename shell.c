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
int status = 0, len = 0; /*wasSearchPath = 0;*/

while (len < vars->contk)
{
	if (access(vars->tokens[len], X_OK) == -1)
		searchRoadPATH(vars, env);
		/*wasSearchPath = searchRoadPATH(vars, env);*/

	if (access(vars->tokens[len], X_OK) == 0) 
	{
		child = fork();

		if (child > 0)
			wait(&status);
		else if (child == 0)
		{
			execve(vars->tokens[len], vars->tokens, env);
			free(vars->comand);
			kill(getpid(), SIGTERM);
		}
		/*if (wasSearchPath)
		free(vars->tokens[0]);*/
	}

len++;
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
	char ruta[1024];
	char *path_tokens = NULL;
	char *newRoad = NULL;
	int i = 0;

	ruta[0] = '\0';
	for (i = 0; env[i]; i++)
	{

	if (strncmp(env[i], "PATH=", 5) == 0)
		{
		strcpy(ruta, env[i]);
		path_tokens = strtok(ruta, "=");

		while (path_tokens != NULL)
		{
			path_tokens = strtok(NULL, ":");
			newRoad = RoadConcatCommand(vars, path_tokens, env);

			if (newRoad != NULL)
			{
				vars->tokens[0] = newRoad;
				/*isCommand(newRoad, vars, env);*/
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
char *RoadConcatCommand(var_t *vars, char *path_tokens, char **env)
{
	char *newRoad;
	char *_returnRoad = NULL;

	(void)env;
	/*newRoad[0] = '\0';*/

	newRoad = str_dup(path_tokens);
	str_cat(newRoad, "/");
	str_cat(newRoad, vars->tokens[0]);

	if ((access(newRoad, X_OK)) == 0)
	{
		_returnRoad = malloc(sizeof(char) * (strlen(newRoad) + 1));

		if (_returnRoad == NULL)
			return (NULL);

		_returnRoad[0] = '\0';
		strcat(_returnRoad, newRoad);
		return (_returnRoad);
	}

	return (NULL);
}

/**
 * isCommand - Function verified comand
 * @vars: struct of variables
 * @env: enviroment
 * Return: 1 success full or 127 fail
 */
int isCommand(var_t *vars, char **env)
{
	int i = 0, tkn = 0;
	char newRoad[1024];
	var_ec ec[] = {
		{"exit", exitFun},
		{"cd", cdFun},
		{"env", enviro},
		{"help", help},
		{NULL, NULL}
	};

	newRoad[0] = '\0';

	strcpy(newRoad, "/bin/");
	strcat(newRoad, vars->tokens[0]);

	while (ec[i].p != NULL)
	{
		if (strcmp(vars->tokens[0], ec[i].cmd) == 0)
		{
			return (ec[i].p(vars, env));
		}
	i++;
	}

	if (ec[i].p == NULL && access(newRoad, X_OK) == -1)
	{
	if (isatty(STDIN_FILENO))
		{
		tkn = vars->tk_i;
		printf("%s: %d: %s: not found\n", vars->nameShell, tkn, vars->tokens[0]);
		return (127);
		}
	}
	i++;
return (0);
}

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