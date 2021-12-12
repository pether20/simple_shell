#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

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
 * struct var_c - struct for commands and tokens.
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
void sighandler(int);
int tokens(var_t *vars, char **env);
int execute(var_t *vars, char **env);
int searchRoadPATH(var_t *vars, char **env);
int RoadConcatCommand(var_t *vars, char *path_tokens, char **env);
int isCommand(var_t *vars, char **env);
int isEspecialCommand(var_t *vars, char **env);
int exitFun(var_t *vars, char **env);
int cdFun(var_t *vars, char **env);
int enviro(var_t *vars, char **env);
int help(var_t *vars, char **env);
char print_help(char *ptr);
char *str_cat(char *s1, char *s2);
char *str_dup(char *str);
size_t len_str(char *str);

int countPipe(char comand[]);
int countFlux(char comand[]);
void finalComandTokens(char *finalTokens[], char comand[]);
void executeBasicComand(char *tokens[], char comand[]);

#endif
