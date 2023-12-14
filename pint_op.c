#include "monty.h"

/**
 * pint_op - prints the value at the top of the stack
 * @top: pointer to the top of the stack
 * @line_number: line number of the opcode
 */

void pint_op(stack_t **top, unsigned int line_number)
{
	globals_t globals = {0};


	if (*top == NULL)
	{
		fprintf(stderr, "L%d: cant't pint, stack empty\n", line_number);
		free(globals.current_line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}
