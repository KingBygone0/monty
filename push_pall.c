#include "monty.h"

/**
 * push - pushes an element onto the stack.
 * @stack: pointer to the top of the stack.
 * @value: value to operate on
 */
void push(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
