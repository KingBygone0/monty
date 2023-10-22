#include "monty.h"

/**
 * execute_opcode - Execute the specified Monty bytecode opcode.
 * @stack: A pointer to the top of the stack.
 * @opcode: The opcode to execute.
 * @line_number: The current line number in the Monty bytecode file.
 * @args: The argument associated with the opcode.
 */
void execute_opcode(stack_t **stack, char *opcode,
		unsigned int line_number, char *args)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", mod},
		{NULL, NULL}
	};

	arg = args;
	i = 0;
	while (instructions[i].opcode)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
