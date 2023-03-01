#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define BUFF_SIZE 200

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int print_and_exit(char *error);
int _read_line(char *buff, int fd, size_t len, off_t *offset);

int parseMontyFile(int fd);
void _parseMontyLine(stack_t **, char *line, int num);

void execute(char *opcode, unsigned int line_number);
void push(stack_t **stack, int n);
void pall(stack_t **stack);

void exec_push(stack_t **stack_arg, unsigned int ine_number);
void exec_pall(stack_t **stack_arg, unsigned int line_number);
void exec_pint(stack_t **stack_arg, unsigned int line_number);
void exec_pop(stack_t **stack_arg, unsigned int line_number);
void exec_swap(stack_t **stack_arg, unsigned int line_number);
void exec_add(stack_t **stack_arg, unsigned int line_number);
void exec_sub(stack_t **stack_arg, unsigned int line_number);
void exec_div(stack_t **stack_arg, unsigned int line_number);
void exec_mul(stack_t **stack_arg, unsigned int line_number);
void exec_mod(stack_t **stack_arg, unsigned int line_number);
void exec_pchar(stack_t **stack_arg, unsigned int line_number);
void exec_pstr(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

extern char *argument;
#endif /* MONTY_H */