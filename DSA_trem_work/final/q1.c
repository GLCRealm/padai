#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node structure to store product information
struct node {
    char product_id;
    char product_name[50];
    int total_sale;
    char product_grade;
    struct node* next;
};

struct queue{
    struct node *front, *rear;
    int size;
};

void initialisequeue(struct queue ** q){
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp -> front = temp-> rear = NULL;
    temp -> size = 0;
    *q = temp;
}

struct node* createnode(char id, const char* name, int sale, char grade) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->product_id = id;
    strcpy(newnode->product_name, name);
    newnode->total_sale = sale;
    newnode->product_grade = grade;
    newnode->next = NULL;
    return newnode;
}


void enqueue(struct queue* q, char id, const char* name, int sale, char grade) {
    struct node* newnode = createnode(id, name, sale, grade);
    if (q -> rear == NULL) {
        q -> front = q -> rear = newnode;
    } else {
        q -> rear->next = newnode;
        q ->rear = newnode;
    }
    q->size++;
    printf("product %c enqueued to the queue\n", id);
}


void dequeue(struct queue* q) {
    if (q->rear == NULL) {
        printf("queue is empty. Cannot dequeue.\n");
    } else {
        struct node* temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL){
            q->rear = NULL;
        }
        printf("product %c dequeued from the queue\n", temp->product_id);
        free(temp);
    }
    q->size--;
}


void insertelements(struct queue** q){
 
    int a;
    printf("enter the no. of products :");
    scanf("%d",&a);
    char id,grade;
    int sale;
    char* name;
    getchar();  

    for (int i = 0; i < a; i++) {
        printf("enter %d product id:\n", i + 1);
        scanf(" %c", &id);

        printf("enter %d product name:\n", i + 1);
        getchar();  
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';  

        printf("enter %d product sale:\n", i + 1);
        scanf("%d", &sale);

        printf("enter %d product grade:\n", i + 1);
        scanf(" %c", &grade);

        enqueue(*q, id, name, sale, grade);
    }
}

void displayQueue(struct queue* q) {
    printf("\n\n\n\n");
    if (q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        while (q->front != NULL) {
            printf("product_id: %c, product_name: %s, total_sale: %d, product_grade: %c\n",
                   q->front->product_id, q->front->product_name, q->front->total_sale, q->front->product_grade);
            q->front = q->front->next;
        }
    }
}

int main() {
    int a;
    struct queue *q;
    initialisequeue(&q);
    insertelements(&q);
    displayQueue(q);
    printf("\n dequeue:\n");
    dequeue(q);
    return 0;
}