#include <stdio.h>
#include <stdlib.h>

// Queue
// FIFO - first in first out

// Operations = enqueue, dequeue, firstVal, lastVal, peek, isEmpty, isFull

// Using Arrays

typedef struct QUEUE
{
    int first, last, size;
    int *arr;
} Queue;
typedef Queue *pQueue;

pQueue createQueue(int size)
{
    pQueue queue = (pQueue)malloc(sizeof(Queue));
    queue->first = 0;
    queue->last = -1;
    queue->size = size;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

void printQueue(pQueue queue)
{
    for (int p = queue->first; p < queue->last + 1; p++)
    {
        printf("%d ", (queue->arr)[p]);
    }
    printf("\n");
}

int isEmpty(pQueue queue)
{
    return queue->last == -1;
}
int isFull(pQueue queue)
{
    return queue->last >= queue->size - 1;
}

void enqueue(pQueue queue, int data)
{
    if (!isFull(queue))
    {
        queue->last += 1;
        (queue->arr)[queue->last] = data;
    }
    else
    {
        printf("Couldn't do it .\n");
    }
}

int dequeue(pQueue queue)
{
    if (!isEmpty(queue))
    {
        int val = (queue->arr)[queue->first];
        for (int i = 0; i < queue->last; i++)
        {
            (queue->arr)[i] = (queue->arr)[i + 1];
        }
        queue->last -= 1;
        return val;
    }
    else
    {
        printf("Couldn't do it!\n");
        return -1;
    }
}

int valAtFirst(pQueue queue)
{
    if (!isEmpty(queue))
    {
        return (queue->arr)[queue->first];
    }
    return -1;
}

int valAtLast(pQueue queue)
{
    if (!isEmpty(queue))
    {
        return (queue->arr)[queue->last];
    }
    return -1;
}

int qPeek(pQueue queue, int pos)
{
    if (!isEmpty(queue) && pos > queue->first && pos < queue->last + 2)
    {
        return (queue->arr)[pos - 1];
    }
    return -1;
}

void clearQueue(pQueue queue)
{
    free(queue->arr);
    free(queue);
}

int main()
{
    pQueue trainLine = createQueue(10);

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
    enqueue(trainLine, 43);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    enqueue(trainLine, 1);

    printQueue(trainLine);
    printf("%d %d", valAtFirst(trainLine), valAtLast(trainLine));
    printf("\n%d", qPeek(trainLine, 1));

    clearQueue(trainLine);

    return 0;
}