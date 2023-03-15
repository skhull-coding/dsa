#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Multiple paranthesis matching program

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

char pop(pStack stack)
{
    if (!isEmpty(stack))
    {
        pNode ptr = stack->top;
        stack->top = ptr->next;
        char val = ptr->data;
        free(ptr);
        return val;
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
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(brackets, expression[i]);
        }
        else if (expression[i] == ')')
        {
            char res = pop(brackets);
            if (res == 0 || res != '(')
            {
                clearStack(brackets);
                return 0;
            }
        }
        else if (expression[i] == '}')
        {
            char res = pop(brackets);
            if (res == 0 || res != '{')
            {
                clearStack(brackets);
                return 0;
            }
        }
        else if (expression[i] == ']')
        {
            char res = pop(brackets);
            if (res == 0 || res != '[')
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
    char string[] = "([a*a-(3+2])";

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