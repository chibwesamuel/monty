#include "monty.h"
/**
* f_queue - prints the top
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
    (void) head;
    (void) counter;
    bus.lifi = 1;
}

/**
* addqueue - add node to the tail stack
* @n: new value
* @head: head of the stack
* Return: no return
*/
void addqueue(stack_t **head, int n)
{
    stack_t *new_code, *aux;

    aux = *head;
    new_code = malloc(sizeof(stack_t));
    if (new_code == NULL)
    {
        printf("Error\n");
    }
    new_code->n = n;
     new_code->next = NULL;
     if (aux)
     {
        while (aux->next)
                aux = aux->next;
     }
     if (!aux)
     {
        *head = new_code;
        new_code->prev = NULL;
     }
     else
     {
        aux->next = new_code;
        new_code->prev = aux;
     }
}