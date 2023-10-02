#include <stdio.h>
#include <stdlib.h>

struct queue {
    int *arr;
    int capacity, front, rear, size;
};

void initializeQueue(struct queue **q, int cap) {
    (*q) = (struct queue *)malloc(sizeof(struct queue));
    (*q)->capacity = cap;
    (*q)->front = -1;
    (*q)->rear = -1;
    (*q)->size = 0;
    (*q)->arr = (int *)malloc(sizeof(int) * cap);
}

void enqueue(struct queue **q, int value) {
    if ((*q)->size == (*q)->capacity) {
        printf("Queue is full\n");
        return;
    }
    (*q)->rear = ((*q)->rear + 1) % (*q)->capacity;
    (*q)->arr[(*q)->rear] = value;
    (*q)->size++;
}

int dequeue(struct queue **q) {
    if ((*q)->size == 0) {
        printf("Empty queue\n");
        return 0;
    }
    int val = (*q)->arr[(*q)->front];
    (*q)->front = ((*q)->front + 1) % (*q)->capacity;
    (*q)->size--;
    return val;
}

void printQueue(struct queue **q) {
    if ((*q)->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    int i = (*q)->front;
    do {
        printf("%d ", (*q)->arr[i]);
        i = (i + 1) % (*q)->capacity;
    } while (i != ((*q)->rear + 1) % (*q)->capacity);
    printf("\n");
}

void freeQueue(struct queue **q) {
    free((*q)->arr);
    free(*q);
}

int main() {
    struct queue *q1 = NULL;
    initializeQueue(&q1, 10);

    for (int i = 0; i < 10; i++) {
        enqueue(&q1, i);
    }

    printQueue(&q1);

    dequeue(&q1);
    printQueue(&q1);

    dequeue(&q1);
    printQueue(&q1);

    freeQueue(&q1);

    return 0;
}
