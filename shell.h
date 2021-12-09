#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/*#define MAX_BUF 100*/

/**
 * struct var_s - struct for commands and tokens.
 * @status: character to match after find  a percentage.
 * @contk: function that will be called when it.
 * @tk_i: the character.
 * @nameShell: save name of shell.
 * @comand: command input.
 * @tokens: save tokens of the comands.
 * typedef var_t: new name struct.
 */
typedef struct var_s
{
	int status;
	int contk;
	int tk_i;
	char *nameShell;
	char *comand;
	char **tokens;

} var_t;

/**
 * struct var_s - struct for commands and tokens.
 * @cmd: Especial command.
 * @p: pointer function.
 * typedef var_c: new name struct.
 */
typedef struct var_c
{
	char *cmd;
	int (*p)(var_t *, char **);

} var_ec;

void promptvi(void);
int execute(var_t *vars, char **env);
int searchRoadPATH(var_t *vars, char **env);
char *RoadConcatCommand(var_t *vars, char *path_tokens);
int isCommand(var_t *vars, char **env);
int isEspecialCommand(var_t *vars, char **env);
int exitFun(var_t *vars, char **env);
int cdFun(var_t *vars, char **env);

int countPipe(char comand[]);
int countFlux(char comand[]);
void finalComandTokens(char *finalTokens[], char comand[]);
void executeBasicComand(char *tokens[], char comand[]);

#endif 
