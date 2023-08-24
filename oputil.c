#include "monty.h"

/**
 * create_instruction - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_instruction()
{
	instruction_t *instruction = malloc(sizeof(instruction_t) * 18);

	if (!instruction)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	instruction[0].opcode = "pall", instruction[0].f = pall_stack;
	instruction[1].opcode = "push", instruction[1].f = push_stack;

	return (instruction);
}

/**
 * clear_all - Clean all mallocs
 */
void clear_all()
{
	if (var.buffer != NULL)
	{
		free(var.buffer);
	}

	if (var.file != NULL)
	{
		fclose(var.file);
	}

	free(var.dictionary);

	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}

		free(var.head);
	}
}

/**
 * start_global_vars - Start variables
 * @var: Global variables to initialize
 * Return: 0 or 1
 */
int start_global_vars(vars *var)
{
	var->file = NULL;
	var->buffer = NULL;
	var->tmp = 0;
	var->dictionary = create_instruction();

	if (var->dictionary == NULL)
		return (EXIT_FAILURE);

	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * isNumber - Clean all program mallocs
 * @string: Number to validate
 * Return: 0, 1
 */
int isNumber(char *string)
{
	int index;

	for (index = 0; string[index]; index++)
	{
		if (string[index] < 48 || string[index] > 57)
			return (1);
	}

	return (0);
}

/**
 * call_function - Calling function
 * @var: Global variables
 * @opcode: Command to execute
 * Return: 0 or 1
 */
int call_function(vars *var, char *opcode)
{
	int i;

	for (i = 0; var->dictionary[i].opcode; i++)
		if (strcmp(opcode, var->dictionary[i].opcode) == 0)
		{
			if (!var->dictionary[i].f)
				return (EXIT_SUCCESS);
			var->dictionary[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

