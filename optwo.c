#include "monty.h"

/**
 * pop_stack - Delete top of the stack list
 * @stack: linked list
 * @line_number: line execution
 * @mode: mode number
 * Return: 0 or 1
 */
int pop_stack(stack_tt **stack,
			  unsigned int line_number,
			  __attribute__((unused)) int mode)
{
	stack_tt *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
	return (EXIT_SUCCESS);
}

/**
 * swap_stack - Delete top of stack list
 * @stack: linked list
 * @line_number: line execution
 * @mode: mode number
 * Return: 0 or 1
 */
int swap_stack(stack_tt **stack,
			   unsigned int line_number,
			   __attribute__((unused)) int mode)
{
	int tmp_value;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		return (EXIT_FAILURE);
	}
	tmp_value = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp_value;
	return (EXIT_SUCCESS);
}

