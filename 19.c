#include <stdio.h>
#include <stdlib.h>

// Stack using linked list by myself
// no size constraints

// Node for using Linked List
typedef struct NODE
{
    int data;
    struct NODE *next;
} Node;
typedef Node *pNode;

// Create Node - O(1)
pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL; // for not making it a wild pointer
    return node;
}

// Stack Structure
// Contains a pointer to the head node of the linked list
typedef struct STACK
{
    pNode top;
} Stack;
typedef Stack *pStack;

// Create Stack - O(1)
pStack createStack()
{
    pStack stack = (pStack)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Print stack Top ... Bottom - O(n)
void printStack(pStack stack)
{
    pNode ptr = stack->top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Push at top in the stack - O(1)
void push(pStack stack, int data)
{
    pNode node = createNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Checks if the stack is empty or not - O(1)
int isEmpty(pStack stack)
{
    return stack->top == NULL;
}

// Delete the top node and returns its value - O(1)
int pop(pStack stack)
{
    if (!isEmpty(stack))
    {
        pNode temp = stack->top;
        stack->top = temp->next;
        int data = temp->data;
        free(temp);  // freeing the memory while popping
        temp = NULL; // to not make it a dangling pointer
        return data;
    }
    else
    {
        return -1;
    }
}

// Peeks at what position the value is O(n)
int peek(pStack stack, int pos)
{
    int i = 1;
    pNode ptr = stack->top;
    while (i != pos && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (i == pos && ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

// returns the value at the top of the stack - O(1)
int stackTop(pStack stack)
{
    if (!isEmpty(stack))
    {
        return (stack->top)->data;
    }
    return -1;
}

// returns the value at the bottom of the stack - O(n)
int stackBottom(pStack stack)
{
    if (!isEmpty(stack))
    {
        pNode ptr = stack->top;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }
    return -1;
}

int main()
{
    pStack nS = createStack();

    printStack(nS);

    push(nS, 23);
    push(nS, 13);
    push(nS, 36);
    push(nS, 4);

    pop(nS);
    pop(nS);
    pop(nS);
    push(nS, 3);
    push(nS, 88);
    pop(nS);

    pop(nS);
    push(nS, 678);
    push(nS, 45);
    pop(nS);
    pop(nS);

    push(nS, 78);
    push(nS, 79);
    push(nS, 80);
    push(nS, 91);

    printStack(nS);
    printf("%d\n", peek(nS, 3));
    printf("%d\n", stackTop(nS));
    printf("%d", stackBottom(nS));
    return 0;
}