#include <stdio.h>
#include <stdlib.h>

// Queue with linked lists

typedef struct NODE
{
    int data;
    struct NODE *next;
} Node;
typedef Node *pNode;

typedef struct QUEUE
{
    pNode f, r;
} Queue;
typedef Queue *pQueue;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

pQueue createQueue()
{
    pQueue queue = (pQueue)malloc(sizeof(pQueue));
    queue->f = queue->r = NULL;
    return queue;
}

void printQueue(pQueue queue)
{
    pNode temp = queue->f;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty(pQueue queue)
{
    return (queue->f == NULL);
}

int isFull(pQueue queue)
{
    pNode temp = createNode(0);
    if (temp == NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
}

void enqueue(pQueue queue, int data)
{
    if (!isFull(queue))
    {
        pNode newNode = createNode(data);
        if (isEmpty(queue))
        {
            queue->f = newNode;
            queue->r = newNode;
        }
        else
        {
            queue->r->next = newNode;
            queue->r = newNode;
        }
    }
    else
    {
        printf("No space to add !!");
    }
}

int dequeue(pQueue queue)
{
    if (!isEmpty(queue))
    {
        pNode temp = queue->f;
        queue->f = temp->next;
        int data = temp->data;
        free(temp);
        return data;
    }
    return -1;
}

int lastVal(pQueue queue)
{
    if (!isEmpty(queue))
    {
        return queue->r->data;
    }
    return -1;
}

int firstVal(pQueue queue)
{
    if (!isEmpty(queue))
    {
        return queue->f->data;
    }
    return -1;
}

int peek(pQueue queue, int pos)
{
    if (!isEmpty(queue))
    {
        int i = 1;
        pNode temp = queue->f;
        while (i != pos && temp != queue->r)
        {
            temp = temp->next;
            i++;
        }
        if (i == pos)
        {
            return temp->data;
        }
    }

    return -1;
}

int main()
{
    pQueue trainLine = createQueue();

    enqueue(trainLine, 1);
    enqueue(trainLine, 2);
    enqueue(trainLine, 3);
    enqueue(trainLine, 4);
    enqueue(trainLine, 5);
    enqueue(trainLine, 6);
    enqueue(trainLine, 7);
    enqueue(trainLine, 8);
    enqueue(trainLine, 9);
    enqueue(trainLine, 10);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);

    printQueue(trainLine);
    printf("%d\n", lastVal(trainLine));
    printf("%d\n", firstVal(trainLine));

    printf("%d", peek(trainLine, 0));

    return 0;
}