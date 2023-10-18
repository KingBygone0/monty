#include "monty.h"

/**
 * execute_opcode - Execute the specified Monty bytecode opcode.
 * @stack: A pointer to the top of the stack.
 * @instruction: The opcode to execute.
 * @line_number: The current line number in the Monty bytecode file.
 */
void execute_opcode(instruction_t *instruction, stack_t **stack,
		unsigned int line_number)
{
if (strcmp(instruction->opcode, "push") == 0)
push_func(stack, line_number);
else if (strcmp(instruction->opcode, "pall") == 0)
pall_func(stack, line_number);
else if (strcmp(instruction->opcode, "pint") == 0)
pint_func(stack, line_number);
else if (strcmp(instruction->opcode, "pop") == 0)
pop_func(stack, line_number);
/* Add more opcodes as needed...*/
else
{
/* Handle unknown opcodes or errors*/
fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
		instruction->opcode);
exit(EXIT_FAILURE);
}
}
