#include "monty.h"


/**
 * setMode - Sets the mode to stack or queue
 * @is_stack: A boolean indicating if the mode is stack (true) or queue (false)
 */
void setMode(bool is_stack)
{
bool mode_stack = true;

mode_stack = is_stack;
}

/**
 * isStackMode - Checks if the current mode is stack
 * Return: true if the mode is stack, false otherwise
 */
bool isStackMode(void)
{
bool mode_stack = true;

return (mode_stack);
}

/**
 * isQueueMode - Checks if the current mode is queue
 * Return: true if the mode is queue, false otherwise
 */
bool isQueueMode(void)
{
bool mode_stack = true;

return (!mode_stack);
}

/**
 * executeOpcode - Execute the specified Monty bytecode opcode.
 * @stack: A pointer to the top of the stack.
 * @opcode: The opcode to execute.
 * @line_number: The current line number in the Monty bytecode file.
 */

void executeOpcode(stack_t **stack, char *opcode, unsigned int line_number)
{
char *arg;
int value;

if (opcode[0] == '#')
{

}
else if (strcmp(opcode, "push") == 0)
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
else if (opcode != NULL)
execute_opcode(opcode, stack, line_number);
else if (strcmp(opcode, "rotr") == 0)
rotr(stack, line_number);
else if (strcmp(opcode, "rot1") == 0)
rotl(stack, line_number);
else if (strcmp(opcode, "stack") == 0)
setMode(true);
else if (strcmp(opcode, "queue") == 0)
setMode(false);
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
