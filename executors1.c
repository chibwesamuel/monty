#include "monty.h"

/**
 * exec_add - adds the top two elements of the stack.
 *
 * @stack: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack);
	*stack = tmp->next;

	(*stack)->n += tmp->n;
	(*stack)->prev = NULL;

	free(tmp);
	argument = NULL;
}

/**
 * exec_sub - subtracts the top element of the stack
 * from the second top element of the stack.
 *
 * @stack: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack);
	*stack = tmp->next;

	(*stack)->n -= tmp->n;
	(*stack)->prev = NULL;

	free(tmp);
	argument = NULL;
}

/**
 * exec_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @stack: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack);
	*stack = tmp->next;

	(*stack)->n *= tmp->n;
	(*stack)->prev = NULL;

	free(tmp);
	argument = NULL;
}

/**
 * exec_div - divides the second top element
 * of the stack by the top element of the stack.
 *
 * @stack: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack);
	*stack = tmp->next;

	(*stack)->n /= tmp->n;
	(*stack)->prev = NULL;

	free(tmp);
	argument = NULL;
}

/**
 * exec_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @stack: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack);
	*stack = tmp->next;

	(*stack)->n %= tmp->n;
	(*stack)->prev = NULL;

	free(tmp);
	argument = NULL;
}