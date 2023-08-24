#include "monty.h"

/**
 * pint_stack - Printing last node
 * @stack: linked list
 * @line_number: line execution
 * @mode: number mode
 * Return: 0 or 1
 */
int pint_stack(stack_tt **stack,
			   unsigned int line_number,
			   __attribute__((unused)) int mode)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

		return (EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
	return (EXIT_SUCCESS);
}

/**
 * pall_stack - Print stack list
 * @stack: linked list
 * @line_number: File line
 * @mode: Global variable Mode
 * Return: 0 or 1
 */
int pall_stack(stack_tt **stack,
			   unsigned int line_number,
			   __attribute__((unused)) int mode)
{
	stack_tt *tmp = *stack;
	(void)line_number;

	if (!tmp)
		return (EXIT_SUCCESS);

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

/**
 * push_stack - Push new value in list
 * @stack: Double linked list
 * @line_number: File line
 * @mode: Global variable Mode
 * Return: 0 or 1
 */
int push_stack(stack_tt **stack, unsigned int line_number, int mode)
{
	stack_tt *tmp_value = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (isNumber(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}

	tmp_value = malloc(sizeof(stack_tt));

	if (!tmp_value)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	tmp_value->n = atoi(num);

	if (mode == 0 || !*stack)
	{
		tmp_value->next = *stack;
		tmp_value->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp_value;
		*stack = tmp_value;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp_value;
		tmp_value->prev = tm;
		tmp_value->next = NULL;
	}

	return (EXIT_SUCCESS);
}

