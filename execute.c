#include "monty.h"
/**
 * execute_opcode - Executes an opcode based on its name
 * @opcode: The name of the opcode to execute
 * @stack: An array representing the stack
 * @line_number: A pointer to the current line number
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
if (strcmp(opcode, "pall") == 0)
pall(stack, line_number);
else if (strcmp(opcode, "pint") == 0)
pint(stack, line_number);
else if (strcmp(opcode, "pop") == 0)
pop(stack, line_number);
else if (strcmp(opcode, "swap") == 0)
swap(stack, line_number);
else if (strcmp(opcode, "add") == 0)
add(stack, line_number);
else if (strcmp(opcode, "sub") == 0)
sub(stack, line_number);
else if (strcmp(opcode, "mul") == 0)
_mul(stack, line_number);
else if (strcmp(opcode, "div") == 0)
_div(stack, line_number);
else if (strcmp(opcode, "mod") == 0)
_mod(stack, line_number);
else if (strcmp(opcode, "pchar") == 0)
pchar(stack, line_number);
else if (strcmp(opcode, "pstr") == 0)
pstr(stack, line_number);
else if (strcmp(opcode, "nop") == 0)
nop(stack, line_number);
else
{
printf("Unknown opcode: %s\n", opcode);
}
}
