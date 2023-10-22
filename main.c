#include "monty.h"
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
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
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, len, file) != NULL)
	{
	line_number++;
	opcode = strtok(line, " \t\n");
		if (opcode)
		{
			arg = strtok(NULL, " \t\n");
			execute_opcode(&stack, opcode, line_number, arg);
		}
	}
	free_stack(stack);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
