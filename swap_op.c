#include "monty.h"


/**
 * swap_op - swaps the top two elements of the stack
 * @top: pointer to the top of the stack
 * @line_number: line number of the opcode
 */

void swap_op(stack_t **top, unsigned int line_number)
{
	stack_t *first, *second;
	globals_t globals = {0};


	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n", line_number);
		free(globals.current_line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	first = *top;
	second = first->next;

	first->next = second->next;

	if (second->next != NULL)
	{
		second->next->prev = first;

	}

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*top = second;
}
