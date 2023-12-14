#include "monty.h"

globals_t globals;

/**
 * main - entry point
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	globals.file = fopen(argv[1], "r");

	if (globals.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_file(&top);

	fclose(globals.file);

	free(globals.current_line);
	free_stack(top);

	exit(EXIT_SUCCESS);
}



/**
 * exec_opcode - executes a single opcode
 * @opcode: opcode to execute
 * @top: pointer to the top of the stack
 * @line_number- line number of opcode
 */

void exec_opcode(char *opcode, stack_t **top, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{NULL, NULL}
	};

	int l;

	for (l = 0; instructions[l].opcode != NULL; l++)
	{
		if (strcmp(opcode, instructions[l].opcode) == 0)
		{
			instructions[l].f(top, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*top);
	free(globals.current_line);
	exit(EXIT_FAILURE);
}
