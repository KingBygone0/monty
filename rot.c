#include "monty.h"
/**
 * rotl - Rotates the stack to the top (rotl opcode)
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;
	stack_t *current;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		new_top = (*stack)->next;
		current = *stack;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = *stack;
		(*stack)->prev = current;
		(*stack)->next = NULL;
		*stack = new_top;
		(*stack)->prev = NULL;
	}
}

/**
 * rotr - Rotates the stack to the bottom (rotr opcode)
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		current = *stack;
		while (current->next != NULL)
		{
			current = current->next;
		}

	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
	}
}
