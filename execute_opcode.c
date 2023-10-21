#include "monty.h"

/**
 * executeOpcode - Execute the specified Monty bytecode opcode.
 * @stack: A pointer to the top of the stack.
 * @opcode: The opcode to execute.
 * @line_number: The current line number in the Monty bytecode file.
 */
void executeOpcode(stack_t **stack, char *opcode, unsigned int line_number)
{
int value;
char *arg;

if (strcmp(opcode, "push") == 0)
{
arg = strtok(NULL, " \n");
if (arg == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
value = atoi(arg);
push(stack, value);
}
else if (strcmp(opcode, "pall") == 0)
pall(stack, line_number);
else if (strcmp(opcode, "pint") == 0)
pint(stack, line_number);
else if (strcmp(opcode, "pop") == 0)
pop(stack, line_number);
else if (strcmp(opcode, "swap") == 0)
swap(stack, line_number);
else if (strcmp(opcode, "add") == 0)
add(stack, line_number);
else if (strcmp(opcode, "nop") == 0)
nop(stack, line_number);
else if (strcmp(opcode, "sub") == 0)
sub(stack, line_number);
else if (strcmp(opcode, "div") == 0)
_div(stack, line_number);
else if (strcmp(opcode, "mul") == 0)
_mul(stack, line_number);
else if (strcmp(opcode, "mod") == 0)
_mod(stack, line_number);
else if (strcmp(opcode, "pchar") == 0)
pchar(stack, line_number);
else if (strcmp(opcode, "pstr") == 0)
pstr(stack, line_number);
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
