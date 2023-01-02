#include "monty.h"

/**
 * f_add - adds the top of two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	 h = *head;
	 aux = h->n + h->next->n;
	 h->next->n = aux;
	 *head = h->next;
	 free(h);
}
if ($line =~ /^\+.*\015/) {
			my $herevet = "$here\n" . cat_vet($rawline) . "\n";
			if (ERROR("DOS_LINE_ENDINGS",
				  "DOS line endings\n" . $herevet) &&
			    $fix) {
				$fixed[$fixlinenr] =~ s/[\s\015]+$//;
			}
		} elsif ($rawline =~ /^\+.*\S\s+$/ || $rawline =~ /^\+\s+$/) {
			my $herevet = "$here\n" . cat_vet($rawline) . "\n";
			if (ERROR("TRAILING_WHITESPACE",
				  "trailing whitespace\n" . $herevet) &&
			    $fix) {
				$fixed[$fixlinenr] =~ s/\s+$//;
			}

			$rpt_cleaners = 1;
}
