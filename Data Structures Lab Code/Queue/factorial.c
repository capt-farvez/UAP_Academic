#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

void queue_new(Queue *q, int cap)
{
    q->array = malloc(cap * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->capacity = cap - 1;
}

bool is_empty(Queue *q)
{
    if (q->front > q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_full(Queue *q)
{
    if (q->rear == q->capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue *q, int item)
{
    if (is_full(q))
        return;
    q->rear++;
    q->array[q->rear] = item;
}

int peek(Queue *q)
{
    if (is_empty(q))
        return -1;
    return q->array[q->front];
}

int dequeue(Queue *q)
{
    if (is_empty(q))
        return -1;
    int item = q->array[q->front];
    q->front++;
    return item;
}

void traverse_queue(Queue *q)
{
    printf("\nCurrent state of the queue: \n");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main()
{
    int input, fact = 1;
    printf("Enter N: ");
    scanf("%d", &input);

    Queue q;
    queue_new(&q, input);

    for(int i = 1; i <= input; i++) {
        enqueue(&q, i);
    }

    traverse_queue(&q);

    while (!is_empty(&q))
    {
        fact *= dequeue(&q);
    }
    
    printf("The factorial: %d\n", fact);
    
    return 0;
}