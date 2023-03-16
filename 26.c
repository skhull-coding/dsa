#include <stdio.h>
#include <stdlib.h>

// Circular Imcrement
// i = i+1; -> Linear increment
// i = (i+1)%size -> Circular imcrement

// Linear Queue -> Space not used efficiently

// Circular Queue
// using circular queue to use the space efficiently

typedef struct CIRCULAR_QUEUE
{
    int f, r, size;
    int *arr;
} CQueue;
typedef CQueue *pCQueue;

pCQueue createQueue(int size)
{
    pCQueue queue = (pCQueue)malloc(sizeof(CQueue));
    queue->f = queue->r = -1;
    queue->size = size;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(pCQueue queue)
{
    return (queue->f == queue->r) && (queue->f == -1);
}

int isFull(pCQueue queue)
{
    return ((queue->f == queue->r) && (queue->f != -1) || (queue->r == queue->size - 1) && (queue->f == -1));
}

void printQueue(pCQueue queue)
{
    if (queue->arr == NULL)
    {
        printf("No Queue found to print");
    }
    else if (!isEmpty(queue))
    {
        int i = queue->f + 1;
        do
        {
            printf("%d ", (queue->arr)[i]);
            i = (i + 1) % queue->size;
        } while (i != queue->r + 1);
    }
    else
    {
        printf("Queue is empty!");
    }
    printf("\n");
}

int dequeue(pCQueue q)
{
    int val = -1;
    if (!isEmpty(q))
    {
        q->f = (q->f + 1) % q->size;
        val = (q->arr)[q->f];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
    }
    else
    {
        printf("Queue Underflow!!\n");
    }
    return val;
}

void enqueue(pCQueue q, int data)
{
    if (!isFull(q))
    {
        q->r = (q->r + 1) % q->size;
        (q->arr)[q->r] = data;
    }
    else
    {
        printf("Queue Overflow!!\n");
    }
}

int valAtFirst(pCQueue queue)
{
    if (!isEmpty(queue))
    {
        return (queue->arr)[queue->f + 1];
    }
    return -1;
}

int valAtLast(pCQueue queue)
{
    if (!isEmpty(queue))
    {
        return (queue->arr)[queue->r];
    }
    return -1;
}

void clearQueue(pCQueue queue)
{
    free(queue->arr);
    queue->arr = NULL; // to prevent dangling pointers
    free(queue);
    queue = NULL;
}

int qCPeek(pCQueue queue, int pos)
{
    if (!isEmpty(queue) && !(pos > queue->r - queue->f) && (pos > 0))
    {

        return ((queue->arr)[queue->f + pos]);
    }
    else
    {
        return -1;
    }
}

int main()
{
    pCQueue trainLine = createQueue(10);

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
    enqueue(trainLine, 1);
    enqueue(trainLine, 1);
    enqueue(trainLine, 1);
    enqueue(trainLine, 1);
    enqueue(trainLine, 1);
    enqueue(trainLine, 1);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    dequeue(trainLine);
    enqueue(trainLine, 1);
    enqueue(trainLine, 22);
    enqueue(trainLine, 3);

    printf("%d\n", (trainLine->arr)[11]);
    printf("%d\n", valAtLast(trainLine));
    printf("%d\n", valAtFirst(trainLine));

    printf("Element: %d\n", qCPeek(trainLine, 3));

    printQueue(trainLine);
    clearQueue(trainLine);
    printQueue(trainLine);

    return 0;
}