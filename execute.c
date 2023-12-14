#include "monty.h"
#include <stdio.h>

/**
 * execute_file - executes opcodes from file
 * @top: pointer to the top of the stack
 */

void execute_file(stack_t **top)
{
	unsigned int line_number = 0;
	globals_t globals = {0};

	while (fgets(globals.current_line, MAX_ARG_LENGTH, globals.file) != NULL)
	{
		char *opcode = strtok(globals.current_line, " \t\r\n\a");

		globals.argument = strtok(NULL, " \n\t");



		line_number++;

		if (globals.current_line[strlen(globals.current_line) - 1] == '\n')
			globals.current_line[strlen(globals.current_line) - 1] = '\0';


		if (opcode == NULL || *opcode == '#')
			continue;

		exec_opcode(opcode, top, line_number);
	}
}
