#include <stdbool.h>
#include "monty.h"
#include <ctype.h>
/**
 * is_number - Check if a string represents a valid integer.
 * @str: The string to check.
 *
 * Return: true if str is a valid integer, false otherwise.
 */
bool is_number(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
	{
	return (false);  /* NULL or empty string is not a valid number */
	}

	/* Check each character in the string */
	for (i = 0; str[i] != '\0'; i++)
	{
	/* If the character is not a digit and not the negative sign */
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-'))
		{
		return (false);  /* Not a valid number */
		}
	}
	return (true);  /* All characters are either digits or the negative sign */
}
