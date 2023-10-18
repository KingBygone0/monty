#include "monty.h"
#include <stddef.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE 200809L
/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
char *filename, *line = NULL;
FILE *file;
size_t len = 0;
ssize_t read;
unsigned int line_number;
instruction_t instruction;
stack_t *stack = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
filename = argv[1];
file = fopen(filename, "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
line_number = 1;
while ((read = custom_getline(&line, &len, file)) != -1)
{
instruction.opcode = strtok(line, " \t\n");
if (instruction.opcode == NULL || instruction.opcode[0] == '#')
{
line_number++;
continue;
}
execute_opcode(&instruction, &stack, line_number);
line_number++;
}
free(line);
fclose(file);
return (0);
}
