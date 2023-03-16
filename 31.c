#include <stdio.h>
#include <stdlib.h>

// DEqueue using linked lists

typedef struct NODE
{
    int data;
    struct NODE *next;
} Node;
typedef Node *pNode;

typedef struct QUEUE
{
    pNode front, rear;
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
    pQueue queue = (pQueue)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(pQueue q)
{
    return (q->front == q->rear) && (q->front == NULL);
}

int isFull(pQueue q)
{
    pNode temp = createNode(0);
    if (temp == NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
}

void printQueue(pQueue q)
{
    if (!isEmpty(q))
    {
        pNode ptr = q->front;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    else
    {
        printf("No element to print\n");
    }
}

void enqueue(pQueue q, int data)
{
    if (!isFull(q))
    {
        pNode node = createNode(data);
        if (isEmpty(q))
        {
            q->front = q->rear = node;
        }
        else
        {
            q->rear->next = node;
            q->rear = node;
        }
    }
    else
    {
        printf("No enqueue operation will be allowed!!\n");
    }
}

void enqueue_F(pQueue q, int data)
{
    if (!isFull(q))
    {
        pNode node = createNode(data);
        if (isEmpty(q))
        {
            q->front = q->rear = node;
        }
        else
        {
            node->next = q->front;
            q->front = node;
        }
    }
    else
    {
        printf("No enqueue operation will be allowed!!\n");
    }
}

int dequeue(pQueue q)
{
    if (!isEmpty(q))
    {

        pNode temp = q->front;
        int data = temp->data;
        q->front = temp->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
    else
    {
        printf("No dequeue operation will be allowed!!\n");
    }
}

int dequeue_B(pQueue q)
{
    if (!isEmpty(q))
    {
        if (q->rear == q->front)
        {
            int data = q->rear->data;
            free(q->rear);
            q->rear = q->front = NULL;
            return data;
        }
        else
        {
            pNode temp = q->rear;
            pNode ptr = q->front;
            while (ptr->next != temp)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            q->rear = ptr;
            int data = temp->data;
            free(temp);
            return data;
        }
    }
    else
    {
        printf("No dequeue operation will be allowed!!\n");
    }
}

int firstVal(pQueue q)
{
    if (!isEmpty(q))
    {
        return q->front->data;
    }
    return -1;
}

int lastVal(pQueue q)
{
    if (!isEmpty(q))
    {
        return q->rear->data;
    }
    return -1;
}

int peek(pQueue q, int pos)
{
    if (!isEmpty(q) && pos > 0)
    {
        pNode ptr = q->front;
        int i = 1;
        while (i != pos && ptr != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        if (i == pos && ptr != NULL)
        {
            return ptr->data;
        }
    }
    return -1;
}

int main()
{
    pQueue trains = createQueue();

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
    enqueue(trains, 37);
    enqueue(trains, 36);
    enqueue(trains, 35);
    enqueue(trains, 32);
    dequeue(trains);

    printf("First value : %d\n", firstVal(trains));
    printf("Last value : %d\n", lastVal(trains));
    printf("Item at 1 : %d\n", peek(trains, 1));

    printQueue(trains);

    return 0;
}