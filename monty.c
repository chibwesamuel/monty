#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/***
 * push - function that pushes an element to the stack
 * pall - prints all values on the stack, starting from the top of the stack
 * @x: stack count
 *
 * Return: 0 on success
 */

int stack[256];
int count = 0;

void push(int x)
{
    if (count == 256)
    {
        fprintf(stderr, "Stack full");
        return;
    }
    stack[count] = x;
    count++;
}

int pall()
{
    if (count == 0)
    {
        fprintf(stderr, "Stack is empty");
        return (-1);
    }
    int res = stack[count - 1];
    count--;
    return (res);
}

int main(int argc, char* argv[])
{
    push(1);
    push(2);
    push(3);

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d ", pall());
    }

    return (0);
}
