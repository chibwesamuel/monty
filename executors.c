#include "monty.h"


/**
 * exec_push - validates the argument and
 * call the push function.
 *
 * @stack_arg: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_push(stack_t **stack_arg, unsigned int line_number)
{
	int n;
	int i;

	i = 0;
	while (argument && argument[i])
	{
		if ((argument[i] != '-' && argument[i] != '+') &&
		(argument[i] < '0' || argument[i] > '9'))
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	else if ((strcmp(argument, "0") == 0 ||
		strcmp(argument, "-0") == 0))
		n = 0;
	else
	{
		n = atoi(argument);
		if (n == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}
	}

	push(stack_arg, n);
	argument = NULL;
}


/**
 * exec_pall -  prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack_arg: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_pall(stack_t **stack_arg, unsigned int line_number)
{
	(void) line_number;
	pall(stack_arg);
	argument = NULL;
}


/**
 * exec_pint - Prints the value at the top
 * of the stack, followed by a new line.
 *
 * @stack_arg: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_pint(stack_t **stack_arg, unsigned int line_number)
{
	if (!stack_arg || !(*stack_arg))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack_arg)->n);
	argument = NULL;
}


/**
 * exec_pop - removes the top element of the stack.
 *
 * @stack_arg: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_pop(stack_t **stack_arg, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack_arg || !(*stack_arg))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack_arg;
	*stack_arg = (*stack_arg)->next;
	free(tmp);
	argument = NULL;
}


/**
 * exec_swap - swaps the top two elements of the stack.
 *
 * @stack_arg: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_swap(stack_t **stack_arg, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack_arg || !(*stack_arg) || !(*stack_arg)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack_arg;
	*stack_arg = (*stack_arg)->next;

	if (tmp->next->next)
		tmp->next->next->prev = tmp;
	tmp->next = tmp->next->next;
	tmp->prev = *stack_arg;

	(*stack_arg)->next = tmp;
	(*stack_arg)->prev = NULL;
	argument = NULL;
}