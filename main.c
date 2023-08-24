#include "monty.h"

/**
 * main - Start program
 * @number_of_arg: Number of arguments
 * @av: Pointer containing arguments
 * Return: success or fail
 */
int main(int number_of_arg, char **av)
{
	char *opcode;
	vars var;

	if (number_of_arg != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_global_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");

	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		clear_all(&var);

		return (EXIT_FAILURE);
	}

	while (getline(&var.buffer, &var.tmp, var.file) != EOF)
	{
		opcode = strtok(var.buffer, " \r\t\n");
		if (opcode != NULL)
			if (call_function(&var, opcode) == EXIT_FAILURE)
			{
				clear_all(&var);
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	clear_all(&var);

	return (EXIT_SUCCESS);
}

