#include "monty.h"

/**
 * parseMontyFile - Parses a monty file.
 *
 * @fd: File descriptor of the file to file.
 * The file must be opened with at least reading enabled.
 *
 * Return: EXIT_SUCCESS.
 */
int parseMontyFile(int fd)
{
	char line[BUFF_SIZE];
	off_t offset = 0;
	int lineNum = 1;
	stack_t *stack;

	stack = NULL;
	while (_read_line(line, fd, BUFF_SIZE, &offset) != -1)
	{
		_parseMontyLine(&stack, line, lineNum);
		++lineNum;
	}

	free_stack(stack);
	return (EXIT_SUCCESS);
}

/**
 * _parseMontyLine - Parses a monty file
 * line instruction.
 *
 * @stack: A doule pointer to the stack.
 * @line: The line to parse.
 * @num: The number of the line.
 */
void _parseMontyLine(stack_t **stack, char *line, int num)
{
	char *opcode;
	int i;
	int f_size;
	instruction_t executors[] = {
		{"push", exec_push},
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		{"swap", exec_swap},
		{"add", exec_add},
		{"sub", exec_sub},
		{"div", exec_div},
		{"mul", exec_mul},
		{"mod", exec_mod},
		{"pchar", exec_pchar},
		{"pstr", exec_pstr},
	};

	f_size = sizeof(executors) / sizeof(executors[0]);
	opcode = strtok(line, " ");
	if (opcode == NULL || strcmp(opcode, "nop") == 0 ||
		opcode[0] == '#')
		return;

	argument = strtok(NULL, " ");
	/*printf("opcode = %s, arguemnt = %s\n", opcode, argument);*/
	for (i = 0; i < f_size; i++)
		if (strcmp(executors[i].opcode, opcode) == 0)
		{
			executors[i].f(stack, num);
			return;
		}

	fprintf(stderr, "L%d: unknown instruction %s\n",
		num, opcode);
	exit(EXIT_FAILURE);
}