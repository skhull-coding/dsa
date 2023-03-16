#include <stdio.h>
#include <stdlib.h>

// Double Ended Queue - DE-queue
// DE-queue does not follow FIFO discipline
// two type of DE queue - resticted input and output DEqueue
// RID - insertion from front is not allowed
// ROD - deletion from rear is not allowed

// DEqueue ADT
// data - same as queue
// operations - isempty, isfull, enqueuef, enqueuer, dequeuef, dequeuer, and all the same as queue

// with array
typedef struct QUEUE // DEqueue
{
    int size;
    int front, rear;
    int *arr;
} Queue;
typedef Queue *pQueue;

pQueue createQueue(int size)
{
    pQueue newQ = (pQueue)malloc(sizeof(Queue));
    newQ->size = size;
    newQ->front = newQ->rear = -1;
    newQ->arr = (int *)malloc(newQ->size * sizeof(int));
    return newQ;
}

int isFull(pQueue q)
{
    return ((q->front == -1) && (q->rear == q->size - 1));
}

int isEmpty(pQueue q)
{
    return q->front == q->rear;
}

int spaceFront(pQueue q)
{
    return q->front != -1;
}

int spaceRear(pQueue q)
{
    return q->rear != q->size - 1;
}

void printQueue(pQueue q)
{
    if (!isEmpty(q))
    {
        for (int i = q->front + 1; i < q->rear + 1; i++)
        {
            printf("%d ", (q->arr)[i]);
        }
    }
    else
    {
        printf("No element to print in Queue");
    }
    printf("\n");
}

void enqueue(pQueue q, int data)
{
    if (spaceRear(q))
    {
        q->rear += 1;
        (q->arr)[q->rear] = data;
    }
    else
    {
        printf("No space is back!!\n");
    }
}

void enqueue_F(pQueue q, int data)
{
    if (spaceFront(q))
    {
        (q->arr)[q->front] = data;
        q->front -= 1;
    }
    else
    {
        printf("No space in front!!\n");
    }
}

int dequeue(pQueue q)
{
    if (!isEmpty(q))
    {
        int val = (q->arr)[q->front];
        q->front += 1;
        return val;
    }
    else
    {
        printf("Dequeing isn't possible in empty queue!!\n");
    }
    return -1;
}

int dequeue_B(pQueue q)
{
    if (!isEmpty(q))
    {
        int val = (q->arr)[q->rear];
        q->rear -= 1;
        return val;
    }
    else
    {
        printf("Dequeing isn't possible in empty queue!!\n");
    }
    return -1;
}

int lastVal(pQueue q)
{
    if (!isEmpty(q))
    {
        return (q->arr)[q->rear];
    }
    return -1;
}

int firstVal(pQueue q)
{
    if (!isEmpty(q))
    {
        return (q->arr)[q->front + 1];
    }
    return -1;
}

int peek(pQueue q, int pos)
{
    if (!isEmpty(q))
    {
        int index = pos + q->front;
        if (index > 0 && index <= q->rear)
        {
            return (q->arr)[index];
        }
    }
    return -1;
}

int main()
{
    pQueue trains = createQueue(5);

    enqueue(trains, 1);
    enqueue(trains, 2);
    enqueue(trains, 3);
    enqueue(trains, 4);
    enqueue(trains, 5);
    dequeue(trains);

    enqueue_F(trains, 6);
    dequeue_B(trains);

    printf("First value : %d\n", firstVal(trains));
    printf("Last value : %d\n", lastVal(trains));
    printf("Item at 1 : %d\n", peek(trains, 5));

    printQueue(trains);

    return 0;
}