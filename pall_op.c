#include "monty.h"

/**
 * pall_op - prints all values in a stack
 * @top: pointer to the top of the stack
 * @line_number: line number of the opcode
 */

void pall_op(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		(void)line_number;
	}
}
