#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define ARG_MAX 1024

extern char **environ;
int wd_count(char *p);
void rm_end(char **d, char *s);
void exe_cmd(char *buff, int i, char *script, char **env);
int checkcmd(char **cmd, char **env);
char **splitcmd(char *);
void _strncpy(char *dest, char *src, size_t n);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
void _printenv(void);
char *_getenv(char *name, char **env, char **tmp);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void free_arg(char **arg);
void check_int(char *str, int *status);
int _power(int n, int pow);
#endif
