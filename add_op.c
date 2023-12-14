#include "monty.h"

/**
 * add_op - adds the top two elements of a stack
 * @top: pointer to the top of the stack
 * @line_number: line number of the opcode
 */

void add_op(stack_t **top, unsigned int line_number)
{
	globals_t globals = {0};


	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: cant't add, stack too short\n", line_number);
		free(globals.current_line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n += (*top)->n;
	pop_op(top, line_number);
}
