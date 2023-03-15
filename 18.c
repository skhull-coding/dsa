#include <stdio.h>
#include <stdlib.h>

// Stack ADT
// operations
// - push, pop, peek, is empty and is full

typedef struct stack
{
    int size;
    int top;
    int *arr;
} Stack;
typedef Stack *pStack;

pStack createStack(int size)
{
    pStack stack = (pStack)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = (size - 1);
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    return stack;
}

int isEmpty(pStack stack)
{
    return (stack->top <= -1);
}

int isFull(pStack stack)
{
    return (stack->top >= stack->size);
}

void printStack(pStack stack)
{
    printf("Stack : ");
    for (int i = 0; i < (stack->top) + 1; i++)
    {
        printf("%d ", (stack->arr)[i]);
    }
    printf("\n");
}

int push(pStack stack, int element)
{
    if (!isFull(stack))
    {
        (stack->top) += 1;
        (stack->arr)[stack->top] = element;
    }
    else
    {
        printf("Cannot Push!!\n");
        return -1;
    }
    return stack->top;
}

int pop(pStack stack)
{
    if (!isEmpty(stack))
    {
        (stack->top) -= 1;
        return (stack->arr)[stack->top + 1];
    }
    else
    {
        printf("Cannot Pop!!\n");
        return 0;
    }
}

int peek(pStack stack, int index)
{
    if (index > stack->top + 1 || index < 1)
    {
        printf("Cannot find!!\n");
        return -1;
    }
    else
    {
        return (stack->arr)[stack->top - index + 1];
    }
}

int stackTop(pStack stack)
{
    if (!isEmpty(stack))
    {
        return stack->arr[stack->top];
    }
    return -1;
}
int stackBottom(pStack stack)
{
    if (!isEmpty(stack))
    {
        return stack->arr[0];
    }
    return -1;
}

int main()
{

    pStack s = createStack(12);

    push(s, 45);
    push(s, 34);
    push(s, 341);
    push(s, 1);
    pop(s);
    pop(s);
    push(s, 31);

    printStack(s);
    printf("%d", peek(s, 4));

    return 0;
}