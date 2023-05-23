#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>
char *_remove(char **str);
char *_append(char **str1, char *buffer);
size_t _strlen(char *str);
void _execute(char *str, char **env);
char *_modify(char **str, char cha, char *str1);
char *_locate(char **com, char *path);
char *_path(char **envr, char **pth);
char *new_string(char **str, char *command);
char **parse(char *str, char **argv);
void com_test(char **argv, char **envir, char *str);
void handle_exit(char *com);
void handle_env(char *com, char **envir);
#endif

