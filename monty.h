#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>
#define BUFFER_SIZE 30

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
} stack_tt;

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
	int (*f)(stack_tt **stack, unsigned int line_number, int mode);
} instruction_t;

/**
 * struct global_var - global variables
 * @file: file name
 * @buffer: Getline buffer
 * @tmp: Getline counter
 * @dictionary: instruction dictionary
 * @head: pointer to list
 * @line_number: Stores file current line
 * @MODE: configuration stack or queue
 */
typedef struct global_var
{
	FILE *file;
	char *buffer;
	size_t tmp;
	instruction_t *dictionary;
	stack_tt *head;
	unsigned int line_number;
	int MODE;
} vars;

extern vars var;

int pall_stack(stack_tt **stack, unsigned int line_number, int mode);
int push_stack(stack_tt **stack, unsigned int line_number, int mode);
int call_function(vars *var, char *opcode);
void clear_all(vars *var);
int isNumber(char *string);
int start_global_vars(vars *var);

#endif /* MONTY_H */

