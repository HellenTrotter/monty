#include "monty.h"

/**
 * pop_op - removes the top element of the stack
 * @top: pointer to the top of the stack
 * @line_number: line number of opcode
 * Return: 0(success)
 */

int pop_op(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(globals.current_line);
		return (-1);
	}

	tmp = (*top)->next;
	free(*top);
	*top = tmp;

	if (*top != NULL)
		(*top)->prev = NULL;

	return (0);
}	
