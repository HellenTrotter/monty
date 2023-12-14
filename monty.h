#ifndef MONTY_H
#define MONTY_H

#define MAX_OPCODE_LENGTH 10
#define MAX_ARG_LENGTH 20
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globals - variables-> argument, file, line
 * @argument: value
 * @file: pointer to file
 * @current_line: input line content
 */

typedef struct globals
{
	char *argument;
	FILE *file;
	char *current_line;
} globals_t;

extern globals_t globals;

void push_op(stack_t **top, unsigned int line_number);
void pall_op(stack_t **top, unsigned int line_number);
int _is_number(char *str);
void free_stack(stack_t *top);
stack_t *_add_node(stack_t **top, const int l);
void execute_file(stack_t **top);
void exec_opcode(char *opcode, stack_t **top, unsigned int line_number);
void pint_op(stack_t **top, unsigned int line_number);
void pop_op(stack_t **top, unsigned int line_number);
void add_op(stack_t **top, unsigned int line_number);
void swap_op(stack_t **top, unsigned int line_number);
void nop_op(stack_t **top, unsigned int line_number);


#endif

