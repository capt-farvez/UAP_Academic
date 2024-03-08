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
    int input, sum = 0;
    printf("Enter N: ");
    scanf("%d", &input);

    Queue q;
    queue_new(&q, input);

    int prevPrev = 0, prev = 1;

    if(input >= 1) {
            enqueue(&q, prevPrev);
    }
    if(input >= 2) {
            enqueue(&q, prev);
    }

    for(int i = 3; i <= input; i++) {
        int next = prev + prevPrev;
        prevPrev = prev;
        prev = next;
        enqueue(&q, next);
    }

    traverse_queue(&q);

    while (!is_empty(&q))
    {
        sum += dequeue(&q);
    }
    
    printf("The sum: %d\n", sum);
    
    return 0;
}