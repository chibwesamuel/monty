#include <stdio.h>
#include <stdarg.h>
#include "monty.h"

char *argument = NULL;

/**
 * main - Main function of the MontyBytesCode interpreter.
 *
 * @ac: Argument count (int).
 * @av: A pointer to pointers to character strings (c strings).
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE on failure.
 */
int main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		print_and_exit("USAGE: monty file");

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	parseMontyFile(fd);
	exit(EXIT_SUCCESS);
}