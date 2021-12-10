#include "shell.h"

int exitFun(var_t *vars)
{
	int status;
	char cnt[10];
	(void)env;

	status = atoi(vars->tokens[1]);
	sprintf(cnt, "%d", status);
	if (isatty(STDIN_FILENO))
		write(1, cnt, strlen(cnt));
	exit(status);

}

int cdFun(var_t *vars)
{
	char *road = NULL;
	(void)env;

	road = malloc(sizeof(char)*1024);

	getcwd(road, 1024);
	strcat(road, "/");
	strcat(road, vars->tokens[1]);
	chdir(road);

	return(1);
}
