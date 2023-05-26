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
#include <signal.h>
char *_remove(char **str);
char *_append(char **str1, char *buffer);
size_t _strlen(char *str);
void _execute(char *str, char **env);
char *_modify(char **str, char cha, char *str1);
char *_locate(char **com, char *path);
char *_path(char **envr, char **pth);
char *new_string(char **str, char *command);
char **parse(char *str, char *argv[]);
void com_test(char **argv, char **envir, char *str);
void handle_exit(char *com);
void handle_env(char *com, char **envir);
void print_error(char *str);
void signal_handler(int signal);
char *space_handle(char **str);
size_t space_track(char *str);
char *empty_string(char **str);
char *end_spaces(char **str);
size_t total_spaces(char *str);
char *_strdup(char **strd, char *ostr);
void execute_interactive(char **env);
void execute_non_interactive(char **env, char *str);
void handle_command(char *command, char **env);
void execute_command(char *command, char **env);
void print_error_message(char *executable, char *command);
char *append_to_line(char *line, size_t line_size, char c);
char *custom_getline(void);
void execute_single_command(char *command, char **env);
void print_error_message(char *command, char *error_msg);
char *concat_strings(char *str1, char *str2);
char *get_program_name(char *command);
size_t tokenize(char *str, char *tokens[]);
extern char **environ;






#define BUFFER_SIZE 1024



#endif

