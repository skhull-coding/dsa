#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Infix prefix and postfix
// Notations to write an expression
// Infix
//      - a+b
//      - a-b
//      - p/q
//      - x-4
// Operand <operator> operand
// Prefix
//      <Operator> operand1 operand2
// Postfix
//  operand1 operand2 <operator>

// Infix to postfix using stack

typedef struct NODE
{
    char data;
    int prefrence;
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
    node->prefrence = 0;
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

int prefStackTop(pStack stack)
{
    if (!isEmpty(stack))
    {
        return stack->top->prefrence;
    }
    return -1;
}

void push(pStack stack, char data)
{
    if (!isFull(stack))
    {
        pNode node = createNode(data);
        if (data == '-' || data == '+')
        {
            node->prefrence = 1;
        }
        else
        {
            node->prefrence = 2;
        }
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

char *ChangeToPostfixExpression(char expression[])
{
    char *postfixExp = (char *)malloc(sizeof(char) * (strlen(expression) + 1)); // for the last \0 character - null termination character
    pStack operators = createStack();
    int pref = 0;
    int j = 0;
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*' || expression[i] == '/')
        {
            if (expression[i] == '-' || expression[i] == '+')
            {
                pref = 1;
            }
            else
            {
                pref = 2;
            }

            while (prefStackTop(operators) >= pref)
            {
                postfixExp[j] = pop(operators);
                j++;
            }
            push(operators, expression[i]);
        }
        else
        {
            postfixExp[j] = expression[i];
            j++;
        }
    }
    while (!isEmpty(operators))
    {
        postfixExp[j] = pop(operators);
        j++;
    }
    clearStack(operators);
    postfixExp[j] = '\0';
    return postfixExp;
}

int main()
{
    char string[] = "2+3-2/2";
    char *pString = ChangeToPostfixExpression(string);

    printf("Postfixed Expression : %s", pString);
    free(pString);

    return 0;
}