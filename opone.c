#include "monty.h"

/**
 * pall_stack - Print stack list
 * @stack: linked list
 * @line_number: File line
 */
void pall_stack(stack_tt **stack, unsigned int line_number)
{
	stack_tt *tmp = *stack;
	(void)line_number;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * push_stack - Push new value in list
 * @stack: Double linked list
 * @line_number: File line
 */
void push_stack(stack_tt **stack, unsigned int line_number)
{
	stack_tt *tmp_value = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (isNumber(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		clear_all();
		exit(EXIT_FAILURE);
	}

	tmp_value = malloc(sizeof(stack_tt));

	if (!tmp_value)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clear_all();
		exit(EXIT_FAILURE);
	}

	tmp_value->n = atoi(num);

	if (var.MODE == 0 || !*stack)
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
}
