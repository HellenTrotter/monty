#include "monty.h"

/**
 * free_stack - frees stack_t list
 * @top: pointer to the top of the stack
 */

void free_stack(stack_t *top)
{
	stack_t *current;

	while (top != NULL)
	{
		current = top;
		top = top->next;
		free(current);
	}
}



/**
 * _add_node - adds a new nodeat the beginning of a stack_t list
 * @top: pointer to a pointer of the top of the stack
 * @n: value to ne added to the node
 * Return: pointer to the new node
 */

stack_t *_add_node(stack_t **top, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error:malloc failed\n");
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*top == NULL)
	{
		new->next = NULL;
	}
	else
	{
		new->next = *top;
		(*top)->prev = new;
	}

	*top = new;
	return (new);
}
