#include "monty.h"
/**
 * pstr - Prints the string starting at the top of the stack (pstr opcode)
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		value = current->n;
		if (value == 0 || value < 0 || value > 127)
		{
			break;
		}
	putchar(value);
	current = current->next;
	}
	putchar('\n');
}

/**
 * pchar - Prints the character at the top of the stack (pchar opcode)
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(value);
	putchar('\n');
}
