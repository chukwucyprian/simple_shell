#include "main.h"


/**
 * append_to_line - Appends a character to the line buffer
 * @line: The line buffer to append to
 * @line_size: The current size of the line buffer
 * @c: The character to append
 *
 * Return:
 *   A pointer to the reallocated line buffer on success
 *   NULL if an error occurs
 */
char *append_to_line(char *line, size_t line_size, char c)
{
	size_t i;
	char *temp = malloc((line_size + 2) * sizeof(char));

	if (temp == NULL)
	{
		free(line);
		return (NULL);
	}

	if (line != NULL)
	{
		for (i = 0; i < line_size; i++)
			temp[i] = line[i];
		free(line);
	}
	temp[line_size] = c;
	temp[line_size + 1] = '\0';
	return (temp);
}

/**
 * custom_getline - Read a line of input from stdin
 *
 * Return:
 *   A pointer to the line read, or NULL on failure or EOF
 */
char *custom_getline(void)
{
static char buffer[BUFFER_SIZE];
static size_t buffer_pos;
static ssize_t num_read;
static int eof_flag;
char *line = NULL;
size_t line_size = 0;
int newline_found = 0;
if (!eof_flag)
{
while (!newline_found)
{
if (buffer_pos == (size_t)num_read)
{num_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (num_read <= 0)
break;
buffer_pos = 0;
}
while (buffer_pos < (size_t)num_read)
{
if (buffer[buffer_pos] == '\n')
{newline_found = 1;
buffer_pos++;
break;
}
line = append_to_line(line, line_size, buffer[buffer_pos++]);
if (line == NULL)
return (NULL);
line_size++;
}
}
if (line == NULL && (num_read == 0 || newline_found))
eof_flag = 1;
if (line == NULL && eof_flag)
{eof_flag = 0;
return (NULL);
}
return (line);
}
return (NULL);
}

