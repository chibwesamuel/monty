#include "monty.h"

/**
 * push - Pushes an element at the top of the stack.
 *
 * @n: The value of the element.
 * @stack: A double pointer to the top
 * of the stack.
 */
void push(stack_t **stack, int n)
{
	stack_t *elt;

	elt = malloc(sizeof(elt));
	if (elt == NULL)
		print_and_exit("Error: malloc failed");

	elt->n = n;
	elt->prev = NULL;
	elt->next = NULL;
	if (stack == NULL)
		stack = &elt;
	else if (*stack)
	{
		elt->next = *stack;
		(*stack)->prev = elt;
		*stack = elt;
	}
	else
		*stack = elt;
	/*
	 * printf("stack = %p , *stack %p\n", (void *)stack , (void *)*stack);
	 */
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: A double pointer to the top
 * of the stack.
 */
void pall(stack_t **stack)
{
	stack_t *tmp;

	tmp = stack != NULL ? *stack : NULL;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - Frees memory used by
 * the stack.
 *
 * @stack: A pointer to the top
 * of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
Footer
© 2023 GitHub, Inc.
Footer navigation

    Terms
    Privacy
    Security
    Status
    Docs
    Contact GitHub
    Pricing
    API
    Training
    Blog
    About