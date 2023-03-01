#include "monty.h"


/**
 * exec_pchar - prints the char at the top of the stack,
 * followed by a new line.
 *
 * @stack: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
	argument = NULL;
}

/**
 * exec_pstr - prints the string starting at the top
 * of the stack, followed by a new line.
 *
 * @stack: A double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 */
void exec_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t  *p;

	(void) line_number;
	p = stack ? *stack : NULL;
	while (p)
	{
		if (p->n <= 0 || p->n > 127)
			break;
		printf("%c", (char) p->n);
		p = p->next;
	}
	puts("");
}