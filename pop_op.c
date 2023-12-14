#include "monty.h"

/**
 * pop_op - removes the top element of the stack
 * @top: pointer to the top of the stack
 * @line_number: line number of opcode
 * Return: 0(success)
 */

void pop_op(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	globals_t globals = {0};

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(globals.current_line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	tmp = (*top)->next;
	free(*top);
	*top = tmp;

	if (*top != NULL)
		(*top)->prev = NULL;
}
