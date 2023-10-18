#include "monty.h"
/**
 * custom_getline - Custom getline function.
 * @lineptr: A pointer to the buffer that will hold the line.
 * @n: A pointer to the size of the buffer.
 * @stream: The file stream to read from.
 *
 * Return: The number of characters read, or -1 if there's an error or EOF.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
int ch;
size_t index = 0;
char *temp;
if (lineptr == NULL || n == NULL)
return (-1);
if (*lineptr == NULL || *n == 0)
{
*n = 128;
*lineptr = (char *)malloc(*n);
if (*lineptr == NULL)
return (-1);
}
while (1)
{
ch = fgetc(stream);
if (ch == EOF || ch == '\n')
{
(*lineptr)[index] = '\0';
return ((index > 0) ? (ssize_t)index : -1);
}
if (index == *n - 1)
{
*n += 128;
temp = (char *)realloc(*lineptr, *n);
if (temp == NULL)
return (-1);
*lineptr = temp;
}
(*lineptr)[index++] = ch;
}
}
