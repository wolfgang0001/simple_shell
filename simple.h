#ifndef _SIMPLE__
#define _SIMPLE_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>
#define PROMPT "simple $ "


/**
 * struct builtin_d - Defines the builtins functions.
 * @built: The name of the build in command.
 * @f: A pointer to the right builtin function.
 */
typedef struct builtin_d
{
	char *built;
	void (*f)(char *);
} builtin_t;

extern char **environ;

char *dir_search(char **, char *);
int f_paths(char *);
char *b_path(char *, char *);
char **tokenize_path(int , char *);
char *p_find(char *);
void double_free(char **);
void single_free(int , ...);
int str_len(char *);
void create_child(char **, char *, int , char **);
char **tokenize(int , char *, const char *);
void parse_line(char *, size_t , int , char **);
char **token_interface(char *, const char *, int );
int count_token(char *, const char *);


/*Builtin function*/
void (*builtin_chk(char *))(char *);
void envir_v(__attribute__((unused))char *);
void chdir_cd(char *);
void exit_sh(char *);
int built_in(char **, char *);

/* ALx H_functions*/
void error_printing(char *, int, char *);
void exec_error(char *, int, char *);

/*Alx library functions*/
int _strcmp(char *, char *);
char *_strdup(char *);
void print_str(char *, int);
int print_number(int);
int put_char(char);


#endif
