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
#include <dirent.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>

ssize_t read_input(char *prompt, char **command, bool pipe);
void execute_command(char *command);
void shell_loop(void);
int main(int argc, char *argv[], char **env);
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
char *append_to_line(char *line, size_t line_size, char c);
char *custom_getline(void);


#define MAX_ARGS 10
#define BUFFER_SIZE 1024


#endif

