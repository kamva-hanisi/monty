#include "monty.h"

/**
 * pop_stack - Delete top of the stack list
 * @mode: list
 * @stack: linked list
 * @line_number: line execution
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

