#include <stdio.h>
#include <stdlib.h>

// DEqueue using circular arrays

typedef struct QUEUE
{
    int size, front, rear;
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

int isEmpty(pQueue q)
{
    return ((q->front == q->rear) && (q->front == -1));
}

int isFull(pQueue q)
{
    return ((q->front == q->rear) && (q->front != -1) || (q->rear == q->size - 1) && (q->front == -1));
}

void printQueue(pQueue q)
{
    if (!isEmpty(q))
    {
        int i = q->front + 1;
        do
        {
            printf("%d ", (q->arr)[i]);
            i = (i + 1) % q->size;
        } while (i != q->rear + 1);
    }
    else
    {
        printf("No element to display in the queue!!\n");
    }
    printf("\n");
}

void enqueue(pQueue q, int data)
{
    if (!isFull(q))
    {
        q->rear = (q->rear + 1) % q->size;
        (q->arr)[q->rear] = data;
    }
    else
    {
        printf("No Enqueue operation is allowed!!\n");
    }
}

void enqueue_F(pQueue q, int data)
{
    if (!isFull(q))
    {
        if (q->front != -1)
        {
            (q->arr)[q->front] = data;
            q->front = (q->front - 1) % q->size;
            if (q->front == -1)
            {
                q->front = q->size - 1;
            }
        }
        else if (isEmpty(q))
        {
            enqueue(q, data);
        }
        else if (q->front == -1)
        {
            (q->arr)[q->size - 1] = data;
            q->front = q->size - 2;
        }
    }
    else
    {
        printf("No Enqueue operation is allwed!!\n");
    }
}

int dequeue(pQueue q)
{
    int val = -1;
    if (!isEmpty(q))
    {
        q->front = (q->front + 1) % q->size;
        val = (q->arr)[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    else
    {
        printf("No Dequeueing operation is allowed!!\n");
    }
    return val;
}

int dequeue_B(pQueue q)
{
    int val = -1;
    if (!isEmpty(q))
    {
        val = (q->arr)[q->rear];
        q->rear = (q->rear - 1) % q->size;
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else if (q->rear == -1)
        {
            q->rear = q->size - 1;
        }
    }
    else
    {
        printf("No Dequeueing operation is allowed!!\n");
    }
    return val;
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
        return (q->arr)[(q->front + 1) % q->size];
    }
    return -1;
}

int peek(pQueue queue, int pos)
{
    if (!isEmpty(queue) && (pos > 0))
    {
        return ((queue->arr)[(queue->front + pos) % queue->size]);
    }
    else
    {
        return -1;
    }
}

int main()
{
    pQueue trains = createQueue(5);

    printf("Full: %d\n", isFull(trains));
    printf("Empty: %d\n", isEmpty(trains));
    enqueue(trains, 1);
    enqueue(trains, 2);
    enqueue(trains, 3);
    enqueue(trains, 4);
    enqueue(trains, 5);
    enqueue(trains, 4);
    printf("Full: %d\n", isFull(trains));
    printf("Empty: %d\n", isEmpty(trains));

    dequeue(trains);

    enqueue_F(trains, 6);
    dequeue(trains);

    dequeue_B(trains);
    dequeue_B(trains);
    dequeue_B(trains);
    dequeue_B(trains);
    dequeue_B(trains);
    dequeue_B(trains);
    dequeue_B(trains);
    dequeue_B(trains);

    enqueue_F(trains, 99);
    enqueue_F(trains, 98);
    enqueue_F(trains, 97);
    enqueue_F(trains, 96);
    enqueue_F(trains, 95);
    enqueue_F(trains, 94);
    enqueue_F(trains, 93);
    enqueue_F(trains, 92);

    enqueue_F(trains, 99);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    dequeue(trains);
    enqueue(trains, 36);
    enqueue(trains, 36);
    enqueue(trains, 36);
    enqueue(trains, 36);

    printf("First value : %d\n", firstVal(trains));
    printf("Last value : %d\n", lastVal(trains));
    printf("Item at 1 : %d\n", peek(trains, 1));

    printQueue(trains);

    return 0;
}