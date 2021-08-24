#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

ssize_t _prompt(char **argv, int *flag, char **env);
int _exitt(char *av, int num);
int _print_env(char *av, char **env);
void _path(char **av, char *env, char *av_0, int av_l, int *p_find);
void fill(char *str, char *p);
char **_strtok(char *str);
void __cd_error(info_t *info, char *dir);
void __cd_success(info_t *info);
int __cd(info_t *info);
#endif
