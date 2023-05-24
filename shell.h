#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct builtin_funcs - a struct to hold my own builtin functions
 * @command: the command string
 * @funptr: pointer to the builtin function
*/

typedef struct builtin_funcs
{
	char *command;
	void (*funptr)(int, char **);
} f_struc;


/*Strings Functions*/
char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
int _atoi(char *str);
char *_itoa(int x);
int num_len(int num);

/*Shell helper Specific functions*/
char **token_line(char *line, char *delim);
int tokens_count(char *str, char *delim);
char *get_path(char **env);
void (*find_fun(char *str))();
char *read_line(void);
void fork_process(char **args, char **argv, char **env);
void my_signal(int sig);

/*Builtins*/
void handle_exit(int status, char **env);
void handle_env(int status, char **env);

/*Memory allocation/free functions*/
void *_calloc(size_t nmemb, unsigned int size);
char **allocate_string_array(size_t n);
void qol_free(char **args);

/**
 * struct path - a struct to hold a tokenized strings array and size.
 * @my_paths: the tokenized strings array.
 * @size: size of the strings array.
*/
typedef struct path
{
	char **my_paths;
	size_t size;
} paths;
paths handle_path(char **env, char **tokens_args);
#endif

