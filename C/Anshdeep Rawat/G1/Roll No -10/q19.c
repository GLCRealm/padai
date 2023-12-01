#include <stdio.h>
#include <stdlib.h>

struct queue {
    int *arr;
    int capacity, front, rear,size;
};

struct queue* initialisequeue(int cap) {
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->capacity=cap;

    temp->front = -1;
    temp->rear = -1;
    temp -> size = 0; 
    temp->arr = (int *)malloc(sizeof(int) * cap);
    return temp;
}

void enque(struct queue* q1, int value){
    if(q1->size == q1->capacity){
        printf("Queue is full\n");
        return ;
    }
    q1->rear = (q1->rear + 1)% q1->capacity;
    q1->arr[q1->rear] = value;
    q1->size++;

}

int deque(struct queue*q1){
    if(q1->size ==0){
        printf("empty queue");
        return 0;

    }
    int val = (q1->front);
    q1-> front = (q1->front + 1)%q1->capacity;
    q1->size--;
    return val; 
}

void printqueue(struct queue* q1) {
    if (q1->size ==0) {
        printf("queue empty\n");
        return;
    }
    int i = q1->front;
    do {
        printf("%d ", q1->arr[i]);
        i = (i + 1) % q1->capacity; 
    } while (i != (q1->rear + 1) % q1->capacity);
    printf("\n");
}




int main(){

    struct queue* q1= initialisequeue(10);
    for (int i = 0;i <10;i++){
        enque(q1 ,i );
    }
    printqueue(q1);

    deque(q1);
    printqueue(q1);
    deque(q1);
    printqueue(q1);



}