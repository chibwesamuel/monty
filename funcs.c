#include "monty.h"

/**
 * _read_line - Reads a line from an open file descriptor.
 *
 *
 * @buff: A pointer to character strings for storing
 * the read line. AKA buffer.
 * @fd: An open file descriptor.
 * @len: The buffer size.
 * @offset: A pointer to an off_t, used as the starting point for
 * the new line.
 *
 * Return: 1 on success or -1 on failure or on EOF reached.
 */
int _read_line(char *buff, int fd, size_t len, off_t *offset)
{
	int rCount, i = 0;

	if (lseek(fd, *offset, SEEK_SET) == -1)
		return (-1);

	rCount = read(fd, buff, len);
	if (rCount <= 0)
		return (-1);

	while (i < rCount && *(buff + i) != '\n')
		i++;

	/* End the buffers at the end of the line => read line :) */
	*(buff + i) = '\0';

	/* i = rCount means no need to skip an extra \n  */
	*offset += i == rCount ? i : i + 1;
	return (1);
}


/**
 * print_and_exit - Print an error message to stderr
 * and exit with EXIT_FAILURE.
 *
 *
 * @error: The error message.
 *
 *
 * Return: EXIT_FAILURE
 */
int print_and_exit(char *error)
{
	fprintf(stderr, "%s\n", error);
	exit(EXIT_FAILURE);
}