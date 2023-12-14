#include "monty.h"

/**
 * push_op - pushes an element onto the stack
 * @top: pointer to the top of the stack
 * @line_number: current line number of opcode
 */

void push_op(stack_t **top, unsigned int line_number)
{
	int i;

	if (globals.argument == NULL || _is_number(globals.argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*top);
		fclose(globals.file);
		free(globals.current_line);
		exit(EXIT_FAILURE);
	}

	i = atoi(globals.argument);

	if (_add_node(top, i) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*top);
		fclose(globals.file);
		free(globals.current_line);
		exit(EXIT_FAILURE);
	}


}
