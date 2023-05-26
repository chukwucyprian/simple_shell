#include "main.h"

/**
 * tokenize - tokenizes a string
 * @str: string
 * @tokens: array to store the tokens
 * Return: number of tokens
 */
size_t tokenize(char *str, char *tokens[])
{
char *token;
size_t count = 0;

 /* Find the first non-space character */
while (*str == ' ')
str++;

/* Tokenize the string manually */
while (*str != '\0')
{
/* Find the end of the current token */
token = str;
while (*str != ' ' && *str != '\0')
str++;

/* Store the token in the array */
tokens[count++] = token;

/* Find the next non-space character */
while (*str == ' ')
str++;

if (*str == '\0')
break;

/* Replace the space with a null terminator */
*str++ = '\0';
}

return (count);
}
