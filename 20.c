#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Paranthesis matching
// Conditions for paranthesis matching with stack
// - While popping, stack should not underflow- if it happens, unbalanced
// - At End of expression (EOE), the stack mush be empty

typedef struct NODE
{
    char data;
    struct NODE *next;
} NODE;
typedef NODE *pNode;

typedef struct STACK
{
    pNode top;
} STACK;
typedef STACK *pStack;

pNode createNode(char data)
{
    pNode node = (pNode)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

pStack createStack()
{
    pStack stack = (pStack)malloc(sizeof(STACK));
    stack->top = NULL;
    return stack;
}

int isEmpty(pStack stack)
{
    return stack->top == NULL;
}

int isFull(pStack stack)
{
    pNode temp = createNode('0');
    if (temp == NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
}

void push(pStack stack, char data)
{
    if (!isFull(stack))
    {
        pNode node = createNode(data);
        node->next = stack->top;
        stack->top = node;
    }
}

int pop(pStack stack)
{
    if (!isEmpty(stack))
    {
        pNode ptr = stack->top;
        stack->top = ptr->next;
        free(ptr);
        return 1;
    }
    return 0;
}

void clearStack(pStack stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

int paranthesisMatching(char expression[])
{
    pStack brackets = createStack();

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(')
        {
            push(brackets, '(');
        }
        else if (expression[i] == ')')
        {
            int res = pop(brackets);
            if (!res)
            {
                clearStack(brackets);
                return 0;
            }
        }
    }
    if (!isEmpty(brackets))
    {
        clearStack(brackets);
        return 0;
    }
    clearStack(brackets);
    return 1;
}

int main()
{
    char string[] = "((8*(9))";

    if (paranthesisMatching(string))
    {
        printf("Brackets are balanced!");
    }
    else
    {
        printf("Brackets are not balanced!");
    }

    return 0;
}